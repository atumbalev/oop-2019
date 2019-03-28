# Bonus 4. Stack Adapter

## Problem

Implement a stack that adapts another data structure by only allowing stack-like behaviour.

STL Data Structures that you should support:
* std::vector (aka resizing array) - ```#include <vector>```
* std::list (we will look more into this next time) - ```#include <list>```
* std::deque (might look into this next semester) - ```#include <deque>```

The stack should:
* Be templated (type of elements and type of container)
* By default use std::deque
* Support the following operations
	* default constructor - initilize the stack with an empty container
	* constructor that takes a container and makes it a stack
	* push - add an element to the back of the container
	* pop - remove the last element
	* top - return a (const) reference to the last element
	* empty - return whether the container is empty
	* size - return the size of the container

## Notes

This task will also demonstrate some basic OOP principles:
* You do **NOT** need to know how the 3 STL containers actually work, just that they keep a sequence of elements (Abstraction)
* Do **NOT** implement methods or keep data that you do not need (Not going to spoil this one)

## Hint

The whole assignment could be done in around 15ish lines of code if you find yourself writing a lot, you are probably on the wrong track.

## Deadline

```
07.04.2019 23:59
```
