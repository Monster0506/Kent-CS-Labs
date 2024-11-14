#include "list.hpp"
#include <iostream>
List::List()
{
    size_ = 0;
    list_ = new double[size_];
}

int List::check(double num)
{
    for (int i = 0; i < size_; i++)
        if (list_[i] == num)
            return i;
    return -1;
}

void List::addNumber(double num)
{
    int index = check(num);
    if (index != -1)
    {
        std::cout << "duplicate!" << std::endl;
        return;
    }
    double *newArray = new double[size_ + 1];
    for (int i = 0; i < size_; i++)
        newArray[i] = list_[i];
    newArray[size_] = num;
    delete[] list_;
    list_ = newArray;
    ++size_;
}

void List::removeNumber(double num)
{
    int index = check(num);
    double *newArray = new double[size_ - 1];
    if (index == -1)
    {
        std::cout << "not present!" << std::endl;
        return;
    }
    bool found = false;
    for (int i = 0; i < size_; i++)
    {
        if (list_[i] == num)
            found = true;

        else
        {
            if (!found)
                newArray[i] = list_[i];
            else
                newArray[i - 1] = list_[i];
        }
    }
    delete[] list_;
    list_ = newArray;
    size_--;
}

void List::output()
{
    for (int i = 0; i < size_; i++)
        std::cout << list_[i] << " ";
    std::cout << std::endl;
}

List::List(const List &l)
{
    size_ = l.size_;
    delete[] list_;
    list_ = new double[size_];
    for (int i = 0; i < size_; i++)
    {
        list_[i] = l.list_[i];
    }
}

List& List::operator=(const List& l)
{
    if (this == &l)
    {
        return *this;
    }
    delete[] list_;
    size_ = l.size_;

    list_ = new double[size_];
    for (int i = 0; i < size_; i++)
    {
        list_[i] = l.list_[i];
    }
    return *this;

} // overloaded assignment
List::~List()
{
    delete[] list_;
} // destructor