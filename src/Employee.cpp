#include "Employee.h"

//STATIC VAR INIT
unsigned int Employee::IDCounter = 0;


Employee::Employee(const string& inName, const string& inSurname)
        : Name(inName), Surname(inSurname), AvgSalary(0.0), EmployeeID(0)
        {
            ++IDCounter;
            EmployeeID = IDCounter;
        }


Employee::~Employee()
{

}


const string& Employee::GetName() const
{
    return Name;
}


const string& Employee::GetSurname() const
{
    return Surname;
}


const double& Employee::GetAvgSalary() const
{
    return AvgSalary;
}


const unsigned int& Employee::GetIDCounter()
{
    return IDCounter;
}


const unsigned int& Employee::GetEmployeeID() const
{
    return EmployeeID;
}


double& Employee::SetAvgSalary()
{
    return AvgSalary;
}
