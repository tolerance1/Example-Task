#ifndef HOURLYWAGED_H
#define HOURLYWAGED_H

#include "Employee.h"

class HourlyWaged : public Employee
{
    public:
        HourlyWaged(const string name, const string surname, const double rate);
        ~HourlyWaged() {}

        void CalculateSalary();

    private:
        double Hours {8};
        double Days {20.8};
};

#endif // HOURLYWAGED_H
