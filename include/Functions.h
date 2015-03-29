#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

using std::ostream;


namespace Functions
{
    template<typename T>
    class SortOnSalary
    {
        public:
            bool operator() (const T& pLeft_object, const T& pRight_object);
    };


    template<typename T>
    void DeleteObjectsBeforeExit (T& ContainerInput);


    template<typename T>
    void OutputContainer (ostream& os, const T& ContainerInput);


    template<typename T>
    void PopulateContainer(T& ContainerInput);


    template<typename T>
    void DisplayFirst5names(const T& ContainerInput);


    template<typename T>
    void DisplayLast3IDs(const T& ContainerInput);


    template<typename T>
    void WriteToFile(const T& ContainerInput);


    void ReadFromFile();

}

//TEMPLATE FUNCTION IMPLEMENTATIONS MUST RESIDE IN THE SAME HEADER
#include "Functions_impl.h"

#endif // FUNCTIONS_H
