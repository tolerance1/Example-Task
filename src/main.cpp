#include <set>
#include <iostream>
#include <exception>

#include "Employee.h"
#include "Functions.h"

using namespace std;
using namespace Functions;


int main()
{
    multiset<Employee*, SortOnName<Employee*> > msetOfEmployees;

    PopulateContainer(msetOfEmployees);

    cout << "--TASK A--" << endl;
    DisplayContainer(msetOfEmployees);

    cout << "--TASK B--" << endl;
    DisplayFirst5Names(msetOfEmployees);

    cout << "--TASK C--" << endl;
    DisplayLast3IDs(msetOfEmployees);

    cout << "--TASK D, E--" << endl;
    WriteToFile(msetOfEmployees);

    //handle read errors
    try
    {
        ReadFromFile(msetOfEmployees);
    }
    catch(const exception& exp)
    {
        cout << "EXCEPTION IN FUNCTION ReadFromFile()!: " << exp.what() << endl;
    }
    catch(...)
    {
        cout << "UNKNOWN EXCEPTION!" << endl;
    }

    DeleteObjectsBeforeExit(msetOfEmployees);


    return 0;
}
