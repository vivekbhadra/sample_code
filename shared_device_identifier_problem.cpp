#include <iostream>
#include <string>
#include <vector>

std::string find_shared_identifier(const std::vector<std::string> &identifiers)
{
    // TODO: Find and return the characters shared at the
    // beginning of every identifier.

    return {};
}

int main()
{
    const std::vector<std::string> identifiers{ "sensor_temperature", "sensor_pressure", "sensor_status" };

    const std::string shared_identifier{ find_shared_identifier(identifiers) };

    std::cout << "Shared identifier: \"" << shared_identifier << "\"\n";

    return 0;
}
