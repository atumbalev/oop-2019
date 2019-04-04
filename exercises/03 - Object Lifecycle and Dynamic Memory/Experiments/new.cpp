#include <iostream>

int main()
{
	// Allocate 40 bytes for 10 ints
	int *a = new int[10]{1,2,3,4};
	// Use them like a normal array
	for (int i = 0 ; i < 4; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	// When new fails it throws std::bad_alloc and return nullptr
	int *b = new (std::nothrow) /*so the program doesn't terminate*/ int[10000000000];
	std::cout << b << std::endl; // Failed to allocate memory => b is nullptr

	// Terminate called after bad_alloc
	int *c = new int[10000000000];
	
	// This doesn't get called because the program terminated
	delete a;

	return 0;
}