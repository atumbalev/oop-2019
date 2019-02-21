#include <iostream>
#include <iomanip>

const int MAX_PRISONERS = 100;
const int MAX_NAME_LENGTH = 20;

struct Prisoner
{
    char name[MAX_NAME_LENGTH];
    int ID;
    int time;
};

void printPrisoner(const Prisoner& prisoner)
{
    std::cout << std::left
              << std::setw(MAX_NAME_LENGTH) << prisoner.name
              << std::setw(15)              << prisoner.ID
              << std::setw(15)              << prisoner.time << std::endl;
}

struct Prison
{
    char name[MAX_NAME_LENGTH];
    int size;
    Prisoner* prisoners[MAX_PRISONERS];
};

void printPrison(const Prison& prison)
{
    std::cout << prison.name << std::endl;

    std::cout << std::left
              << std::setw(MAX_NAME_LENGTH) << "Name"
              << std::setw(15)              << "ID"
              << std::setw(15)              << "Time" << std::endl;

    for (int i = 0; i < prison.size; ++i)
    {
        printPrisoner(*prison.prisoners[i]);
    }
}

using Comparator = bool(*)(Prisoner const*, Prisoner const*);

// Using Selection Sort
void sortPrison(Prison& prison, Comparator cmp)
{
    for (int i = 0; i < prison.size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < prison.size; ++j)
        {
            if (cmp(prison.prisoners[j], prison.prisoners[minIndex]))
            {
                minIndex = j;
            }
        }

        std::swap(prison.prisoners[minIndex], prison.prisoners[i]);
    }
}

bool timeComparator(Prisoner const* p1, Prisoner const* p2)
{
    return p1->time <= p2->time;
}

int main(int argc, char const *argv[])
{
    Prisoner p{"Pe6o Pe6o Pe6o Pe6o", 10, 200};
    Prisoner m{"Me6o", 20, 40};
    Prisoner p2{"Pe6o 2222222", 24, 2};

    Prison fmi{"FMI", 3, {&p, &p2, &m}};
    printPrison(fmi);

    std::cout << std::endl;
    sortPrison(fmi, timeComparator);
    printPrison(fmi);

    // BONUS: Using Lambdas
    std::cout << std::endl;
    sortPrison(fmi, [](Prisoner const* p1, Prisoner const* p2){ return p1->ID <= p2->ID; });
    printPrison(fmi);

    return 0;
}
