#ifndef P_ARRAY_H
#define P_ARRAY_H

#include <iostream>
#include <omp.h>

using namespace std;

// #define dummy -99999

template <typename T>
class pArray
{
    size_t pArraySize;  // size of list
    T *myArray;
    T dummy;
    typedef T temp;
    omp_lock_t arrayLock;
    int thread_num;

public:


/**
Constructor for generic array type T, and size s
*/
    pArray(size_t s, int numThreads)
    {
        // cout<<"Constructor: ";
        pArraySize = s;
        myArray = new T [pArraySize];
        dummy = -99999;
        thread_num = numThreads;
        omp_init_lock(&(arrayLock));
    }


    void acquireLock()
    {
        #pragma omp critical
        {
            omp_set_lock(&(arrayLock));
        }
    }

    void releaseLock()
    {
        omp_unset_lock(&(arrayLock));
    }


/**
Overloading '[]' operator for array element access
*/
    T &operator[] (int index)
    {
        // cout<<"[]. ";
        if(index >= 0 && index < pArraySize)
            return myArray[index];
        else
            return dummy;
    }

/**
Returns array size
*/
    int arraySize()
    {
        return pArraySize;
    }
/**
Returns true if array is empty
*/
    bool isEmpty()
    {
        if(pArraySize == 0) return true;
        return false;
    }
/**
Returns element at the front of the array
*/
    T front()
    {
        if(pArraySize == 0) return dummy;
        return myArray[0];
    }
/**
Returns element at the back of the array
*/
    T back()
    {
        if(pArraySize == 0) return dummy;
        return myArray[pArraySize-1];
    }
/**
Returns element at position 'index' of the array
*/
    T at(int index)
    {
        if(index >= 0 && index < pArraySize)
            return myArray[index];
        else return dummy;
    }

    void fillArray(T element)
    {
        acquireLock();
        #pragma omp parallel for num_threads(thread_num)
        for(int i = 0 ; i < pArraySize ; i++)
            myArray[i] = element;
        releaseLock();
    }



    void reverseArray()
    {
        // cout<<"Reversing array: ";
        int lower = 0;
        int upper = pArraySize - 1;
        acquireLock();
        #pragma omp parallel for num_threads(thread_num)
        for(int i = 0; i < pArraySize/2; i++) //; lower < upper ; lower++, upper--)
        {
            T temp = myArray[i];
            myArray[i] = myArray[pArraySize-i-1];
            myArray[pArraySize-i-1] = temp;
        }
        releaseLock();
    }

    void printArray()
    {
        for(int i = 0 ; i < pArraySize ; i++)
            cout<<myArray[i]<<"  ";
        cout<<endl;
    }



    ~pArray()
    {
        free(myArray);
        // cout<<"Array deleted!"<<endl;
    }

};




#endif /* P_ARRAY_H */
