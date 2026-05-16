#include <iostream>

#include "list.hpp"

template <typename T>
class Collection;

template <typename T>
auto equal(const Collection<T>& lhs, const Collection<T>& rhs) -> bool;

template <typename T>
class Collection {
   private:
    node<T>* head;

   public:
    Collection();

    Collection(const Collection& other);
    auto operator=(const Collection& other) -> Collection&;
    ~Collection();

    auto add(const T& item) -> void;
    auto remove(const T& item) -> void;
    auto last() const -> T;
    auto print() const -> void;

    friend auto equal<T>(const Collection<T>& lhs, const Collection<T>& rhs)
        -> bool;
};

template <typename T>
Collection<T>::Collection() : head(nullptr) {}

template <typename T>
Collection<T>::Collection(const Collection& other) : head(nullptr) {
    node<T>* current = other.head;
    while (current != nullptr) {
        add(current->getData());
        current = current->getNext();
    }
}

template <typename T>
auto Collection<T>::operator=(const Collection& other) -> Collection<T>& {
    if (this != &other) {
        while (head != nullptr) {
            node<T>* temp = head;
            head = head->getNext();
            delete temp;
        }

        node<T>* current = other.head;
        while (current != nullptr) {
            add(current->getData());
            current = current->getNext();
        }
    }
    return *this;
}

template <typename T>
Collection<T>::~Collection() {
    while (head != nullptr) {
        node<T>* temp = head;
        head = head->getNext();
        delete temp;
    }
}

template <typename T>
auto Collection<T>::add(const T& item) -> void {
    node<T>* newNode = new node<T>();
    newNode->setData(item);
    if (head == nullptr)
        head = newNode;
    else {
        node<T>* current = head;
        while (current->getNext() != nullptr) current = current->getNext();
        current->setNext(newNode);
    }
}

template <typename T>
auto Collection<T>::remove(const T& item) -> void {
    node<T>* current = head;
    node<T>* prev = nullptr;

    while (current != nullptr) {
        if (current->getData() == item) {
            if (prev == nullptr)
                head = current->getNext();
            else
                prev->setNext(current->getNext());
            node<T>* temp = current;
            current = current->getNext();
            delete temp;
        } else {
            prev = current;
            current = current->getNext();
        }
    }
}

template <typename T>
auto Collection<T>::last() const -> T {
    // technically we should handle what to do if the collection is empty and thow an error, but I'm not going to do that.
    node<T>* current = head;
    while (current->getNext() != nullptr) current = current->getNext();
    return current->getData();
}

template <typename T>
auto Collection<T>::print() const -> void {
    node<T>* current = head;
    while (current != nullptr) {
        if (current->getNext() != nullptr)
            std::cout << current->getData() << "------->";
        else
            std::cout << current->getData();
        current = current->getNext();
    }
    std::cout << std::endl;
}
template <typename T>
auto equal(const Collection<T>& lhs, const Collection<T>& rhs) -> bool {
    auto left = lhs.head;
    auto right = rhs.head;

    while (left != nullptr && right != nullptr) {
        if (left->getData() != right->getData()) return false;
        left = left->getNext();
        right = right->getNext();
    }

    return left == nullptr && right == nullptr;
}
