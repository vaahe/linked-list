#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <initializer_list>
#include <iostream>
#include <utility>

template <class T>
class LinkedList {
public:
    template <typename>
    class Iterator {
    public:
        explicit Iterator(T* ptr) : m_ptr(ptr) {}
        //keyword 'explicit' is used to mark constructor to not implicitly convert types

        T& operator*() const {
            return *m_ptr;
        }

        T* operator->() const {
            return m_ptr;
        }

        Iterator<T>& operator++()
        {
            ++m_ptr;
            return *this;
        }

        Iterator<T>& operator++(T) {
            Iterator<T> tmp = *this;
            ++(*this);
            return tmp;
        }

        Iterator<T>& operator--() {
            --m_ptr;
            return *this;
        }

        Iterator<T>& operator--(T) {
            Iterator<T> tmp = *this;
            --(*this);
            return tmp;
        }

        bool operator==(const Iterator<T>& other) {
            return m_ptr == other.m_ptr;
        }

        bool operator!=(const Iterator<T>& other)
        {
            return m_ptr != other.m_ptr;
        }
    private:
        T* m_ptr;
    };
private:
    template <typename>
    struct Node {
    public:
        Node(T data = T(), Node<T>* next = nullptr, Node<T>* prev = nullptr) {
            m_data = data;
            m_next = next;
            m_prev = prev;
        }

        T m_data;
        Node<T>* m_next;
        Node<T>* m_prev;
    };

public:
    LinkedList();
    LinkedList(const LinkedList<T>&);
    LinkedList(LinkedList<T>&&);  //move constructor
    LinkedList(const std::initializer_list<T>&);  //parameterized constructor
    ~LinkedList();

public:
    Node<T>* front();  //accesses the first element
    Node<T>* back();  //accesses the last element
    Iterator<T> begin();  //returns an iterator to the beginning
    Iterator<T> end();  //returns an iterator to the end
    bool empty() const;  //checks whether a linked list container is empty or not
    int size() const;  //finds the number of elements
    void clear();  //removes all elements
    LinkedList<T>::Node<T> insert(Node<T>*, const T&);  //inserts the elements at any position
    LinkedList<T>::Iterator<T> emplace(Iterator<T>, T&&);  //extends list by inserting new element at a given position
    void push_back(T);  //adds element at the end
    void push_front(T);  //adds element at the beginning
    void resize(int);  //changes size
    void splice(Iterator<T>, LinkedList<T>&);  //transfers elements from one linked list to another
    LinkedList<T>& merge(LinkedList<T>&);  //merges two linked lists into one
    //Iterator remove_if(Iterator, Iterator, bool);  //removes elements fulfilling condition
    void unique();  //removes duplicate values
    void pop_front();  //removes the first element
    void pop_back();
    void print();
    friend std::ostream& operator<<(std::ostream&, const LinkedList<T>&);
    bool operator==(const LinkedList<T>&);
    bool operator!=(const LinkedList<T>&);
    LinkedList<T>& operator=(const LinkedList<T>&);  //copy operator assignment
    LinkedList<T>& operator=(LinkedList<T>&&);  //move operator assignment
    LinkedList<T>& operator+(LinkedList<T>&);
    LinkedList<T>& operator+=(const LinkedList<T>&);
    bool operator<(const LinkedList<T>&);
    bool operator<=(const LinkedList<T>&);
    bool operator>(const LinkedList<T>&);
    bool operator>=(const LinkedList<T>&);

private:
    Node<T>* m_head;
    Node<T>* m_tail;
    int m_size;
};

#include "linked_list.hpp"

#endif //  LINKED_LIST_H