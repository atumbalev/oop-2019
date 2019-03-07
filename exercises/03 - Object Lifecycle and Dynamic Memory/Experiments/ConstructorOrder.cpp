#include <iostream>

class Test
{
private:
	int a;
public:
	Test(int _a)
	{
		a = _a;
		std::cout << "Create " << a << std::endl;
	}
	~Test()
	{
		std::cout << "Destroy " << a << std::endl;
	}
};

class Outer
{
private:
	class Inner
	{
	public:
		Inner(int _a): a(_a) { std::cout << "Create inner " << a << std::endl; }
		~Inner() { std::cout << "Destroy inner " << a << std::endl; }
	private:
		int a;
	} x, y, z;
public:
	Outer(): y(20), x(10), z(30) { std::cout << "Create outer" << std::endl; }
	~Outer() { std::cout << "Destroy outer" << std::endl; }
};

int main(int argc, char const *argv[])
{
	// Created in order of declaration (1 -> 2 -> 3)
	// Destroyed in reverse order (3 -> 2 -> 1)
	Test a(1), b(2), c(3);

	Outer o;
	// Inner classes created first in order of declaration (not init list) (10 -> 20 -> 30)
	// Then create outer
	// Destroy outer first
	// Then destroy the inner classes in reverse order (30 -> 20 -> 10)

	return 0;
}