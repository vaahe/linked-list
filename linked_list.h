#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <initializer_list>
#include <iostream>

template <class T>
class LinkedList;

template <class T>
std::ostream& operator<<(std::ostream&, LinkedList<T>&);

template <class T>
class LinkedList {
public:
    class Iterator {
    public:
        using value_type = T;
        using reference = T&;
        using pointer = T*;

    public:
        Iterator(Node*);
        T& operator*() const;
        Node* operator->() const;
        Iterator& operator++();
        Iterator& operator++(int);
        Iterator& operator--();
        Iterator& operator--(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;

    private:
        Node* m_ptr;
    };

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
    LinkedList();
    LinkedList(const LinkedList<T>&);
    LinkedList(LinkedList<T>&&);  //move constructor
    LinkedList(const std::initializer_list<T>&);  //parameterized constructor
    ~LinkedList();

public:
    Node* front();  //accesses the first element
    Node* back();  //accesses the last element
    Iterator begin();  //returns an iterator to the beginning
    Iterator end();  //returns an iterator to the end
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
    template<typename>
    friend std::ostream& operator<<(std::ostream&, LinkedList<T>&);
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

private:
    Node* m_head;
    Node* m_tail;
    int m_size;

private:
    T sum();
    void print();
};

#include "linked_list.hpp"

#endif //  LINKED_LIST_H
