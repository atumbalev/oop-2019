#ifndef EXERCISES_04___DYNAMIC_ARRAYS_COMPANY_WORKER_HPP_
#define EXERCISES_04___DYNAMIC_ARRAYS_COMPANY_WORKER_HPP_

#include <iostream>

class Worker
{
 public:
    // Big 4
    explicit Worker(const char* _name = "", const char* _position = "", double _salary = 0);
    ~Worker();
    Worker(const Worker& other);
    Worker& operator=(const Worker& other);

    // Mutators and Selectors
    void setName(const char* _name);
    void setPosition(const char* _position);
    void setSalary(double _salary) { salary = _salary; }

    const char* getName() const { return name; }
    const char* getPosition() const { return position; }
    int getSalary() const { return salary; }

    void print() { std::cout << name << " " << position << " " << salary << std::endl; }
    friend void swap(Worker& lhs, Worker& rhs);
 private:
    char *name;
    char *position;
    double salary;

    void del();
    void copyWorker(const Worker& other);
};

#endif  // EXERCISES_04___DYNAMIC_ARRAYS_COMPANY_WORKER_HPP_
