// The length of a vector is how many elements are “in use”.
// The capacity of a vector is how many elements have been allocated in memory.

// Vector indexing is based on length, not capacity
#include <iostream>
#include <vector>

void printCapLen(const std::vector<int>& v)
{
	std::cout << "Capacity: " << v.capacity() << " Length:" << v.size() << '\n';
}

int main()
{

	std::vector<int> v(100); // allocate room for 100 elements
	printCapLen(v);

	v.resize(102); // resize to 102 elements
	printCapLen(v);

	v.resize(0); // resize to 0 elements
	printCapLen(v);

	v.shrink_to_fit();
	printCapLen(v);

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
