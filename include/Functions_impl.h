#ifndef FUNCTIONS_IMPL_H
#define FUNCTIONS_IMPL_H

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>

#include "HourlyWaged.h"
#include "MonthlyWaged.h"

using namespace std;


template<typename T>
bool Functions::SortOnName<T>::operator() (const T& pLeft_object, const T& pRight_object)
{

    if(pLeft_object->GetAvgSalary() == pRight_object->GetAvgSalary())
    {
        return (pLeft_object->GetName() < pRight_object->GetName());
    }
    else
    {
        return (pLeft_object->GetAvgSalary() > pRight_object->GetAvgSalary());//max-to-min
    }

}


template<typename T>
void Functions::DeleteObjectsBeforeExit (T& ContainerInput)
{
    for(auto Iterator = ContainerInput.begin();//auto = typename T::const_iterator
    Iterator != ContainerInput.end();
    ++Iterator)
    {
        delete (*Iterator);
    }

}


template<typename T>
void Functions::DisplayContainer (const T& ContainerInput)
{
    cout << left << setw(5) << "Num." << setw(5) << "ID"
    << setw(15) << "Name" << setw(15) << "Surname" << setw(15) << "AvgSalary" << endl;

    for(auto Iterator = ContainerInput.cbegin();//auto = typename T::const_iterator
    Iterator != ContainerInput.cend();
    ++Iterator)
    {
        cout << left << setw(5) << distance(ContainerInput.cbegin(), Iterator)
        << setw(5) << (*Iterator)->GetEmployeeID() << setw(15) << (*Iterator)->GetName()
        << setw(15) << (*Iterator)->GetSurname() << setw(15)
        << (*Iterator)->GetAvgSalary() << endl;
    }

}


template<typename T>
void Functions::PopulateContainer(T& ContainerInput)
{
    ContainerInput.insert(new HourlyWaged("D_Stas", "Tolerance", 20.0));
    ContainerInput.insert(new MonthlyWaged("d_Bill", "Gates", 20.0));
    ContainerInput.insert(new HourlyWaged("C_Average", "Joe", 19.0));
    ContainerInput.insert(new MonthlyWaged("c_Viktor", "Yanukovich'", 19.0));
    ContainerInput.insert(new HourlyWaged("B_Jane", "Roe", 18.0));
    ContainerInput.insert(new MonthlyWaged("b_Frank", "Foe", 18.0));
    ContainerInput.insert(new HourlyWaged("A_Tommy", "Toe", 18.0));
    ContainerInput.insert(new MonthlyWaged("a_Karren", "Koe", 18.0));
}


template<typename T>
void Functions::DisplayFirst5Names(T& ContainerInput)
{
    cout << "Num.\tName" << endl;

    typename T::const_iterator RangeEnd = ContainerInput.cbegin();

    advance(RangeEnd, 5);

    for_each(ContainerInput.cbegin(), RangeEnd,
             [](const Employee* pInput) ->void
             {cout << "\t" << pInput->GetName() << endl;} );
}

template<typename T>
void Functions::DisplayLast3IDs(T& ContainerInput)
{
    cout << "Num.\tID" << endl;

    typename T::const_iterator RangeBegin = ContainerInput.cend();

    advance(RangeBegin, -3);

    for_each(RangeBegin, ContainerInput.cend(),
             [](const Employee* pInput) ->void
             {cout << "\t" << pInput->GetEmployeeID() << endl;} );
}

template<typename T>
void Functions::WriteToFile(const T& ContainerInput)
{
    ofstream WriteBuffer;

    WriteBuffer.open("WriteToFile.txt", ios_base::out);
    if(WriteBuffer.is_open())
    {
        cout << "File open for write success!" << endl;

        WriteBuffer << left << setw(5) << "Num." << setw(5) << "ID"
        << setw(15) << "Name" << setw(15) << "Surname" << setw(15) << "AvgSalary" << endl;

        for(typename T::const_iterator Iterator = ContainerInput.cbegin();
        Iterator != ContainerInput.cend();
        ++Iterator)
        {
            WriteBuffer << left << setw(5) << distance(ContainerInput.cbegin(), Iterator)
            << setw(5) << (*Iterator)->GetEmployeeID() << setw(15) << (*Iterator)->GetName()
            << setw(15) << (*Iterator)->GetSurname() << setw(15)
            << (*Iterator)->GetAvgSalary() << endl;

        }

        WriteBuffer.close();
        cout << "Write buffer closed!" << endl;

    }
    else
        cout << "File open for write fail." << endl;

}

template<typename T>
void Functions::ReadFromFile(const T& ContainerInput)
{
    ifstream ReadBuffer;

    ReadBuffer.open("WriteToFile.txt", ios_base::in);
    if(ReadBuffer.is_open())
    {
        cout << "File open for read success!" << endl;

        string FileContent;

        while(ReadBuffer.good())
        {
            getline(ReadBuffer, FileContent);
            cout << FileContent << endl;
        }

        ReadBuffer.close();
        cout << "Read buffer closed!" << endl;
    }
    else
        cout << "File open for read fail." << endl;

}

#endif // FUNCTIONS_IMPL_H
