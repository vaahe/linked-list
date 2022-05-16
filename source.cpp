#include <iostream>

typedef DoublyLinkedList * iterator;
typedef const DoublyLinkedList * const_iterator;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    Node* head;

    public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList &obj);
    ~DoublyLinkedList();

    void front();
    void back();

    iterator begin();
    iterator end();
    bool empty();
    int size();
    void clear();
    void insert();
    iterator emplace();
    
};