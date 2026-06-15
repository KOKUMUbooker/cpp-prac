#include <string>

constexpr std::string_view hello{ "Hello" };   // implicitly const

constexpr const std::string_view& getConstRef() // function is constexpr, returns a const std::string_view&
{
    return hello;
}

int main()
{
    // ================= Type deductions with const =================================
    const double a{ 7.8 }; // a has type const double
    auto b{ a };           // b has type double (const dropped)

    constexpr double c{ 7.8 }; // c has type const double (constexpr implicitly applies const)
    auto d{ c };               // d has type double (const dropped)

    { // Implicit block to separate new examples with similar names
        double a{ 7.8 };    // a has type double
        const auto b{ a };  // b has type const double (const applied)

        constexpr double c{ 7.8 }; // c has type const double (constexpr implicitly applies const)
        const auto d{ c };         // d is const double (const dropped, const reapplied)
        constexpr auto e{ c };     // e is constexpr double (const dropped, constexpr reapplied)
    }

    // ================= Type deductions with references =================================
        auto ref1{ getConstRef() };                  // std::string_view (reference dropped and top-level const dropped)
    constexpr auto ref2{ getConstRef() };        // constexpr const std::string_view (reference dropped and top-level const dropped, constexpr applied, implicitly const)

    auto& ref3{ getConstRef() };                 // const std::string_view& (reference reapplied, low-level const not dropped)
    constexpr const auto& ref4{ getConstRef() }; // constexpr const std::string_view& (reference reapplied, low-level const not dropped, constexpr applied)

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
