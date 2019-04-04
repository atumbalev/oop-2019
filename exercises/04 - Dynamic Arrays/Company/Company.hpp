#pragma once

#include "Worker.hpp"

class Company
{
 public:
    // Big 4
    explicit Company(const char* name = "", size_t capacity = 4);
    ~Company();
    Company(const Company& other);
    Company& operator=(const Company& other);

    // Mutators and selectors
    void setName(const char* name);
    const char* getName() const { return name; }

    void add(const Worker& worker);
    void print() const;
    void remove(const char* _name);
    void sort();
 private:
    char *name;
    Worker *workers;
    size_t size;
    size_t capacity;

    void del();
    void copyCompany(const Company& other);
    void extend();
};
