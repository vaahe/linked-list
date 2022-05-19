#include "doublylinkedlist.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() {
	m_head = m_tail = nullptr;
	m_list_size = 0;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& otherList) {
	
}

DoublyLinkedList::~DoublyLinkedList() {
	clear();
}

bool DoublyLinkedList::empty() {
	if (m_list_size == 0) return true;
	else return false;
}

int DoublyLinkedList::size() {
	return m_list_size;
}

void DoublyLinkedList::push_front(Node& node) {
	Node* new_node = new Node(node);
	new_node->m_data = node.m_data;

	if (m_head != nullptr) {
		m_head = new_node;
		m_head->m_next = m_tail;
		m_head->m_prev = nullptr;
	}
	else {
		new_node->m_prev = nullptr;
		new_node->m_next = m_head;
		m_head->m_prev = new_node;
	}

	++m_list_size;
}

void DoublyLinkedList::pop_front() {
	Node* temp = m_head;
	if (m_head->m_next != nullptr) {
		m_head = m_head->m_next;
		m_head->m_prev = nullptr;
		delete temp;
	}
	else {
		delete m_tail;
		m_head = m_tail = nullptr;
	}

	--m_list_size;
}

void DoublyLinkedList::clear() {
	while (m_head) {
		Node* temp = m_head;
		m_head = m_head->m_next;
		delete temp;
	}  
	
	/*
	while(list_size) {
		clear();
	}
	*/
}

void DoublyLinkedList::print() {
	std::cout<<this->m_list_size;
}