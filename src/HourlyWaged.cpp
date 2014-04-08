#include "HourlyWaged.h"

void HourlyWaged::CalculateSalary()
{
    Employee::SetAvgSalary() = 20.8 * 8 * Hourly_wage;
}


HourlyWaged::HourlyWaged(const string& inName, const string& inSurname,
                         double inHourly_wage)
        : Employee(inName, inSurname),
        Hourly_wage(inHourly_wage)
        {
            CalculateSalary();
        }


HourlyWaged::~HourlyWaged()
{

}
