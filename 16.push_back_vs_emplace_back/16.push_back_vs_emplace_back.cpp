// push_back() and emplace_back() will increment the length of a std::vector,
// and will cause a reallocation to occur if the capacity is not sufficient 
// to insert the value.push_back() and emplace_back() will increment the length of a std::vector, 
// and will cause a reallocation to occur if the capacity is not sufficient to insert the value.

// Both push_back() and emplace_back() push an element onto the stack.
// If the object to be pushed already exists, 
// push_back() and emplace_back() are equivalent, and push_back() should be preferred.

// Prefer emplace_back() when creating a new temporary object to add to the container, 
// or when you need to access an explicit constructor.

// Prefer push_back() otherwise.

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Foo
{
private:
	std::string m_a{};
	int m_b{};

public:
	Foo(std::string_view a, int b)
		: m_a{ a }, m_b{ b }
	{
	}

	explicit Foo(int b)
		: m_a{}, m_b{ b }
	{
	};
};

int main()
{
	std::vector<Foo> stack{};

	// When we already have an object, push_back and emplace_back are similar in efficiency
	Foo f{ "a", 2 };
	stack.push_back(f);    // prefer this one
	stack.emplace_back(f);

	// When we need to create a temporary object to push, emplace_back is more efficient
	stack.push_back({ "a", 2 }); // creates a temporary object, and then copies it into the vector
	stack.emplace_back("a", 2);  // forwards the arguments so the object can be created directly in the vector (no copy made)

	// push_back won't use explicit constructors, emplace_back will
	// stack.push_back({ 2 }); // compile error: Foo(int) is explicit
	stack.emplace_back(2);  // ok

	return 0;
}
