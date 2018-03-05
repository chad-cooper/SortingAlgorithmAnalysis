#include <iostream>
#include <time.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "Sorting.hpp"
//create sorted data for type T
template<class T>
void CreateSortedData(T* data, unsigned size);
//create constant data of type T
template<class T>
void CreateConstantData(T *data, unsigned size);
//create random data of type T
template<class T>
void CreateRandomData(T *data, unsigned size);
//helper function for creating data
template<class T>
bool CreateData(T* data, char* type, unsigned size);
//function to check if data is sorted after running algorithm
template<class T>
bool IsSorted(T* data, unsigned size);

int main(int argc, char *argv[])
{
    //check number of params
    if (argc != 4)
    {
        std::cout << "Usage: Sorting <sort> <size> <type of data>" << std::endl;
        return 1;
    }
    
    //create sorted, constant, or random data based on parameters
    unsigned size = atoi(argv[2]);
    int *data = new int[size];
    if (!CreateData<int>(data, argv[3], size))
    {
        return 1;
    }
    
    //start clock for timing
    std::clock_t begin = std::clock();
    //create Sorting object and call correct sort
    Sorting<int>sorting;
    if (strcmp(argv[1], "q") == 0)
    {
        sorting.quicksort(data, 0, size - 1);
    }
    else if (strcmp(argv[1], "s") == 0)
    {
        sorting.selectionsort(data, size);
    }
    else if (strcmp(argv[1], "i") == 0)
    {
        sorting.insertionsort(data, size);
    }
    else
    {
        std::cerr << "Incorrect sorting algorithm specified." << std::endl;
        return 1;
    }
    //end clock for timing
    std::clock_t end = std::clock();
    std::cout << "It took " << static_cast<double>((end - begin) / (double)CLOCKS_PER_SEC) << " seconds to sort the data." << std::endl;
    
    //check to see if data is sorted
    if (!IsSorted<int>(data, size))
    {
        std::cout << "Data not correctly sorted after running algorithm." << std::endl;
    }
    else
    {
        std::cout << "Data correctly sorted after running algorithm." << std::endl;
    }
    return 0;
}
template<class T>
bool CreateData(T* data, char* type, unsigned size)
{
    if (strcmp(type, "s") == 0)
    {
        CreateSortedData(data, size);
    }
    else if (strcmp(type, "r") == 0)
    {
        CreateRandomData(data, size);
    }
    else if (strcmp(type, "c") == 0)
    {
        CreateConstantData(data, size);
    }
    else
    {
        std::cerr << "Incorrect type specified." << std::endl;
        return false;
    }
    return true;
}
//we are assuming that data is already allocated in main for each of the following functions
template<class T>
void CreateSortedData(T *data, unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        data[i] = i;
    }
}
template<class T>
void CreateRandomData(T *data, unsigned size)
{
    srand(static_cast<unsigned>(time(NULL)));
    for (unsigned i = 0; i < size; ++i)
    {
        data[i] = rand() % size + 1;
    }
}
template<class T>
void CreateConstantData(T *data, unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        data[i] = 1;
    }
}
template<class T>
bool IsSorted(T* data, unsigned size)
{
    for (unsigned i = 0; i < size - 1; ++i)
    {
        if (data[i] > data[i + 1])
        {
            return false;
        }
    }
    return true;
}
