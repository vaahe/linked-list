#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <initializer_list>
#include <iostream>

template <class T>
class LinkedList {
private:
    struct Node {
    public:
        Node(T data = T(), Node* next = nullptr, Node* prev = nullptr) :
            m_next(next),
            m_prev(prev),
            m_data(data) {}

        T m_data;
        Node* m_next;
        Node* m_prev;
    };

public:
    class Iterator {
    public:
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;

    public:
        Iterator(Node*);
        reference operator*() const;
        pointer operator->() const;
        Iterator& operator++();
        Iterator& operator++(int);
        Iterator& operator--();
        Iterator& operator--(int);
        bool operator==(const Iterator&) const;
        bool operator!=(const Iterator&) const;

    private:
        Node* m_ptr;
    };

public:
    LinkedList();
    LinkedList(const LinkedList<T>&);
    LinkedList(LinkedList<T>&&);  //move constructor
    LinkedList(const std::initializer_list<T>&);  //parameterized constructor
    ~LinkedList();

public:
    Node* front() const;  //accesses the first element
    Node* back() const;  //accesses the last element
    Iterator begin() const;  //returns an iterator to the beginning
    Iterator end() const;  //returns an iterator to the end
    bool empty() const;  //checks whether a linked list container is empty or not
    int size() const;  //finds the number of elements
    void clear();  //removes all elements
    Node insert(Node*, const T&);  //inserts the elements at any position
    Iterator emplace(Iterator, T&&);  //extends list by inserting new element at a given position
    void push_back(T);  //adds element at the end
    void push_front(T);  //adds element at the beginning
    void resize(int);  //changes size
    void splice(Iterator, LinkedList<T>&);  //transfers elements from one linked list to another
    LinkedList<T>& merge(LinkedList<T>&);  //merges two linked lists into one
    void unique();  //removes duplicate values
    void pop_front();  //removes the first element
    void pop_back();
    friend std::ostream& operator<<(std::ostream&, const LinkedList<T>&);
    LinkedList<T>& operator=(const LinkedList<T>&);  //copy operator assignment
    LinkedList<T>& operator=(LinkedList<T>&&);  //move operator assignment
    LinkedList<T>& operator+(LinkedList<T>&);
    LinkedList<T>& operator+=(const LinkedList<T>&);
    bool operator==(LinkedList<T>&);
    bool operator!=(LinkedList<T>&);
    bool operator<(LinkedList<T>&);
    bool operator<=(LinkedList<T>&);
    bool operator>(LinkedList<T>&);
    bool operator>=(LinkedList<T>&);
    void print();
private:
    Node* m_head;
    Node* m_tail;
    int m_size;

private:
    T sum();
    
};

#include "linked_list.hpp"

#endif //  LINKED_LIST_H
