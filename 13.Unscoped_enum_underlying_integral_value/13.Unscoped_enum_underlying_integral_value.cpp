#include <iostream>

enum Animal
{
    cat = -3,    // -3
    dog,         // -2
    pig,         // -1
    unknown,     // 0
    horse,       // 1
    giraffe = 5, // 5
    chicken,     // 6
};

int main()
{
    Animal a{}; // value-initialization zero-initializes a to value 0
    Animal c{chicken};
    std::cout << a << "\n"; // prints 0
    std::cout << c << "\n"; // prints 6

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
