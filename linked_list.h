#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <initializer_list>
#include <ostream>

class Iterator {
public:
    explicit Iterator(int* ptr) : m_ptr(ptr) {}
    //keyword 'explicit' is used to mark constructor to not implicitly convert types

    int& operator*() const {
        return *m_ptr;
    }

    int* operator->() const {
        return m_ptr;
    }

    Iterator& operator++()
    {
        ++m_ptr;
        return *this;
    }

    Iterator& operator--() {
        --m_ptr;
        return *this;
    }

    bool operator==(const Iterator& other) {
        return this->m_ptr == other.m_ptr;
    }

    bool operator!=(const Iterator& other)
    {
        return this->m_ptr != other.m_ptr;
    }
private:
    int* m_ptr;
};


class LinkedList {
private:
    struct Node {
    public:
        Node(int data = 0, Node* next = nullptr, Node* prev = nullptr) {
            this->m_data = data;
            this->m_next = next;
            this->m_prev = prev;
        }

        int m_data;
        Node* m_next;
        Node* m_prev;
    };

public:
    LinkedList();
    LinkedList(const LinkedList&);
    //LinkedList(LinkedList&&);  //move constructor
    LinkedList(const std::initializer_list<Node>&);  //parameterized constructor
    ~LinkedList();

public:
    Node* front();  //accesses the first element
    Node* back();  //accesses the last element
    Iterator begin();  //returns an iterator to the beginning
    Iterator end();  //returns an iterator to the end
    bool empty();  //checks whether a linked list container is empty or not
    int size();  //finds the number of elements
    void clear();  //removes all elements
    //Iterator insert(Iterator, int);  //inserts the elements at any position
    //Iterator emplace(Iterator, int);  //extends list by inserting new element at a given position
    void push_back(int);  //adds element at the end
    void push_front(int);  //adds element at the beginning
    void resize(int);  //changes size
    //void splice(Iterator, LinkedList&);  //transfers elements from one linked list to another
    //void merge(LinkedList& list);  //merges two linked lists into one
    //bool remove_if(Iterator, Iterator, bool);  //removes elements fulfilling condition
    void unique();  //removes duplicate values
    void pop_front();  //removes the first element
    void pop_back();
    void print();
    friend std::ostream& operator<<(std::ostream&, const LinkedList&);
    bool operator==(LinkedList&);
    bool operator!=(LinkedList&);
    LinkedList& operator=(LinkedList&);  //copy operator assignment
    LinkedList& operator=(LinkedList&&);  //move operator assignment
    LinkedList& operator+(LinkedList&);
    LinkedList& operator+=(LinkedList&);
    int operator[](int);
    bool operator<(LinkedList&);
    bool operator<=(LinkedList&);
    bool operator>(LinkedList&);
    bool operator>=(LinkedList&);

private:
    Node* m_head;
    Node* m_tail;
    int m_list_size;
};

#endif // !LINKED_LIST_H
