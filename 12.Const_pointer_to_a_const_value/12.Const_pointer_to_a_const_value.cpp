// A const pointer to a const value can not have its address changed, 
// nor can the value it is pointing to be changed through the pointer.
// It can only be dereferenced to get the value it is pointing at.

int main()
{
    int value{ 5 };
    const int* const ptr{ &value }; // a const pointer to a const value

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
