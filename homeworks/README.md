# Homework 01 - Vector

## vector 

Implement a generic resizing array (aka vector) with the following properties:

* An inner class iterator that wraps a pointer to an element in the vector with the following methods:
    * Prefix and postfix operators ++ and -- that move the pointer the the next / previous element in the vector
    * All versions of operators * and -> for working with pointers
    * All comparision operators (compare the wrapped pointers)
    * operators + that:
        * Adds iterator to integer (move the iterator that many places)
        * Adds integer to iterator
    * operators - that:
        * Subtracts an integer from iterator to move it backwards
        * Subtracts 2 iterators to return the how many elements away from each other they are
    * operators += and -=

* Default constructor that creates an empty vector
* Constructor that takes a number and reserves enough space for that many elements
* Constructor that takes a number and an element and initializes the vector with that many copies of the given element
* Constructor that takes an initialzier list

* operator[] - returns reference to element at given index
* at - same as above with bounds checking
* front - reference to first element
* back - reference to last element

* begin - returns iterator that points to first element
* end - returns iterator that points AFTER the last element

* empty- returns whether the vector is empty
* size - returns the size of the vector
* reserve - takes a number and reserves memory for that many elemens (does nothing if the number is less than the current capacity)
* capacity - returns the amount of elements that the vector can currently store
* shink_to_fit - reduces memory usage by freeing unused memory

* insert - takes an iterator and an element, inserts the element before the position pointed by the iterator and returns an iterator pointing to the inserted value
* erase - takes an iterator, removes the element at that position and returns an iterator that points to the next element
* push_back - adds an element to the end
* pop_back - removes the last element
* swap - swaps the contents of 2 vectors
* comparison operators - lexicographically compares the values in the vector
* erase - remove all elements equal to a given one
* erase_if - remove all elements that statisfy a given predicate

## Examples using STL

```c++
// initializing with initializer list
vector<int> v = {1, 2, 3, 4, 5,};
// Range-based for loop, should work with your vector if you follow the given interface
for (int num : v)
{
    std::cout << num << std::endl;
}
/*
Output:
1
2
3
4
5
*/

#include <algorithm> // standard implementations of various algorithms, all of them work with iterators so they should work with your implementations

std::for_each(v.begin(), v.end(), [](int num) {
    std::cout << num << std::endl;
}); // Prints the elements in the vector
```

## Notes

* Use the given names for your methods
* Follow OOP principles shown in class
* Demonstrate usage of your vector in the main function
*  **Programs that don't compile receive 0 points automatically**


## Deadline

31.04.2019 23:59
