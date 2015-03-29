#ifndef MONTHLYWAGED_H
#define MONTHLYWAGED_H

#include "Employee.h"

class MonthlyWaged: public Employee
{
    public:
        MonthlyWaged(const string name, const string surname, const double rate);
        ~MonthlyWaged() {}

        void CalculateSalary();
};

#endif // MONTHLYWAGED_H
