#include <array>
#include <cstdint>
#include <cstdio>
#include <limits>
#include <optional>
#include <type_traits>

struct BeginUpdate
{
    std::uint32_t image_size;
    std::uint32_t image_version;
};

struct WriteBlock
{
    std::uint32_t offset;
    std::uint16_t length;
    std::array<std::uint8_t, 256> bytes;
};

struct FinishUpdate
{
};

constexpr bool valid(const BeginUpdate &request) noexcept
{
    return request.image_size != 0U;
}

constexpr bool valid(const WriteBlock &request) noexcept
{
    return request.length != 0U && request.length <= request.bytes.size() &&
           request.offset <= std::numeric_limits<std::uint32_t>::max() - request.length;
}

class UpdateRequest
{
  public:
    [[nodiscard]]
    static std::optional<UpdateRequest> begin(BeginUpdate request) noexcept
    {
        if (!valid(request))
        {
            return std::nullopt;
        }

        return UpdateRequest{ request };
    }

    [[nodiscard]]
    static std::optional<UpdateRequest> block(const WriteBlock &request) noexcept
    {
        if (!valid(request))
        {
            return std::nullopt;
        }

        return UpdateRequest{ request };
    }

    [[nodiscard]]
    static UpdateRequest finish() noexcept
    {
        return UpdateRequest{ FinishUpdate{} };
    }

    template <class Handler> void dispatch(const Handler &handler) const
    {
        switch (kind_)
        {
        case Kind::begin:
            handler(payload_.begin);
            break;

        case Kind::block:
            handler(payload_.block);
            break;

        case Kind::finish:
            handler(payload_.finish);
            break;
        }
    }

  private:
    enum class Kind : std::uint8_t
    {
        begin,
        block,
        finish
    };

    union Payload
    {
        BeginUpdate begin;
        WriteBlock block;
        FinishUpdate finish;

        explicit Payload(BeginUpdate value) noexcept : begin{ value }
        {
        }

        explicit Payload(const WriteBlock &value) noexcept : block{ value }
        {
        }

        explicit Payload(FinishUpdate value) noexcept : finish{ value }
        {
        }
    };

    explicit UpdateRequest(BeginUpdate value) noexcept : payload_{ value }, kind_{ Kind::begin }
    {
    }

    explicit UpdateRequest(const WriteBlock &value) noexcept : payload_{ value }, kind_{ Kind::block }
    {
    }

    explicit UpdateRequest(FinishUpdate value) noexcept : payload_{ value }, kind_{ Kind::finish }
    {
    }

    Payload payload_;
    Kind kind_;
};

// The implementation relies on trivially copyable payloads.
static_assert(std::is_trivially_copyable_v<UpdateRequest>);

// Demonstration handler: reports requests without programming flash.
struct RequestTrace
{
    void operator()(const BeginUpdate &request) const noexcept
    {
        std::printf("Begin request: size=%lu version=%lu\n", static_cast<unsigned long>(request.image_size),
                    static_cast<unsigned long>(request.image_version));
    }

    void operator()(const WriteBlock &request) const noexcept
    {
        std::printf("Write request: offset=%lu length=%u\n", static_cast<unsigned long>(request.offset),
                    static_cast<unsigned>(request.length));
    }

    void operator()(const FinishUpdate &) const noexcept
    {
        std::puts("Finish request");
    }
};

int main()
{
    const RequestTrace trace;

    auto request = UpdateRequest::begin(BeginUpdate{ 4U, 7U });

    if (!request)
    {
        std::fputs("Invalid begin request\n", stderr);
        return 1;
    }

    request->dispatch(trace);

    const WriteBlock block{ 0U, 4U, { 0x10U, 0x20U, 0x30U, 0x40U } };

    request = UpdateRequest::block(block);

    if (!request)
    {
        std::fputs("Invalid block request\n", stderr);
        return 1;
    }

    request->dispatch(trace);

    request = UpdateRequest::finish();
    request->dispatch(trace);

    std::printf("Union request size: %zu bytes\n", sizeof(UpdateRequest));

    return 0;
}