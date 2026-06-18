#include <iostream>

int main()
{
    int* unitialized_ptr{ new int }; // Without initialization
    int* ptr{ new int { 6 } }; // use uniform initialization

    // value will be set to a null pointer if the integer allocation fails
    int* value{ new (std::nothrow) int{} }; // ask for an integer's worth of memory
    if (!value) // handle case where new returned null
    {
        // Do error handling here
        std::cerr << "Could not allocate memory\n";
    }


    // return memory back to operating system
    delete unitialized_ptr;
    delete ptr;
    delete value;

    // To avoid pointing to already freed memory(dangling pointers), reassign them to nullptr
    unitialized_ptr = nullptr;
    ptr = nullptr;
    value = nullptr;
} 
