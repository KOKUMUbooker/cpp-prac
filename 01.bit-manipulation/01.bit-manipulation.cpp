#include <bitset>
#include <iostream>

// Querying std::bitset

// test() allows us to query whether a bit is a 0 or 1.
// set() allows us to turn a bit on(this will do nothing if the bit is already on).
// reset() allows us to turn a bit off(this will do nothing if the bit is already off).
// flip() allows us to flip a bit value from a 0 to a 1 or vice versa.

// size() returns the number of bits in the bitset.
// count() returns the number of bits in the bitset that are set to true.
// all() returns a Boolean indicating whether all bits are set to true.
// any() returns a Boolean indicating whether any bits are set to true.
// none() returns a Boolean indicating whether no bits are set to true.

int main()
{
    [[maybe_unused]] constexpr int  isHungry{ 0 };
    [[maybe_unused]] constexpr int  isSad{ 1 };
    [[maybe_unused]] constexpr int  isMad{ 2 };
    [[maybe_unused]] constexpr int  isHappy{ 3 };
    [[maybe_unused]] constexpr int  isLaughing{ 4 };
    [[maybe_unused]] constexpr int  isAsleep{ 5 };
    [[maybe_unused]] constexpr int  isDead{ 6 };
    [[maybe_unused]] constexpr int  isCrying{ 7 };

    std::bitset<8> me{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    me.set(isHappy);      // set bit position 3 to 1 (now we have 0000 1101)
    me.flip(isLaughing);  // flip bit 4 (now we have 0001 1101)
    me.reset(isLaughing); // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << me << '\n';
    std::cout << "I am happy: " << me.test(isHappy) << '\n';
    std::cout << "I am laughing: " << me.test(isLaughing) << '\n';

    std::cout << me.size() << " bits are in the bitset\n";
    std::cout << me.count() << " bits are set to true\n";

    std::cout << std::boolalpha;
    std::cout << "All bits are true: " << me.all() << '\n';
    std::cout << "Some bits are true: " << me.any() << '\n';
    std::cout << "No bits are true: " << me.none() << '\n';

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
