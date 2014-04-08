#include "MonthlyWaged.h"

void MonthlyWaged::CalculateSalary()
{
    Employee::SetAvgSalary() = Fixed_Wage;
}


MonthlyWaged::MonthlyWaged(const string& inName, const string& inSurname,
                           double inFixed_Wage)
        : Employee(inName, inSurname),
        Fixed_Wage(inFixed_Wage)
        {
            CalculateSalary();
        }


MonthlyWaged::~MonthlyWaged()
{

}

