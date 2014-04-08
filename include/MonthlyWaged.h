#ifndef MONTHLYWAGED_H
#define MONTHLYWAGED_H

#include "Employee.h"

class MonthlyWaged: public Employee
{
    public:
        MonthlyWaged(const string& inName, const string& inSurname,
                     double inFixed_Wage = 0.0);
        ~MonthlyWaged();

        void CalculateSalary();

    private:
        double Fixed_Wage;

};

#endif // MONTHLYWAGED_H
