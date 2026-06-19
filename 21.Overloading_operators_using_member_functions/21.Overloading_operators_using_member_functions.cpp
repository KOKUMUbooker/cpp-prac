//If you’re overloading assignment(= ), subscript([]), function call(()), or member selection(->), do so as a member function.
//If you’re overloading a unary operator, do so as a member function.
//If you’re overloading a binary operator that does not modify its left operand(e.g. operator+),
// do so as a normal function(preferred) or friend function.
//If you’re overloading a binary operator that modifies its left operand, but you can’t 
// add members to the class definition of the left operand(e.g. operator<<, which has a left operand of type ostream), do so as a normal function(preferred) or friend function.
//If you’re overloading a binary operator that modifies its left operand(e.g. operator+=), 
// and you can modify the definition of the left operand, do so as a member function.

#include <iostream>

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents)
        : m_cents{ cents } {
    }

    // Overload Cents + int
    Cents operator+(int value) const;

    int getCents() const { return m_cents; }
};

// note: this function is a member function!
// the cents parameter in the friend version is now the implicit *this parameter
Cents Cents::operator+ (int value) const
{
    return Cents{ m_cents + value };
}

int main()
{
    const Cents cents1{ 6 };
    const Cents cents2{ cents1 + 2 };
    std::cout << "I have " << cents2.getCents() << " cents.\n";

    return 0;
}

// ========================= Same overloading if it were done using friend function
//#include <iostream>
//
//class Cents
//{
//private:
//    int m_cents{};
//
//public:
//    Cents(int cents)
//        : m_cents{ cents } {
//    }
//
//    // Overload Cents + int
//    friend Cents operator+(const Cents& cents, int value);
//
//    int getCents() const { return m_cents; }
//};
//
//// note: this function is not a member function!
//Cents operator+(const Cents& cents, int value)
//{
//    return Cents(cents.m_cents + value);
//}
//
//int main()
//{
//    const Cents cents1{ 6 };
//    const Cents cents2{ cents1 + 2 };
//    std::cout << "I have " << cents2.getCents() << " cents.\n";
//
//    return 0;
//}