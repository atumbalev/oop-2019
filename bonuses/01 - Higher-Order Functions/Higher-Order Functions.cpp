#include <iostream>

/*
Syntax:

<return_type>(*)(<arg_type1>m <arg_type2>, ...)
*/

/*
Function that takes a double and returns a double
e.g. double doubleThat(double that) { return 2 * that; }
*/
using Function = double(*)(double);

/*
Function that takes an int and returns an int
e.g. int plusOne(int x) { return x + 1; }
*/
using NextFunction = int(*)(int);

/*
Function that takes 2 doubles and returns a double
e.g. double add(double a, double b) { return a + b; }
*/
using BinOperation = double(*)(double, double);

// Iterative function that sums the numbers between a and b
int sumIter(int a, int b)
{
	int result = 0;
	for (int i = a; i <= b; i++)
	{
		result += i;
	}

	return result;
}

// Recursive version of the above
int sumRec(int a, int b)
{
	if (a > b)
		return 0;

	return a + sumRec(a + 1, b);
}

// Product of numbers between a and b
int multIter(int a, int b)
{
	int result = 1;
	for (int i = a; i <= b; i++)
	{
		result *= i;
	}

	return result;
}

// Recursive version
int multRec(int a, int b)
{
	if (a > b)
		return 1;

	return a * multRec(a + 1, b);
}

// Too much code repetition
// sumIter and multIter are pretty much the same thing, how can we reuse the code?
// def: higher-order function -> takes functions as parameters

double add(double x, double y) { return x + y; }
int addOne(int x) { return x + 1; }
double mult(double x, double y) { return x * y; }
double id(double x) { return x; }
double square(double x) { return x * x; }
int addTwo(int x) { return x + 2; }

// accumulate
// applies a binary operation on numbers between a and b
// nextf is used to find the next number (it doesn't have to be a+1)
// base is the initial result
// f can mutate the numbers before applying the binary operation
int accumulate(int a, int b, BinOperation op,
	Function f, NextFunction nextf, int base)
{
	if (a > b)
		return base;

	return op(f(a), accumulate(nextf(a), b, op, f, nextf, base));
}

// demonstrating the use of accumulate

// same as sumRec
int sumAcc(int a, int b)
{
	return accumulate(a, b, add, id, addOne, 0);
}

// Same as multRec, notice how we are reusing code now
int multAcc(int a, int b)
{
	return accumulate(a, b, mult, id, addOne, 1);
}

// Variations

// Add a function that mutates the numbers before adding them
int sumSquares(int a, int b)
{
	return accumulate(a, b, add, square, addOne, 0);
}

// Add a function that changes the way we pick the next number
int sumSquaresSkip(int a, int b)
{
	return accumulate(a, b, add, square, addTwo, 0);
}

// Test
void testAccumulate()
{
	std::cout << sumAcc(1, 10) << std::endl;
	std::cout << sumSquares(1, 3) << std::endl;
	std::cout << sumSquaresSkip(1, 3) << std::endl;
	std::cout << multAcc(1, 5) << std::endl;
}

// derivative of a function
// demonstrating a higher-order function which returns another function
// Calculus monkaS
Function function = nullptr;
double const EPS = 0.0001;

double derivative(double x)
{
	return (function(x + EPS) - function(x)) / EPS;
}

Function derive(Function f)
{
	function = f;
	return derivative;
}

void testDerivative()
{
	std::cout << derive(square)(5) << std::endl; // f(x) = x^2 ; f'(x) = 2x ; f'(5) = 10
}

int main()
{
	testAccumulate();
	testDerivative();

	return 0;
}
