#include "Employee.h"

//STATIC VAR INIT
unsigned int Employee::IDCounter = 0;


Employee::Employee(const string name, const string surname, const double rate)
: name(name), surname(surname), rate(rate)
{
    employeeID = ++IDCounter;
}
