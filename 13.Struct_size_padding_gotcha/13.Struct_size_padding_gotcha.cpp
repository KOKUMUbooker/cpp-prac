// The size of a struct will be at least as large as the size of all the variables it contains. 
// But it could be larger! For performance reasons, the compiler will sometimes add gaps into
// structures (this is called padding).
#include <iostream>

// Foo1 is 50% larger due to the added padding.
struct Foo1
{
    short a{}; // will have 2 bytes of padding after a
    int b{};
    short c{}; // will have 2 bytes of padding after c
};

// You can minimize padding by defining your members in decreasing order of size.
struct Foo2
{
    int b{};
    short a{};
    short c{};
};

int main()
{
    std::cout << sizeof(Foo1) << '\n'; // prints 12
    std::cout << sizeof(Foo2) << '\n'; // prints 8

    return 0;
}
