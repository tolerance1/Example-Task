#include "MonthlyWaged.h"

MonthlyWaged::MonthlyWaged(const string name, const string surname, const double rate)
: Employee(name, surname, rate)
{
    CalculateSalary();
}

void MonthlyWaged::CalculateSalary()
{
    setAvgSalary(getRate() );
}

