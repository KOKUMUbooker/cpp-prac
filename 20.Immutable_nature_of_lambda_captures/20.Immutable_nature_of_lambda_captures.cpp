// The captured variables of a lambda are copies of the outer scope variables, not the actual variables.
// Captures are treated as const by default
#include <iostream>

int main()
{
    int ammo{ 10 };

    // Define a lambda and store it in a variable called "shoot".
    auto shoot{
      [ammo]() {
            // Illegal, ammo cannot be modified.
            //  --ammo;

            std::cout << "Pew! " << ammo << " shot(s) left.\n";
          }
    };

    // Call the lambda
    shoot();

    std::cout << ammo << " shot(s) left\n";

    return 0;
}