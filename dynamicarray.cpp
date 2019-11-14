#include <iostream>
#include "dynamicarray.h"
using namespace std;

const int INITIAL_CAP = 10;

//Default constructor, note they do not have a return value
 DynamicArray::DynamicArray()
{
    capacity = INITIAL_CAP; //Setting the capacity of the array equal to our intial capacity variable
    arr = new int[INITIAL_CAP]; //Allocating that many integer memory locations to the array; rememeber: arr is a pointer
    len = 0; //The actual number of elements in the empty array
}

//Destructor
DynamicArray::~DynamicArray()
{
     delete [] arr; //Deletes memory that held array
     arr = NULL; //Good programming practice to set pointer equal to null
}

//Append function. Note if the array is at its maximum capacity then allocate a new array with twice teh capacity, copy over the old elements, delete the old array, and set arr to point to the new array. Then append teh new value tot he array and update the length
void DynamicArray::append(int newVal)
{
     //If our counter for the amount of elements that have been populated (the amount of elements that actually hold values) length reaches the array's full capacity, marked by capacity, we will double the size of our array by copying the original array into an array double the size
     if (len == capacity)
     {
         int *NewArray = new int [capacity * 2];
         for (int i = 0; i < len; i++)
         {
             NewArray[i] = arr[i];
         }
         int *temp = arr;
         arr = NewArray;
         delete[] temp;
         NewArray = nullptr;
         capacity = capacity * 2;
     }
     //Remember that array indexes and counters are not the same
     arr[len] = newVal;
     //Increment your counter
     len = len + 1;
} //End of append function

int DynamicArray::at(int index)
{
     if (index >= len)
     {
         return -11111;
     }
     else
     return arr[index];
}//End of at function

int DynamicArray::sum()
{

     int counter = 0;
     for (int i = 0; i < len; i++)
     {
         counter = arr[i] + counter;
     }
     return counter;
}//End of sum function

bool DynamicArray::remove(int valToDelete)
{
   /*  bool isFound = false;
     int i;
     for (i = 0; i < len; i++)
     {
         if (arr[i] == valToDelete&&!isFound)
         {
             isFound = true;
             for (int j = i; j < len -1; j++)
             {
                 arr[j] = arr[j+1];
             }
             len--;
         }
     }
     if (len < capacity * 0.5)
     {
         capacity = capacity * 0.8;
         if (capacity<INITIAL_CAP)
         {
             capacity = INITIAL_CAP;
         }
         int *NewArray = new int [capacity];
         for (int i = 0; i < len; i++)
         {
             NewArray[i] = arr[i];
         }
         int *temp = arr;
         arr = NewArray;
         delete[] temp;
         NewArray = nullptr;
     }

     return isFound;

    */



     //bool validation;

     for (int i = 0; i < len; i++)
     {
         if (arr[i] == valToDelete)
         {
             for (int j = i; j < len; j++)
             {
                 arr[j] = arr[j+1];
             }
             //update length after overwriting the current index by shifting all indexes to the right of it left
             len = len - 1;
//             cout << endl;
//             cout << "Capacity: " << capacity << endl;
//             cout << "our counter length: " << len << endl;
//             cout << endl;
             if (len < (capacity *.5) )
             {
                 int size = 0;

                 if (capacity * .80 < INITIAL_CAP)
                 {
                     size = INITIAL_CAP;
                     //int *NewArray = new int [INITIAL_CAP];
                 }
                 else
                 {
                 size = capacity * .8;
                 }

                 int *NewArray = new int [size];
                 for (int i = 0; i < len; i++)
                 {
                     NewArray[i] = arr[i];
                 }
                 int *temp = arr;
                 arr = NewArray;
                 delete[] temp;
                 NewArray = nullptr;
                 capacity = size;

             }

             //validation = true;
             return true;
         }

     }
     //validation = false;
    return false;


}//End of remove function

// Print all array elements
void DynamicArray::print()
{
   for (int i = 0; i < len; i++)
   {
      cout << arr[i] << " ";
      if (i % 10 == 9) {
          cout << endl; // newline every 10 elements
      }
   }
   cout << endl;
} //End of print function
