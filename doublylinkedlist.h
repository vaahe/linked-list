#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <initializer_list>
#include <ostream>

template<class T>
class iterator {
    T i;
public:
    explicit iterator(int position = 0) : i(position) {} 
    //keyword 'explicit' is used to mark constructor to not implicitly convert types

    T operator*() const {
        return i;
    }

    iterator& operator++() {
        ++i;
        return *this;
    }

    bool operator!=(const iterator &other) {
        return i != other.i;
    }
};


typedef iterator<DoublyLinkedList*> list_iterator;
typedef iterator<const DoublyLinkedList*> list_const_iterator;


struct Node {
    int data;
    Node* next;
    Node* prev;
};


class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList();  //default constructor
    DoublyLinkedList(const DoublyLinkedList&);  //copy constructor
    DoublyLinkedList(DoublyLinkedList&&);  //move constructor
    DoublyLinkedList(const std::initializer_list<Node>&);  //parameterized constructor
    ~DoublyLinkedList();  //destructor

    void front();  //accesses the first element
    void back();  //accesses the last element

    Node& begin();  //returns an iterator to the beginning
    Node& end();  //returns an iterator to the end
    bool empty();  //checks whether a linked list container is empty or not
    int size();  //finds the number of elements
    void clear();  //removes all elements
    list_iterator insert(list_iterator, int);  //inserts the elements at any position
    list_iterator emplace(list_iterator, int);  //extends list by inserting new element at a given position
    void push_back(Node&);  //adds element at the end
    void push_front(Node&);  //adds element at the beginning
    void resize(int);  //changes size
    void splice(list_iterator, DoublyLinkedList&);  //transfers elements from one linked list to another
    void merge(DoublyLinkedList& list);  //merges two linked lists into one
    bool remove_if(bool);  //removes elements fulfilling condition
    void unique();  //removes duplicate values

    friend std::ostream& operator<<(std::ostream&, const DoublyLinkedList&);
    bool operator==(DoublyLinkedList&);
    bool operator!=(DoublyLinkedList&);
    DoublyLinkedList& operator=(const DoublyLinkedList&);  //copy operator assignment
    DoublyLinkedList& operator=(DoublyLinkedList&&);  //move operator assignment
    DoublyLinkedList& operator+(DoublyLinkedList&);
    DoublyLinkedList& operator+=(const DoublyLinkedList&);
    DoublyLinkedList& operator<(const DoublyLinkedList&);
    DoublyLinkedList& operator<=(const DoublyLinkedList&);
    DoublyLinkedList& operator>(const DoublyLinkedList&);
    DoublyLinkedList& operator>=(const DoublyLinkedList&);
};

#endif // !DOUBLYLINKEDLIST_H