# Bonus 2. Finally

## Problem

* Implement a function finally that takes a procedure with 0 arguments and executes it at the end of the current scope
* Demonstrate its usage using lambdas

## Example

```c++
void test()
{
	// somehow call finally here with a function that prints bye
	std::cout << "Hi" << std::endl;
}

int main(int argc, char const *argv[])
{
	test();
	std::cout << "End of Main" << std::endl;
	return 0;
}

/* Output
	Hi
	Bye
	End of Main
*/
```

## Deadline

```
24.03.2019 23:59
```
