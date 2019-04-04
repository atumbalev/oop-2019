#include <iostream>
#include <cassert>
#include <cstring>

class SwapTest
{
 public:
    explicit SwapTest(const char* _name)
    {
        std::cout << "Constructor" << std::endl;
        assert(_name);
        std::cout << "Allocation" << std::endl;
        name = new char[strlen(_name) + 1];
        strncpy(name, _name, strlen(_name) + 1);
    }

    SwapTest(const SwapTest& other)
    {
        std::cout << "Copy Constructor" << std::endl;
        std::cout << "Allocation" << std::endl;
        name = new char[strlen(other.name) + 1];
        strncpy(name, other.name, strlen(other.name) + 1);
    }

    SwapTest& operator=(const SwapTest& other)
    {
        std::cout << "Operator=" << std::endl;
        if (this != &other)
        {
            std::cout << "Deallocation" << std::endl;
            delete [] name;
            std::cout << "Allocation" << std::endl;
            name = new char[strlen(other.name) + 1];
            strncpy(name, other.name, strlen(other.name) + 1);
        }

        return *this;
    }

    ~SwapTest()
    {
        std::cout << "Deallocation" << std::endl;
        delete [] name;
    }

    friend void swap(SwapTest& lhs, SwapTest& rhs)
    {
        using std::swap;
        swap(lhs.name, rhs.name);
    }

    void print() const
    {
        std::cout << name << std::endl;
    }
 private:
    char * name;
};

int main()
{
    SwapTest x("Jebaited"), y("DansGame");
    x.print();
    y.print();

    std::cout << "-------------REGULAR SWAP----------" << std::endl;
    std::swap(x, y);
    x.print();
    y.print();
    // 3 Allocations and 3 Deallocations. YIKES!

    std::cout << "-------------OUR SWAP--------------" << std::endl;
    swap(x, y);
    x.print();
    y.print();
    // 0 memory operations. FeelsGoodMan

    std::cout << "-----------------------------------" << std::endl;

    // There is another efficient way of swapping variables, we might look into it later
    return 0;
}
