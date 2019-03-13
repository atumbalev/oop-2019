#include <iostream>
#include <cstring>

#include "Company.hpp"

void Company::del()
{
    delete [] name;
    delete [] workers;
}

void Company::setName(const char* _name)
{
    if (!_name)
    {
        _name = nullptr;
    }

    delete [] name;
    int len = strlen(_name) + 1;
    name = new char[len + 1];
    strcpy(name, _name);
}

void Company::copy(const Company& other)
{
    setName(other.name);
    capacity = other.capacity;
    size = other.size;
    workers = new Worker[capacity];
    for (int i = 0; i < size; ++i)
    {
        workers[i] = other.workers[i];
    }
}

Company::Company(const char* _name, size_t _capacity):
    name(nullptr),
    workers(nullptr),
    size(0),
    capacity(_capacity)
{
    workers = new Worker[capacity];
    setName(_name);
}

Company::Company(const Company& other)
{
    name = nullptr;
    copy(other);
}

Company::~Company()
{
    del();
}

Company& Company::operator=(const Company& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

void Company::print() const
{
    std::cout << name << std::endl;
    for (int i = 0; i < size; ++i)
    {
        workers[i].print();
    }
}

void Company::extend()
{
    Worker *tmp = workers;
    capacity *= 2;
    workers = new Worker[capacity];
    for (int i = 0; i < size; ++i)
    {
        workers[i] = tmp[i];
    }
    delete [] tmp;
}

void Company::add(const Worker& worker)
{
    if (size == capacity)
    {
        extend();
    }

    workers[size++] = worker;
}

void Company::remove(const char* _name)
{
    for (int i = 0; i < size; ++i)
    {
        if (strcmp(workers[i].getName(), _name) == 0)
        {
            for (int j = i; j < size - 1; ++j)
            {
                workers[j] = workers[j + 1];
            }

            --size;
            return;
        }
    }
}

void Company::sort()
{
    for (int i = 0; i < size - 1; ++i)
    {
        Worker min = workers[i];
        size_t minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (workers[j].getSalary() < min.getSalary())
            {
                min = workers[j];
                minIndex = j;
            }
        }

        std::swap(workers[i], workers[minIndex]);
    }
}
