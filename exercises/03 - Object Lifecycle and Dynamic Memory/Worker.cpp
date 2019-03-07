#include <iostream>
#include <cstring>

class Worker
{
public:
    // Cannonical Representation
    Worker(const char* _name = "",
           const char* _position = "",
           double _salary = 0):
        name(nullptr),
        position(nullptr),
        salary(_salary)
    {
        setName(_name);
        setPosition(_position);
    }

    ~Worker()
    {
        del();
    }

    Worker(const Worker& other)
    {
        copy(other);
    }

    Worker& operator=(const Worker& other)
    {
        if(this != &other)
        {
            del();
            copy(other);
        }

        return *this;
    }

    // Mutators and Selectors
    void setName(const char* _name)
    {
        if (!_name)
        {
            _name = "";
        }

        delete [] name;

        int len = strlen(_name);
        name = new char[len + 1];
        strcpy(name, _name);
    }

    void setPosition(const char* _position)
    {
        if (!_position)
        {
            _position = "";
        }

        delete [] position;

        int len = strlen(_position);
        position = new char[len + 1];
        strcpy(position, _position);
    }

    void setSalary(double _salary)
    {
        salary = _salary;
    }

    const char* getName() const
    {
        return name;
    }
    
    const char* getPosition() const
    {
        return position;
    }
    
    int getSalary() const
    {
        return salary;
    }

    void print()
    {
        std::cout << name << " "
                  << position << " "
                  << salary << std::endl;
    }

private:
    char *name;
    char *position;
    double salary;

    void del()
    {
        delete [] name;
        delete [] position;
    }

    void copy(const Worker& other)
    {
        name = position = nullptr;
        setName(other.name);
        setPosition(other.position);
        setSalary(other.salary);
    }
};

int main(int argc, char const *argv[])
{
    Worker p1("Pe6o", "CEO", 100000);
    Worker p2 = p1;
    Worker p3;
    p3 = p1;
    
    p1.print();
    p2.print();
    p3.print();


    p1.setName("Me6o");
    p2.setName("Sme6o");

    p1.print();
    p2.print();
    p3.print();

    return 0;
}
