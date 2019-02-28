# Basic OOP

## Gameplan

* OOP
* Principles
* Abstraction
* methods
* Encapsulation
* Access Specifiers
* Selectors and Mutators
* const qualifer
* this, cascading

## Problem

### Define a class Nurse that includes:

#### Properties
* Name (no more than 50 characters)
* Number of patients assigned to her

#### Methods
* Every appropriate selector and mutator
* print(): prints the information about the patient

### Define a class Patient that includes:

#### Properties
* Name (no more than 50 characters)
* Room Numbers (integer between 100 and 999)
* Pointer to Nurse that takes care of him

#### Methods
* Every appropriate selector and mutator
* print(): prints the information about the patient (if he has a nurse, print the info about her on the same line)
	
### Define a class Hospital that includes:

#### Properties

* array of patients (max 100)
* array of nurses (max 100)

#### Methods

* addPatient: Add a patient and assign him the first nurse in the array that has less than 2 assigned patients, if there isn't such nurse assign him null
* addNurse: Add a nurse
* removePatient: Given a name, remove the first patient with that name
* print() print the info about all the patients