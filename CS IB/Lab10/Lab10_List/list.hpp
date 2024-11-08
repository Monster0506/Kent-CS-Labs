// functions to manipulate list
// Mikhail Nesterenko
// 11/2/2020

#ifndef LIST_HPP
#define LIST_HPP

// prints the values in array "colPtr" of "size" 
void output(double *colPtr, int size);

// returns the index of the element in array "colPtr" of "size"
// that corresponds to the element holding "number"
// if number is not in the array, returns -1
int check(double *colPtr, double number, int size);

// adds "number" to the array pointed to by "colPtr" of "size". 
// if the number is not already there, if "number" is there - no action
// Note, the size of the array is thus increased. 
void addNumber(double *& colPtr, double number, int &size);

// removes a "number" from array "colPtr" of "size".
// if "number" is not there -- no action
// note, "size" changes
void removeNumber(double *& colPtr, double number, int &size);

#endif // LIST_HPP