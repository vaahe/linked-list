#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <initializer_list>
#include <ostream>


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

        Iterator<T>& operator--() {
            --m_ptr;
            return *this;
        }

        bool operator==(const Iterator<T>& other) {
            return this->m_ptr == other.m_ptr;
        }

        bool operator!=(const Iterator<T>& other)
        {
            return this->m_ptr != other.m_ptr;
        }
    private:
        T* m_ptr;
    };
private:
    template <typename>
    struct Node {
    public:
        Node(T data = T(), Node<T>* next = nullptr, Node<T>* prev = nullptr) {
            this->m_data = data;
            this->m_next = next;
            this->m_prev = prev;
        }

        T m_data;
        Node<T>* m_next;
        Node<T>* m_prev;
    };

public:
    LinkedList();
    LinkedList(int);
    LinkedList(const LinkedList<T>&);
    LinkedList(LinkedList<T>&&);  //move constructor
    LinkedList(const std::initializer_list<T>&);  //parameterized constructor
    ~LinkedList();

public:
    Node<T>* front();  //accesses the first element
    Node<T>* back();  //accesses the last element
    Iterator<T> begin();  //returns an iterator to the beginning
    Iterator<T> end();  //returns an iterator to the end
    bool empty();  //checks whether a linked list container is empty or not
    int size();  //finds the number of elements
    void clear();  //removes all elements
    void insert(T, int);  //inserts the elements at any position
    Iterator<T> emplace(Iterator<T>, T);  //extends list by inserting new element at a given position
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
    bool operator==(LinkedList<T>&);
    bool operator!=(LinkedList<T>&);
    LinkedList<T>& operator=(LinkedList<T>&);  //copy operator assignment
    LinkedList<T>& operator=(LinkedList<T>&&);  //move operator assignment
    LinkedList<T>& operator+(LinkedList<T>&);
    LinkedList<T>& operator+=(LinkedList<T>&);
    T& operator[](int);
    bool operator<(LinkedList<T>&);
    bool operator<=(LinkedList<T>&);
    bool operator>(LinkedList<T>&);
    bool operator>=(LinkedList<T>&);

private:
    Node<T>* m_head;
    Node<T>* m_tail;
    int m_list_size;
};

#endif // !LINKED_LIST_H
