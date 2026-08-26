#include <iostream>
#include <string>

void check_entry(const std::string &name, int age, bool has_ticket, bool has_special_permission)
{
    // Normal entry OR exceptional entry
    // bool entry_permitted = (age >= 18 && has_ticket) || has_special_permission;
    bool entry_permitted = age >= 18 && (has_ticket || has_special_permission);

    std::cout << name << ": " << (entry_permitted ? "Entry permitted" : "Entry denied") << '\n';
}

int main()
{
    check_entry("Alice", 20, true, false);
    check_entry("Ben", 16, false, true);
    check_entry("Clara", 20, false, false);
}