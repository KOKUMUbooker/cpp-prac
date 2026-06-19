#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
    // =============================================== Example 1 ============================
    // Print a value and count how many times @print has been called.
    auto print{
      [](auto value) {
        static int callCount{ 0 };
        std::cout << callCount++ << ": " << value << '\n';
      }
    };

    print("hello"); // 0: hello
    print("world"); // 1: world

    print(1); // 0: 1
    print(2); // 1: 2

    print("ding dong"); // 2: ding dong

    // =============================================== Example 2 ============================
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    // Define the function right where we use it.
    auto found{ std::find_if(arr.begin(), arr.end(),
                             [](std::string_view str) // here's our lambda, no capture clause
                             {
                               return str.find("nut") != std::string_view::npos;
                             }) };

    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    return 0;
}