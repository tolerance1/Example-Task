#ifndef FUNCTIONS_IMPL_H
#define FUNCTIONS_IMPL_H

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <sstream>

#include "HourlyWaged.h"
#include "MonthlyWaged.h"

using namespace std;


template<typename T>
bool Functions::SortOnSalary<T>::operator() (const T& pLeft_object, const T& pRight_object)
{

    if(pLeft_object->getAvgSalary() == pRight_object->getAvgSalary())
    {
        return (pLeft_object->getName() < pRight_object->getName());
    }
    else
    {
        return (pLeft_object->getAvgSalary() > pRight_object->getAvgSalary());//max-to-min
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
void Functions::OutputContainer (ostream& os, const T& ContainerInput)
{
    os << left << setw(5) << "Num." << setw(5) << "ID"
    << setw(15) << "Name" << setw(15) << "Surname" << setw(15) << "AvgSalary" << endl;

    for(auto Iterator = ContainerInput.cbegin();//auto = typename T::const_iterator
    Iterator != ContainerInput.cend();
    ++Iterator)
    {
        size_t elementPosition = distance(ContainerInput.cbegin(), Iterator);

        os << left << setw(5) << ++elementPosition << setw(5) << (*Iterator)->getEmployeeID()
        << setw(15) << (*Iterator)->getName() << setw(15) << (*Iterator)->getSurname()
        << setw(15) << (*Iterator)->getAvgSalary() << endl;
    }

}


template<typename T>
void Functions::PopulateContainer(T& ContainerInput)
{
    ifstream input("Employees.txt");

    if(input)//if successfully opened
    {
        for(size_t lineNumber = 1; input.good(); ++lineNumber)//while not EOF
        {
            string line;
            getline(input, line);

            //replace each comma with a space
            for_each(line.begin(), line.end(),
                     [](char& c){if(c == ',') c = ' ';} );

            //remove consecutive duplicate spaces
            string::iterator newEnd =
            unique(line.begin(), line.end(),
                   [](char& ch1, char& ch2){return (ch1 == ' ' && ch2 == ' ');} );

            //erase the shifted duplicates
            line.erase(newEnd, line.end());


            string name, surname, wageType;
            double rate = 0.0;

            //extract the data
            istringstream iss(line);
            iss >> name >> surname >> rate >> wageType;


            //check the line format
            if(wageType.empty() || rate <= 0.0 || surname.empty() || name.empty())
            {
                ostringstream oss;
                oss << "Line " << lineNumber << ": Bad format: \"" << line << "\"" << endl;
                throw runtime_error(oss.str());
            }

            //avoid potential typing errors
            for(char& c : wageType)//for every char in the string
            {
                c = tolower(c);
            }

            if(wageType == "hourly")
            {
                ContainerInput.insert(new HourlyWaged(name, surname, rate));
            }
            else if(wageType == "monthly")
            {
                ContainerInput.insert(new MonthlyWaged(name, surname, rate));
            }
            else
            {
                ostringstream oss;
                oss << "Line " << lineNumber << ": Incorrect wage type: \"" << line << "\"" << endl;
                throw runtime_error(oss.str());
            }
        }
    }
    else
        throw runtime_error("Failed to open a file.");
}


template<typename T>
void Functions::DisplayFirst5names(const T& ContainerInput)
{
    cout << "Num.\tName" << endl;

    typename T::const_iterator RangeEnd = ContainerInput.cbegin();

    advance(RangeEnd, 5);

    size_t counter = 0;

    for_each(ContainerInput.cbegin(), RangeEnd,
             [&counter](const Employee* pInput) ->void
             {cout << ++counter << "\t" << pInput->getName() << endl;} );
}


template<typename T>
void Functions::DisplayLast3IDs(const T& ContainerInput)
{
    cout << "Num.\tID" << endl;

    typename T::const_iterator RangeBegin = ContainerInput.cend();

    advance(RangeBegin, -3);

    size_t counter = 0;

    for_each(RangeBegin, ContainerInput.cend(),
             [&counter](const Employee* pInput) ->void
             {cout << ++counter << "\t" << pInput->getEmployeeID() << endl;} );
}


template<typename T>
void Functions::WriteToFile(const T& ContainerInput)
{
    ofstream WriteBuffer;

    WriteBuffer.open("WriteToFile.txt", ios_base::out);
    if(WriteBuffer.is_open())
    {
        cout << "File open for write success!" << endl;

        OutputContainer(WriteBuffer, ContainerInput);

        WriteBuffer.close();
        cout << "Write buffer closed!" << endl;
    }
    else
        cout << "File open for write fail." << endl;

}

void Functions::ReadFromFile()
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
