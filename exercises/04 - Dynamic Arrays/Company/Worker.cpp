#include <cstring>
#include <iostream>

#include "Worker.hpp"

void Worker::del()
{
    delete [] name;
    delete [] position;
}

void Worker::setName(const char* _name)
{
    if (!_name)
    {
        _name = "";
    }

    delete [] name;

    int len = strlen(_name);
    name = new char[len + 1];
    strncpy(name, _name, len + 1);
}

void Worker::setPosition(const char* _position)
{
    if (!_position)
    {
        _position = "";
    }

    delete [] position;

    int len = strlen(_position);
    position = new char[len + 1];
    strncpy(position, _position, len + 1);
}

void Worker::copyWorker(const Worker& other)
{
    name = position = nullptr;
    setName(other.name);
    setPosition(other.position);
    setSalary(other.salary);
}

Worker::Worker(
    const char* _name,
    const char* _position,
    double _salary):
        name(nullptr),
        position(nullptr),
        salary(_salary)
{
    setName(_name);
    setPosition(_position);
}

Worker::~Worker()
{
    del();
}

Worker::Worker(const Worker& other)
{
    copyWorker(other);
}

Worker& Worker::operator=(const Worker& other)
{
    if (this != &other)
    {
        del();
        copyWorker(other);
    }

    return *this;
}
