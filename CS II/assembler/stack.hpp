//
// File: stack.hpp
//
// Programmer:
// Date:        Spring 2025
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//
#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_

#include <new>
#include <cassert>
#include "../string/string.hpp"

template<typename T> 
class Node {
public:
    Node() : next(nullptr) {}
    Node(const T& item) : data(item), next(nullptr) {}
    T data;
    Node<T>* next;
};

// CLASS INV: Stack implemented as a singly linked list.
// The top of stack (tos) points to the first node in the list.
// An empty stack is represented by a nullptr tos.
template <typename T>
class stack {
public:
    stack() : tos(nullptr) {}
    
    stack(const stack<T>& other) : tos(nullptr) {
        if (other.tos == nullptr) return;
        
        tos = new Node<T>(other.tos->data);
        Node<T>* current = tos;
        Node<T>* otherCurrent = other.tos->next;
        
        while (otherCurrent != nullptr) {
            current->next = new Node<T>(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }
    
    ~stack() {
        while (!empty()) {
            pop();
        }
    }
    
    void swap(stack<T>& rhs) {
        Node<T>* temp = tos;
        tos = rhs.tos;
        rhs.tos = temp;
    }
    
    stack<T>& operator=(stack<T> rhs) {
        swap(rhs);
        return *this;
    }
    
    bool empty() const { return tos == nullptr; }
    bool full() const {   
        Node<T> *temp = new (std::nothrow) Node<T>();
        if (temp == 0)
          return true;
        delete temp;
        return false;
      } 

    T top() const {
        assert(!empty());
        return tos->data;
    }
    
    T pop() {
        assert(!empty());
        T result = tos->data;
        Node<T>* temp = tos;
        tos = tos->next;
        delete temp;
        return result;
    }
    
    void push(const T& item) {
        Node<T>* newNode = new Node<T>(item);
        newNode->next = tos;
        tos = newNode;
    }

private:
    Node<T>* tos;
};

#endif