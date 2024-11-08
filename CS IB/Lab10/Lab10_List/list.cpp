// functions to manipulate list
// Mikhail Nesterenko
// 11/2/2020

#include <iostream>

// prints the values in array "colPtr" of "size"
void output(double *colPtr, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << colPtr[i] << " ";
    std::cout << std::endl;
}

// returns the index of the element in array "colPtr" of "size"
// that corresponds to the element holding "number"
// if number is not in the array, returns -1
int check(double *colPtr, double number, int size)
{
    for (int i = 0; i < size; i++)
        if (colPtr[i] == number)
            return i;
    return -1;
}

// adds "number" to the array pointed to by "colPtr" of "size".
// if the number is not already there, if "number" is there - no action
// Note, the size of the array is thus increased.
void addNumber(double *&colPtr, double number, int &size)
{
    int index = check(colPtr, number, size);
    if (index != -1)
    {
        std::cout << "duplicate!" << std::endl;
        return;
    }
    double *newArray = new double[size + 1];
    for (int i = 0; i < size; i++)
        newArray[i] = colPtr[i];
    newArray[size] = number;
    delete[] colPtr;
    colPtr = newArray;
    ++size;
}

// removes a "number" from array "colPtr" of "size".
// if "number" is not there -- no action
// note, "size" changes
void removeNumber(double *&colPtr, double number, int &size)
{
    int index = check(colPtr, number, size);
    double *newArray = new double[size - 1];
    if (index == -1)
    {
        std::cout << "not present!" << std::endl;
        return;
    }
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (colPtr[i] == number)
            found = true;

        else
        {
            if (!found)
                newArray[i] = colPtr[i];
            else
                newArray[i - 1] = colPtr[i];
        }
    }
    delete[] colPtr;
    colPtr = newArray;
    size--;
}
