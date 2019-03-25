# Bonus 2. Optional

## Problem

Implement a class OptionalInt that may or may not hold a valid integer value and has the following methods:

* operators-> and * for accessing the current value without checking if it is valid (both const and non-const versions)
* typecast to bool that returns whether the value is valid
* value - that returns the value if it is valid and somehow produces an error if it isn't
* value_or - takes an integer argument and returns the value if it is valid or the given integer otherwise
* reset - makes the value invalid
* operators== and != (invalid optionals are always considered equal and never equal to valid ones)

Also implement:
* A sensible operator+ for 2 optional ints
* A binary search function for an array that returns an optional

## Deadline

```
07.04.2019 23:59
```
