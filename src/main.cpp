#include <set>
#include <iostream>
#include <exception>

#include "Employee.h"
#include "Functions.h"

using namespace std;
using namespace Functions;


int main()
{
    multiset<Employee*, SortOnSalary<Employee*> > employees;

    try
    {
        cout << "--TASK A, E--" << endl;
        PopulateContainer(employees);
        OutputContainer(cout, employees);

        cout << "--TASK B--" << endl;
        DisplayFirst5names(employees);

        cout << "--TASK C--" << endl;
        DisplayLast3IDs(employees);

        cout << "--TASK D--" << endl;
        WriteToFile(employees);
        ReadFromFile();
    }
    catch(const exception& exp)
    {
        cout << "Exception: " << exp.what() << endl;
    }
    catch(...)
    {
        cout << "Unknown exception!" << endl;
    }

    DeleteObjectsBeforeExit(employees);


    char ch = '\0';
    cin >> ch;


    return 0;
}
