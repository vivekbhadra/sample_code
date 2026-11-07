#include <array>
#include <cstdint>
#include <cstdio>
#include <limits>
#include <optional>
#include <type_traits>
#include <variant>

// Decoded application requests, not communication wire layouts.

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

// Union implementation: the class maintains the active-member tag.

class UnionUpdateRequest
{
  public:
    [[nodiscard]]
    static std::optional<UnionUpdateRequest> begin(BeginUpdate request) noexcept
    {
        if (!valid(request))
        {
            return std::nullopt;
        }

        return UnionUpdateRequest{ request };
    }

    [[nodiscard]]
    static std::optional<UnionUpdateRequest> block(const WriteBlock &request) noexcept
    {
        if (!valid(request))
        {
            return std::nullopt;
        }

        return UnionUpdateRequest{ request };
    }

    [[nodiscard]]
    static UnionUpdateRequest finish() noexcept
    {
        return UnionUpdateRequest{ FinishUpdate{} };
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

    explicit UnionUpdateRequest(BeginUpdate value) noexcept : payload_{ value }, kind_{ Kind::begin }
    {
    }

    explicit UnionUpdateRequest(const WriteBlock &value) noexcept : payload_{ value }, kind_{ Kind::block }
    {
    }

    explicit UnionUpdateRequest(FinishUpdate value) noexcept : payload_{ value }, kind_{ Kind::finish }
    {
    }

    Payload payload_;
    Kind kind_;
};

// This implementation relies on trivially copyable payloads.
static_assert(std::is_trivially_copyable_v<UnionUpdateRequest>);

// Variant implementation: the library maintains the active type.

class VariantUpdateRequest
{
  public:
    [[nodiscard]]
    static std::optional<VariantUpdateRequest> begin(BeginUpdate request) noexcept
    {
        if (!valid(request))
        {
            return std::nullopt;
        }

        return VariantUpdateRequest{ request };
    }

    [[nodiscard]]
    static std::optional<VariantUpdateRequest> block(const WriteBlock &request) noexcept
    {
        if (!valid(request))
        {
            return std::nullopt;
        }

        return VariantUpdateRequest{ request };
    }

    [[nodiscard]]
    static VariantUpdateRequest finish() noexcept
    {
        return VariantUpdateRequest{ FinishUpdate{} };
    }

    template <class Handler> void dispatch(const Handler &handler) const
    {
        std::visit(handler, payload_);
    }

  private:
    using Payload = std::variant<BeginUpdate, WriteBlock, FinishUpdate>;

    explicit VariantUpdateRequest(BeginUpdate value) noexcept : payload_{ value }
    {
    }

    explicit VariantUpdateRequest(const WriteBlock &value) noexcept : payload_{ value }
    {
    }

    explicit VariantUpdateRequest(FinishUpdate value) noexcept : payload_{ value }
    {
    }

    Payload payload_;
};

// Desktop demonstration handler.
// It reports requests; it does not program or verify firmware.

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

// Exercise both implementations through their identical public APIs.

template <class Request> bool demonstrate(const char *name)
{
    std::printf("%s\n", name);

    const RequestTrace trace;

    auto request = Request::begin(BeginUpdate{ 4U, 7U });

    if (!request)
    {
        return false;
    }

    request->dispatch(trace);

    const WriteBlock block{ 0U, 4U, { 0x10U, 0x20U, 0x30U, 0x40U } };

    request = Request::block(block);

    if (!request)
    {
        return false;
    }

    request->dispatch(trace);

    request = Request::finish();
    request->dispatch(trace);

    std::printf("Request size: %zu bytes\n\n", sizeof(Request));

    return true;
}

int main()
{
    if (!demonstrate<UnionUpdateRequest>("Union implementation") ||
        !demonstrate<VariantUpdateRequest>("std::variant implementation"))
    {
        std::fputs("Request validation failed\n", stderr);
        return 1;
    }

    return 0;
}