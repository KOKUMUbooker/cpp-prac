#include <iostream>
#include <vector>

int main()
{
    std::vector fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    // ================= Traditional for loop
    std::cout << "Traditional for loop : " << "\n";
    std::size_t length{ fibonacci.size() };
    for (std::size_t index{ 0 }; index < length; ++index)
        std::cout << fibonacci[index] << ' ';

    std::cout << '\n';

    // ================= Range based for loop
    std::cout << "\nRange based for loop : " << "\n";
    for (int num : fibonacci) // iterate over array fibonacci and copy each value into `num`
        std::cout << num << ' '; // print the current value of `num`

    std::cout << '\n';

    // ================ Type deduction in range based loops using auto
    for (auto num : fibonacci) // compiler will deduce type of num to be `int`
        std::cout << num << ' ';

    std::cout << '\n';

    // =========== Example 2 - that avoids inexpensive copies
    std::vector<std::string> words{ "peter", "likes", "frozen", "yogurt" };

    for (const auto& word : words) // word is now a const reference
        std::cout << word << ' ';

    std::cout << '\n';

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
