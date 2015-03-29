#include "HourlyWaged.h"

HourlyWaged::HourlyWaged(const string name, const string surname, const double rate)
: Employee(name, surname, rate)
{
    CalculateSalary();
}

void HourlyWaged::CalculateSalary()
{
    setAvgSalary(Days * Hours * getRate() );
}
