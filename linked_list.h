#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <initializer_list>
#include <ostream>

template<class T>
class iterator
{
    T i;
public:
    explicit iterator(int position = 0) : i(position) {}
    //keyword 'explicit' is used to mark constructor to not implicitly convert types

    T operator*() const
    {
        return i;
    }

    iterator& operator++()
    {
        ++i;
        return *this;
    }

    bool operator!=(const iterator& other)
    {
        return i != other.i;
    }
};


//typedef iterator<LinkedList*> list_iterator;
//typedef iterator<const LinkedList*> list_const_iterator;


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


class LinkedList {
public:
    LinkedList();  //default constructor
    //LinkedList(const LinkedList&);  //copy constructor
    //LinkedList(LinkedList&);  //move constructor
    //LinkedList(const std::initializer_list<Node>&);  //parameterized constructor
    ~LinkedList();  //destructor

public:
    Node* front();  //accesses the first element
    Node* back();  //accesses the last element
    //Node& begin();  //returns an iterator to the beginning
    //Node& end();  //returns an iterator to the end
    bool empty();  //checks whether a linked list container is empty or not
    int size();  //finds the number of elements
    void clear();  //removes all elements
    //list_iterator insert(list_iterator, int);  //inserts the elements at any position
    //list_iterator emplace(list_iterator, int);  //extends list by inserting new element at a given position
    void push_back(int);  //adds element at the end
    void push_front(int);  //adds element at the beginning
    void resize(int);  //changes size
    //void splice(list_iterator, LinkedList&);  //transfers elements from one linked list to another
    //void merge(LinkedList& list);  //merges two linked lists into one
    //bool remove_if(bool);  //removes elements fulfilling condition
    void unique();  //removes duplicate values
    void pop_front();  //removes the first element
    void pop_back();
    void print();
    //std::ostream& operator<<(std::ostream&, const LinkedList&);
    //bool operator==(LinkedList&);
    //bool operator!=(LinkedList&);
    //LinkedList& operator=(const LinkedList&);  //copy operator assignment
    //LinkedList& operator=(LinkedList&);  //move operator assignment
    //LinkedList& operator+(LinkedList&);
    //LinkedList& operator+=(const LinkedList&);
    //LinkedList& operator<(const LinkedList&);
    //LinkedList& operator<=(const LinkedList&);
    //LinkedList& operator>(const LinkedList&);
    //LinkedList& operator>=(const LinkedList&);

private:
    Node* m_head;
    Node* m_tail;
    int m_list_size;
};

#endif // !LINKED_LIST_H
