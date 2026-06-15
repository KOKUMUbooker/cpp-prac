// Rvalue expressions evaluate to a value.

int return5()
{
    return 5;
}

int main()
{
    int x{ 5 }; // 5 is an rvalue expression
    const double d{ 1.2 }; // 1.2 is an rvalue expression

    int y{ x }; // x is a modifiable lvalue expression
    const double e{ d }; // d is a non-modifiable lvalue expression
    int z{ return5() }; // return5() is an rvalue expression (since the result is returned by value)

    int w{ x + 1 }; // x + 1 is an rvalue expression
    int q{ static_cast<int>(d) }; // the result of static casting d to an int is an rvalue expression

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
