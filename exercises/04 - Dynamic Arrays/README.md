# Dynamic Arrays

## Gameplan

* Separating code
	* Interface
		* Guards
		* inline functions
	* Implementation
	* Basic build process
* Vector
	* Chosing a growth factor
* Swap
* friend functions
* Alternative assignment strategies
	* Copy and Swap Idiom
	* Copy Elision
	* Reusing Buffers

## Problem (continued from last time)

### NEW! Separate into header and cpp files.

### Define a class Worker that includes:

#### Properties
* Name (no limit)
* Position (no limit)
* Salary

#### Methods
* Cannonical Representation
* Mutators and Selectors
* Print method

### Define a class Factory

#### Properties
* Name (no size limit)
* Array of workers (no size limit)

#### Methods
* Cannonical Representation
* Mutators and Selectors
* Print the name and then every worker in order
* Sort workers by salary
* Add Worker to the end of the array
* Remove worker by name
