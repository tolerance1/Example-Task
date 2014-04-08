#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace Functions
{

template<typename T>
class SortOnName
{
    public:
        bool operator() (const T& pLeft_object, const T& pRight_object);
};


template<typename T>
void DeleteObjectsBeforeExit (T& ContainerInput);


template<typename T>
void DisplayContainer (const T& ContainerInput);


template<typename T>
void PopulateContainer(T& ContainerInput);


template<typename T>
void DisplayFirst5Names(T& ContainerInput);


template<typename T>
void DisplayLast3IDs(T& ContainerInput);


template<typename T>
void WriteToFile(const T& ContainerInput);


template<typename T>
void ReadFromFile(const T& ContainerInput);


}

//TEMPLATE FUNCTION IMPLEMENTATIONS MUST RESIDE IN THE SAME HEADER
#include "Functions_impl.h"

#endif // FUNCTIONS_H
