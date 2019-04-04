#include "Company.hpp"
#include "Worker.hpp"

int main()
{
    Worker w1("Gosho", "Cleaner", 50);
    Worker w2("Peter", "CEO", 15000);
    Worker w3("Anthony", "Painter", 600);
    Worker w4("Natalia", "Designer", 3000);
    Worker w5("Kalina", "Computer programmer", 5000);

    Company c("The players EOOD");

    c.print();
    std::cout << std::endl;

    c.add(w1);
    c.print();
    std::cout << std::endl;

    c.add(w2);
    c.print();
    std::cout << std::endl;

    c.add(w3);
    c.print();
    std::cout << std::endl;

    c.add(w4);
    c.print();
    std::cout << std::endl;

    c.add(w5);
    c.print();
    std::cout << std::endl;

    c.sort();  // sort by salary
    std::cout << "Sorted by salary: \n";
    c.print();
    std::cout << std::endl;

    // test copy constructor
    Company copyCtorTest(c);
    std::cout << "Copy ctor test---------------\n";
    copyCtorTest.print();
    std::cout << std::endl;

    copyCtorTest.remove("Kalina");
    copyCtorTest.remove("Anthony");
    copyCtorTest.remove("Peter");
    copyCtorTest.print();
    std::cout << std::endl;

    c.print();  // should have same data

    std::cout << "Copy ctor test finished-------------\n";

    c.remove("Natalia");
    c.remove("Peter");
    std::cout << std::endl;

    c.print();

    c.remove("Gosho");
    std::cout << std::endl;

    c.print();
    std::cout << std::endl;

    c.remove("Anthony");
    c.remove("Kalina");
    c.print();
    std::cout << std::endl;

    c.add(w1);
    c.print();

    return 0;
}
