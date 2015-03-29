#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using std::string;

class Employee
{
    public:
        Employee(const string name, const string surname, const double rate);
        virtual ~Employee() {}

        virtual void CalculateSalary() = 0;

        //GETTERS
        const string& getName() const {return name; }
        const string& getSurname() const {return surname; }
        const double getRate() const {return rate; }
        const double getAvgSalary() const {return avgSalary; }
        const unsigned int getEmployeeID() const {return employeeID; }

        //SETTERS
        void setAvgSalary(const double value) {avgSalary = value; };

    private:
        string name;
        string surname;

        double rate;
        double avgSalary {0.0};

        unsigned int employeeID {0};

        static unsigned int IDCounter;//global id counter
};

#endif // EMPLOYEE_H
