#include <iostream>
#include <cstring>

// Testing access specfiers and const qualifers
class test
{
private:
    int a = 10;
public:
    int getA() const
    {
        return a;
    }

    int getOtherObjectsA(const test& other) const
    {
        return other.a;
    }

    void constPrint() const
    {
        std::cout << a << std::endl;
    }

    void nonConstPrint()
    {
        std::cout << a << std::endl;
    }
};

// Test return types of selectors
class test2
{
private:
    char a[20] = "Kappa";
    int b = 10;
    char *c;
public:
    test2()
    {
        c = new char[20];
        strcpy(c, "Kappa");
    }
    void print() const
    {
        std::cout << a << " " << b << std::endl;
    }

    const char* correctGet() const
    {
        return a;
    }

    char* wrongGet1()
    /*
        Right now it's even more obvious because the compiler prevents us from adding const to the end,
        but there are similar situations where the const can be added (will examine in later lectures)
    */
    {
        return a;
    }

    int& wrongGet2()
    {
        return b;
    }
};

class PublicIntArray
{
public:
    int arr[10];
    int size;

    void print() const
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i] << " "; 
        }

        std::cout << std::endl;
    }
};

class TestCascade
// Or when is it a good idea to return a reference
{
public:
    TestCascade& add(int x)
    {
        a+=x;
        return *this;
    }

    int get() const
    {
        return a;
    }
private:
    int a = 0;
};

int main(int argc, char const *argv[])
{
    // Test access specifiers
    test t1, t2;
    // std::cout << t1.a << std::endl; // ERROR: int test::a is private within this context
    std::cout << t1.getA() << std::endl; // SUCCESS

    std::cout << t1.getOtherObjectsA(t2) << std::endl; // SUCCESS: Access modifiers work on class level, not object level

    // Test const qualifer
    const test t3;
    t3.constPrint(); // SUCCESS
    // t3.nonConstPrint(); // ERROR: Passing 'const test' as 'this' argument discard qualifiers, nonConstPrint() doesn't change anything but the compiler doesn't know that

    // Test return values of selectors
    test2 x;
    std::cout << std::endl;

    // All 3 selectors work
    std::cout << x.correctGet() << std::endl;
    std::cout << x.wrongGet1() << std::endl;
    std::cout << x.wrongGet2() << std::endl;

    // But the latter 2 break the encapsulation
    // x.correctGet()[0] = 'Q'; // ERROR: assignment of read-only location
    strcpy(x.wrongGet1(), "monkaS");
    x.wrongGet2() = 322;
    x.print();

    // Test cascading method
    std::cout << std::endl;
    TestCascade tc;
    std::cout << tc.add(10).add(20).add(-15).get() << std::endl;

        // Why do we bother with encapsulation?
    std::cout << std::endl;
    PublicIntArray p{{1,2,3}, 3};
    p.print();
    // But size is not public, so we can freely change it
    p.size = 1000000; // Oh, bother
    // p.print(); // 1 2 3 + a  bunch of random numbers followed by Segmentation Fault

    return 0;
}