// Chad Cooper
// Anna McMaster
// Ryan Gray

#ifndef Sorting_hpp
#define Sorting_hpp


#include <stdio.h>
#include <iostream>
using namespace std;


template <typename T>
class Sorting {

public:
    
    void selectionsort(T* data, int size);
    
    void quicksort(T* data, int low, int high);
    
    void insertionsort(T* data, int size);
    
    
    
    
    /********************** Auxiliary Functions *********************/
    
    
    // Takes the indices of the first and last elements in the array,
    // and returns the index of the median
    int medianOf3(T* data, int left, int right);
    
    // Swaps the values in an array at indices a and b.
    void swapLocations(T* data, int a, int b);
    
    void printArray();
    
};

template <typename T>
void Sorting<T>::selectionsort(T* data, int size) {
    
    int current, next, min;
    
    //"current" sets the index where the unsorted array begins
    //for indexes < current, they are sorted
    
    for (current = 0; current < size - 1; current++) {
        
        //find the minimum element in unsorted array
        min = current;
        for (next = current + 1; next < size; next++) {
            if (data[next] < data[min])
                min = next;
        }
        //swap the found min with the first unsorted element
        swapLocations(data, current, min);
    }
}

template <typename T>
void Sorting<T>::quicksort(T* data, int low, int high){
    
    int pivot, pivot_index, i = low, j = high - 1;
    
    if(low >= high){
        return;
    }
    
    pivot_index = medianOf3(data, low, high);
    pivot = data[pivot_index];
    
    if((high - low) <= 2){ // if sub-array is size 3 or less, median of 3 sorts it
        return;
    }
    
    for(;;){
        while(data[++i] < pivot) // traverse until data[i] > pivot
        { /* Do nothing */ }
        while(pivot < data[--j]) // traverse until data[j] < pivot
        { /* Do nothing */ }
        if(i < j) // i and j have not crossed over yet
        {
            swapLocations(data, i, j);
        }
        else
            break;
        
    }
    
    swapLocations(data, i, high - 1); // Swap the pivot into position i.
    
    quicksort(data, low, i-1); // Sort from 0 to left of the pivot
    quicksort(data, i+1, high); // Sort from pivot + 1 to the end.
}


template <typename T>
int Sorting<T>::medianOf3(T* arr, int left, int right){
    int center = (left + right)/2;
    
    if(arr[center] < arr[left])
        swapLocations(arr, center, left);
    if(arr[right] < arr[left])
        swapLocations(arr, right, left);
    if(arr[right] < arr[center])
        swapLocations(arr, right, center);
    
    swapLocations(arr, center, right-1);
    return right-1;
}

template <typename T>
void Sorting<T>::swapLocations(T* arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

template <typename T>
void Sorting<T>::insertionsort(T* data, int size) {
    int tempValue;
    int currentValue;
    int i;
    
    //starting at the second element of the array initially
    //comparing with the previous value (tempvalue - 1), and
    //going through the entire array
    for (i = 1; i < size; i++) {
        
        //setting values for 2nd value initially, then using them to compare
        currentValue = data[i];
        tempValue = i - 1;
        
        //if the previous value is greater than the current one
        //move it to current value's place and update the previous/temp value position
        while (tempValue >= 0 && (data[tempValue] > currentValue)) {
            
            data[tempValue + 1] = data[tempValue];
            tempValue = tempValue - 1;
        }
        //if the values don't go through the while, it goes to next element/i in the for loop
    }
}



#endif /* Sorting_hpp */
