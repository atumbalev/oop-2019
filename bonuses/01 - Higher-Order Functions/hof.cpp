#include <iostream>

const int MAX_SIZE = 100;

struct IntArray
{
	int arr[MAX_SIZE];
	int size;
};

using Predicate = bool(*)(int);
using UnaryOperator = int(*)(int);

IntArray map(IntArray ls, UnaryOperator f)
{
	for (int i = 0; i < ls.size; ++i)
	{
		ls.arr[i] = f(ls.arr[i]);
	}

	return ls;
}

IntArray filter(IntArray ls, Predicate p)
{
	int newSize = 0;
	for (int i = 0; i < ls.size; ++i)
	{
		if (p(ls.arr[i]))
		{
			ls.arr[newSize++]  = ls.arr[i];
		}
	}

	ls.size = newSize;

	return ls;
}

void printIntArray(const IntArray& nums)
{
	for (int i = 0; i < nums.size; ++i)
	{
		std::cout << nums.arr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	IntArray nums{{1,2,3,4,5}, 5};
	printIntArray(map(nums, [](int num){ return num * 2;}));
	printIntArray(filter(nums, [](int num){ return num % 2 == 1;}));

	return 0;
}
