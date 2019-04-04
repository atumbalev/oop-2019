#include <iostream>
#include <cstring>
#include <cassert>

class Classic
{
public:
    Classic(const char* _name)
    {
        std::cout << "Constructor" << std::endl;
        assert(_name);
        std::cout << "Allocating Memory" << std::endl;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }

    Classic(const Classic& other)
    {
        std::cout << "Copy Constructor" << std::endl;
        std::cout << "Allocating Memory" << std::endl;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    ~Classic()
    {
        std::cout << "Destructor" << std::endl;
        std::cout << "Deallocating Memory" << std::endl;
        delete [] name;
    }

    Classic& operator=(const Classic& other)
    {
        std::cout << "Operator=" << std::endl;
        if (this != &other)
        {
            std::cout << "Deallocating memory" << std::endl;
            delete [] name;
            std::cout << "Allocating memory" << std::endl;
            name = new char[strlen(other.name) + 1];
            // PROBLEM: If this allocation fails now, we can't get the previous name back
            strcpy(name, other.name);
        }

        return *this;
    }
private:
    char * name;
};

class CopyAndSwap
{
public:
    CopyAndSwap(const char* _name)
    {
        std::cout << "Constructor" << std::endl;
        assert(_name);
        std::cout << "Allocating Memory" << std::endl;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }

    CopyAndSwap(const CopyAndSwap& other)
    {
        std::cout << "Copy Constructor" << std::endl;
        std::cout << "Allocating Memory" << std::endl;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    ~CopyAndSwap()
    {
        std::cout << "Destructor" << std::endl;
        std::cout << "Deallocating memory" << std::endl;
        delete [] name;
    }

    friend void swap(CopyAndSwap& lhs, CopyAndSwap& rhs)
    {
        using std::swap;
        swap(lhs.name, rhs.name);
    }

    CopyAndSwap& operator=(CopyAndSwap other) // With copy elision
    {
        std::cout << "Operator=" << std::endl;
        // If the allocation fails, the function doesn't get called and we don't lose data
        // Memory is freed by the destructor of other
        swap(*this, other);
        return *this;
    }

    /*
    CopyAndSwap& operator=(const CopyAndSwap& other) // No copy elision, not recommender because the compiler is better at making copies than us
    {
        CopyAndSwap temp(other);
        // Allocation may fail before the freeing (so no loss of data)
        swap(*this, temp);
        return *this;
        // Deallocation is handled by temp's destructor
    }
    */
private:
    char * name;
};

class BufferReusement
{
public:
    BufferReusement(const char* _name)
    {
        std::cout << "Constructor" << std::endl;
        assert(_name);
        std::cout << "Allocating Memory" << std::endl;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }

    BufferReusement(const BufferReusement& other)
    {
        std::cout << "Copy Constructor" << std::endl;
        std::cout << "Allocating Memory" << std::endl;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    ~BufferReusement()
    {
        std::cout << "Destructor" << std::endl;
        std::cout << "Deallocating Memory" << std::endl;
        delete [] name;
    }

    friend void swap(BufferReusement& lhs, BufferReusement& rhs)
    {
        using std::swap;
        swap(lhs.name, rhs.name);
    }

    BufferReusement& operator=(const BufferReusement& other)
    {
        std::cout << "Operator=" << std::endl;
        if (this != &other)
        {
            // Only reallocate memory if the buffer is not of sufficient size
            if (strlen(name) < strlen(other.name))
            {
                BufferReusement temp(other);
                swap(*this, temp);
            }
            else
            {
                strcpy(name, other.name);
            }
        }

        return *this;
    }
private:
    char * name;
};

int main()
{
    Classic c1("Kappa"), c2("Mappa");
    std::cout << "--------------------" << std::endl;
    // 1 deallocation and 1 allocation
    std::cout << "Assigning c2 to c1: " << std::endl;
    c1 = c2;
    std::cout << "-------------" << std::endl;

    CopyAndSwap cas1("Kappa"), cas2("Mappa");
    std::cout << "--------------------" << std::endl;
    // 1 deallocation and 1 allocation, but notice the order
    // Memory deallocation happens last
    // Allocation happens before we call operator=
    std::cout << "Assigning cas2 to cas1: " << std::endl;
    cas1 = cas2;
    std::cout << "-------------" << std::endl;

    BufferReusement br1("Kappa"), br2("Mappa");
    std::cout << "--------------------" << std::endl;
    // br1's buffer is big enough so we do 0 memory reallocations
    std::cout << "Assigning br2 to br1: " << std::endl;
    br1 = br2;
    std::cout << "-------------" << std::endl;

    BufferReusement br3("Kappa"), br4("monkaS");
    std::cout << "--------------------" << std::endl;
    // br3's buffer is not big enough so we fall back to a different strategy
    std::cout << "Assigning br4 to br3: " << std::endl;
    br3 = br4;
    std::cout << "-------------" << std::endl;
    return 0;
}
