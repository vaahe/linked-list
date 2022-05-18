#include "doublylinkedlist.h"

DoublyLinkedList::DoublyLinkedList() 
{
	head = tail = nullptr;
	list_size = 0;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& otherList) 
{
	
}

DoublyLinkedList::~DoublyLinkedList()
{
	clear();
}

void DoublyLinkedList::front() {

}

void DoublyLinkedList::back() {

}

void DoublyLinkedList::push_front(Node& node)
{
	Node* new_node = new Node(node);
	new_node->data = node.data;

	if (head != nullptr)
	{
		head = new_node;
		head->next = tail;
		head->prev = nullptr;
	}

	else
	{
		new_node->prev = nullptr;
		new_node->next = head;
		head->prev = new_node;
	}

	++list_size;
}

void DoublyLinkedList::pop_front()
{
	Node* temp = head;
	if (head->next != nullptr)
	{
		head = head->next;
		head->prev = nullptr;
		delete temp;
	}

	else
	{
		delete tail;
		head = tail = nullptr;
	}

	--list_size;
}

void DoublyLinkedList::clear()
{
	while (head)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}  
	
	/*
	while(list_size) {
		clear();
	}
	*/
}