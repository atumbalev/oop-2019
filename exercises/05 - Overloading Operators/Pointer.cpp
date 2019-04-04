#include <iostream>

struct Test
{
    int val;
};

// Absolutelely USELESS class to demonstrate usage of * and ->
class ThisIsLiterallyJustAPointerToTest
{
 public:
    explicit ThisIsLiterallyJustAPointerToTest(Test *_ptr = nullptr): ptr(_ptr) {}
    ThisIsLiterallyJustAPointerToTest& operator++()
    {
        ++ptr;
        return *this;
    }

    ThisIsLiterallyJustAPointerToTest& operator--()
    {
        --ptr;
        return *this;
    }

    ThisIsLiterallyJustAPointerToTest operator++(int)
    {
        ThisIsLiterallyJustAPointerToTest tmp = *this;
        ++ptr;
        return tmp;
    }

    ThisIsLiterallyJustAPointerToTest operator--(int)
    {
        ThisIsLiterallyJustAPointerToTest tmp = *this;
        --ptr;
        return tmp;
    }

    ThisIsLiterallyJustAPointerToTest operator+(int offset) const
    {
        return ThisIsLiterallyJustAPointerToTest(ptr + offset);
    }

    ThisIsLiterallyJustAPointerToTest operator-(int offset) const
    {
        return ThisIsLiterallyJustAPointerToTest(ptr - offset);
    }

    Test& operator[](unsigned index)
    {
        return ptr[index];
    }

    const Test& operator[](unsigned index) const
    {
        return ptr[index];
    }

    Test* operator->()
    {
        return ptr;
    }

    const Test* operator->() const
    {
        return ptr;
    }

    Test& operator*()
    {
        return *ptr;
    }

    const Test& operator*() const
    {
        return *ptr;
    }

    operator Test*() const
    {
        return ptr;
    }


 private:
    Test *ptr;
};

ThisIsLiterallyJustAPointerToTest operator+(int offset, const ThisIsLiterallyJustAPointerToTest& ptr)
{
    return ptr + offset;
}

ThisIsLiterallyJustAPointerToTest operator-(int offset, const ThisIsLiterallyJustAPointerToTest& ptr)
{
    return ptr - offset;
}

int main()
{
    Test a[3] = {{1}, {2}, {3}};
    ThisIsLiterallyJustAPointerToTest ptr(a);

    std::cout << ptr->val << std::endl;
    ptr++;
    std::cout << ptr->val << std::endl;
    ptr--;
    std::cout << ptr->val << std::endl;
    ptr = ptr + 2;
    std::cout << ptr->val << std::endl;
    std::cout << (*ptr).val << std::endl;

    ptr->val = 4;
    std::cout << a[2].val << std::endl;

    (*ptr).val = 10;
    std::cout << a[2].val << std::endl;
}
