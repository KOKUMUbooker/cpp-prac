int foo()
{
    return 5;
}

int goo()
{
    return 6;
}

int fooWithArgs(int x)
{
    return x;
}

int main()
{
    // =============== Assigning a function to a pointer
    int (*fcnPtr)() { &foo }; // fcnPtr points to function foo
    fcnPtr = &goo; // fcnPtr now points to function goo

    // =============== Calling a function via its pointer
    int (*fcnWithArgsPtr)(int) { &fooWithArgs }; // Initialize fcnWithArgsPtr with function fooWithArgs
    if (fcnWithArgsPtr) // make sure fcnPtr isn't a null pointer
        fcnWithArgsPtr(5); // otherwise this will lead to undefined behavior

    return 0;
}