#include<iostream>

// Examples for operator()

// Similar to void PrintHello() { std::cout << "Hello, World!" << std::endl; }
struct PrintHello
{
    void operator()() const
    {
        std::cout << "Hello, World!" << std::endl;
    }
};

// These functions can also return things
struct Return0
{
 public:
    int operator()() const
    {
        return 0;
    }
};

// They can take arguments, too
struct AddNumbers
{
    int operator()(int a, int b) const
    {
        return a + b;
    }
};

// They can have state
struct AddX
{
    int x;
    int operator()(int a) const
    {
        return a + x;
    }
};

// They can be overloaded
struct Overloaded
{
    void operator()(int a) const
    {
        std::cout << "Integer: " << a << std::endl;
    }

    void operator()(const char* a) const
    {
        if (a)
        {
            std::cout << "CString: " << a << std::endl;
        }
        else
        {
            std::cout << "nullptr" << std::endl;
        }
    }
};

int main()
{
    PrintHello{}();
    std::cout << Return0{}() << std::endl;
    std::cout << AddNumbers{}(10, 20) << std::endl;
    std::cout << AddX{21}(30) << std::endl;
    Overloaded{}(10);
    Overloaded{}("Kappa123");

    // More on how this can be useful after we learn about templates
    return 0;
}
