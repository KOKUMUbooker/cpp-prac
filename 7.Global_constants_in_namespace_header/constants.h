#ifndef CONSTANTS_H
#define CONSTANTS_H

// Define your own namespace to hold constants
namespace constants
{
    // Global constants have internal linkage by default
    constexpr double pi{ 3.14159 };
    constexpr double avogadro{ 6.0221413e23 };
    constexpr double myGravity{ 9.2 }; // m/s^2 -- gravity is light on this planet
    // ... other related constants
}
#endif