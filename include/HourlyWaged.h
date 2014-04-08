#ifndef HOURLYWAGED_H
#define HOURLYWAGED_H

#include "Employee.h"

class HourlyWaged : public Employee
{
    public:
        HourlyWaged(const string& inName, const string& inSurname,
                    double inHourly_wage = 0.0);
        ~HourlyWaged();

        void CalculateSalary();

    private:
        double Hourly_wage;

};

#endif // HOURLYWAGED_H
