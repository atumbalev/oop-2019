#include <iostream>
#include <cassert>
#include <cstring>

const int MAX_NAME = 50;
const int MAX_CAPACITY = 200;
const int MAX_ASSIGNED = 2;

class Nurse
{
public:
    void setName(const char* _name)
    {
        int len = strlen(_name);
        assert(len <= 50);
        strncpy(name, _name, len);
    }

    unsigned getAssignedPatientsCount() const
    {
        return assignedPatientsCount;
    }

    const char* getName() const
    {
        return name;
    }

    // Would be better if this is a private function that only Patient / Hospital has access to.
    // We will learn about this later
    void addPatient()
    {
        assignedPatientsCount++;
    }

    void removePatient()
    {
        assert(assignedPatientsCount);
        assignedPatientsCount--;
    }

    void print() const
    {
        std::cout << "Nurse " << name << " Patients: "
                  << assignedPatientsCount << std::endl;
    }

private:
    char name[MAX_NAME];
    unsigned assignedPatientsCount = 0;
};

class Patient
{
public:
    void setName(const char* _name)
    {
        int len = strlen(_name);
        assert(len <= 50);
        strncpy(name, _name, len);
    }

    void setRoomNumber(unsigned _roomNumber)
    {
        assert(_roomNumber >= 100 && _roomNumber <= 999);
        roomNumber = _roomNumber;
    }

    void setAssignedNurse(Nurse *_assignedNurse)
    {
        if (assignedNurse)
        {
            assignedNurse->removePatient();
        }

        assignedNurse = _assignedNurse;
        if (assignedNurse)
        {
            assignedNurse->addPatient();
        }
    }

    const char* getName() const
    {
        return name;
    }

    unsigned getRoomNumber() const
    {
        return roomNumber;
    }

    Nurse const* getAssignedNurse() const
    {
        return assignedNurse;
    }

    void print() const
    {
        std::cout << name << " " << roomNumber << " ";
        assignedNurse->print();
    }
private:
    char name[MAX_NAME];
    unsigned roomNumber;
    Nurse *assignedNurse = nullptr;
};

class Hospital
{
public:
    size_t getNumNurses() const
    {
        return numNurses;
    }

    size_t getNumPatients() const
    {
        return numPatients;
    }

    Hospital& addPatient(const Patient& patient)
    {
        assert(numPatients < MAX_CAPACITY);
        patients[numPatients] = patient;
        for (int i = 0; i < numNurses; ++i)
        {
            if (nurses[i].getAssignedPatientsCount() < MAX_ASSIGNED)
            {
                patients[numPatients++].setAssignedNurse(&nurses[i]);
                return *this;
            }
        }

        patients[numPatients++].setAssignedNurse(nullptr);
        return *this;
    }

    Hospital& addNurse(const Nurse& nurse)
    {
        assert(numNurses < MAX_CAPACITY);
        nurses[numNurses++] = nurse;
        return *this;
    }

    Hospital& removePatient(const char* name)
    {
        int len = strlen(name);
        for (int i = 0; i < numPatients; ++i)
        {
            if (strncmp(patients[i].getName(), name, len) == 0)
            {
                patients[i].setAssignedNurse(nullptr);
                patients[i] = patients[--numPatients];
            }
        }

        return *this;
    }

    void print() const
    {
        for (int i = 0; i < numPatients; ++i)
        {
            patients[i].print();
        }
    } 
private:
    Nurse nurses[MAX_CAPACITY];
    size_t numNurses = 0;
    Patient patients[MAX_CAPACITY];
    size_t numPatients = 0;
};


int main()
{
    Patient a, b, c;
    a.setName("Pe6o");
    a.setRoomNumber(100);

    b.setName("Go6o");
    b.setRoomNumber(210);

    c.setName("Mi6o");
    c.setRoomNumber(322);

    Nurse x, y, z;
    x.setName("Joy");
    z.setName("Pe6o");
    y.setName("Pe6ovica");

    Hospital h;
    h.addNurse(x).addNurse(y).addNurse(z).addPatient(a).addPatient(b).addPatient(c).print();
    std::cout << std::endl;

    h.removePatient("Go6o").print();
    return 0;
}