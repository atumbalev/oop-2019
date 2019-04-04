#include <iostream>

struct init
{
    int a;
    int b;
} i{100, 200}, *ii;

struct testPadding
{
    int a;
    double b;
    int c;
};

// BONUS: feel free to ignore
struct __attribute__((packed)) packed
{
    int a;
    double b;
    int c;
};

// C++11?
struct nonStaticMemberInit
{
    int a = 10;
    double b = 3.22;
};

struct outer
{
    struct inner
    {
        int a = 10;
    } a;

    int b = 20;
};

struct node
{
    // node next; // ERROR: Incomplete type node
    node* next;
};

int main()
{
    // Initialization and access
    std::cout << "i already initialized with a = 100 and b = 200" << std::endl;
    std::cout << "i.a: "<< i.a << ", i.b: " << i.b << std::endl << std::endl;

    init *ii = &i;
    i.a = 300;

    std::cout << "Change i.a to 300 and access through pointer" << std::endl;
    std::cout << "ii->a: " << ii->a << std::endl << std::endl;;

    // C++11
    std::cout << "Change using initializer list" << std::endl;
    i = {500, 600};
    std::cout << "i.a: "<< i.a << ", i.b: " << i.b << std::endl << std::endl;

    // Size
    std::cout << "Regular size of testPadding (int, double, int)" << std::endl;
    std::cout << sizeof(testPadding) << std::endl << std::endl;

    std::cout << "Packed size of testPadding (int, double, int)" << std::endl;
    std::cout << sizeof(packed) << std::endl << std::endl;

    // Initializer list (C++11)
    testPadding tp = {1, 1.25, 2,};

    // Test offset (DON'T EVER DO THIS! ONLY VILAINS DO THIS!)
    void *hack = static_cast<void*>(&tp);

    // hack points at the first integer
    std::cout << "testPadding.a accessed through a pointer and some black magic" << std::endl;
    std::cout << *(static_cast<int*>(hack)) << std::endl << std::endl;
    
    // move hack to next member
    hack += 8;
    std::cout << "testPadding.b accessed through a pointer and some black magic" << std::endl;
    std::cout << *(static_cast<double*>(hack)) << std::endl << std::endl;

    // move hack to c
    hack += 8;
    std::cout << "testPadding.c accessed through a pointer and some black magic" << std::endl;
    std::cout << *(static_cast<int*>(hack)) << std::endl << std::endl;

    // Non-static member initialization (C++11)
    nonStaticMemberInit nsmi;
    std::cout << "a and b initialized in struct: " << std::endl;
    std::cout << nsmi.a << " " << nsmi.b << std::endl << std::endl;

    // Struct within a struct
    std::cout << "Struct within a struct" << std::endl;
    outer s = {{322}, 223};
    std::cout << "s.a.b: " << s.a.a << ", s.b:" << s.b << std::endl;

    return 0;
}
