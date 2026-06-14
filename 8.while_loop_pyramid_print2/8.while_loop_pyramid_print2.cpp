#include <iostream>

// Program prints this :
//         1
//       2 1
//     3 2 1
//   4 3 2 1
// 5 4 3 2 1

namespace constants 
{
    constexpr int max {5};
}

static void printStartingFrom(int iteration)
{
    int end { constants::max };

    while (end > 0)
    {
        if (end <= iteration) std::cout << end << " ";
        else std::cout << "  ";
        --end;
    }
}

int main()
{
    int iteration {1};

    while (iteration <= 5)
    {
        printStartingFrom(iteration);
        std::cout << "\n";
        ++iteration;
    }
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
