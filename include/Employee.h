#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using std::string;

class Employee
{
    public:
        Employee(const string& inName, const string& inSurname);
        virtual ~Employee();

        virtual void CalculateSalary() = 0;

        //GETTERS
        const string& GetName() const;
        const string& GetSurname() const;
        const double& GetAvgSalary() const;
        static const unsigned int& GetIDCounter();
        const unsigned int& GetEmployeeID() const;

        //SETTERS
        double& SetAvgSalary();

    private:
        string Name;
        string Surname;

        double AvgSalary;

        static unsigned int IDCounter;//global id counter

        unsigned int EmployeeID;

};

#endif // EMPLOYEE_H
