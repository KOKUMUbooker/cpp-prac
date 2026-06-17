// An rvalue object is destroyed at the end of the full expression in which it is created.
// Any references to members of the rvalue object are left dangling at that point.

// A reference to a member of an rvalue object can only be safely used within the 
// full expression where the rvalue object is created.
#include <iostream>
#include <string>

class Employee
{
	std::string m_name{};

public:
	void setName(std::string_view name) { m_name = name; }
	std::string getName() const { return m_name; } //  getter returns by value
};

// createEmployee() returns an Employee by value (which means the returned value is an rvalue)
Employee createEmployee(std::string_view name)
{
	Employee e;
	e.setName(name);
	return e;
}

int main()
{
	Employee joe{};
	joe.setName("Joe");
	std::cout << joe.getName() << "\n";

	// Case 1: okay: use returned reference to member of rvalue class object in same expression
	std::cout << createEmployee("Frank").getName() << "\n";

	// Case 2: bad: save returned reference to member of rvalue class object for use later
	// const std::string& ref{ createEmployee("Garbo").getName() }; // reference becomes dangling when return value of createEmployee() is destroyed
    // std::cout << ref << "\n"; // undefined behavior

	// Case 3: okay: copy referenced value to local variable for use later
	std::string val{ createEmployee("Hans").getName() }; // makes copy of referenced member
	std::cout << val << "\n"; // okay: val is independent of referenced member

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
