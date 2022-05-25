#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList() {
	m_head = m_tail = nullptr;
	m_list_size = 0;
}

//copy constructor
LinkedList::LinkedList(const LinkedList& otherList) {
	Node* current = otherList.m_head;
	Node* prev = m_head;
	while (current) {
		prev = new Node(current->m_data, current->m_next, current->m_prev);
		current = current->m_next;
		prev = prev->m_next;
	}
}

LinkedList::~LinkedList() {
	clear();
}

Node* LinkedList::front() {
	return m_head;
}

Node* LinkedList::back() {
	return m_tail;
}

bool LinkedList::empty() {
	if (m_list_size == 0)
		return true;
	else
		return false;
}

int LinkedList::size() {
	return m_list_size;
}

void LinkedList::push_front(int data) {
	Node* new_node = new Node;
	new_node->m_data = data;

	new_node->m_next = m_head;
	new_node->m_prev = nullptr;

	if (m_head != nullptr)
		new_node->m_next->m_prev = new_node;
	else
		m_tail = new_node;

	m_head = new_node;
	++m_list_size;
}

void LinkedList::push_back(int data) {
	Node* new_node = new Node;
	new_node->m_data = data;

	new_node->m_prev = m_tail;
	new_node->m_next = nullptr;

	if (m_tail != nullptr)
		new_node->m_prev->m_next = new_node;
	else
		m_head = new_node;

	m_tail = new_node;
	++m_list_size;
}

void LinkedList::resize(int new_size) {
	if (new_size < m_list_size) {
		while (new_size != m_list_size) {
			pop_back();
		}
	}
	else if (new_size > m_list_size) {
		while (new_size != m_list_size)
			push_back(0);
	}
}

void LinkedList::pop_front() {
	Node* temp = m_head;  //temporary node
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

void LinkedList::pop_back() {
	Node* temp = m_tail;  //temporary node
	if (m_head->m_next != nullptr) {
		m_tail = m_tail->m_prev;
		m_tail->m_next = nullptr;
		delete temp;
	}
	else {
		delete m_head;
		m_tail = m_head = nullptr;
	}

	--m_list_size;
}
/*
void LinkedList::unique() {
	Node* current_node = m_head;
	Node* last_node = m_head;
	if (m_head->m_next == nullptr)
		current_node = nullptr;

	for (;;) {
		current_node = current_node->m_next;
		if (current_node == nullptr) break;

		if (last_node->m_data == current_node->m_data) {
			delete last_node;
		}
		else {
			last_node = last_node->m_next;
		}
	}
}
*/
void LinkedList::clear() {
	while (m_head) {
		Node* temp = m_head;
		m_head = m_head->m_next;
		delete temp;
	}
	m_list_size = 0;
}

void LinkedList::print() {
	if (m_head != nullptr) {
		Node* current = m_head;

		while (current != nullptr) {
			std::cout << current->m_data << std::endl;
			current = current->m_next;
		}
	}
	else
		std::cout << "List is empty!\n";
}

//copy assignment operator
/*
LinkedList& LinkedList::operator=(const LinkedList& otherList) {
	Node* new_node = new Node;
	if (&otherList == this)
		return *this;
	else
		clear();

	new_node = otherList.m_head;

	return otherList;
}
*/

//move operator assignment
/*
LinkedList& LinkedList::operator=(LinkedList&& otherList) {
	if (&otherList == this)
		return *this;

	Node* new_node = new Node;
	new_node = otherList.m_head;

	return otherList;
}
*/

//copy operator assignment
LinkedList& LinkedList::operator=(LinkedList& ohterList) {
	m_head = otherList.m_head;

	if (this == &otherList)
		return *this;

	while (m_head != nullptr) {
		m_head->m_next = otherList.m_head->m_next;
	}

	return *this;
}

LinkedList& LinkedList::operator+(LinkedList& otherList) {

}

bool LinkedList::operator==(LinkedList& otherList) {
	if (m_head == nullptr && otherList.m_head == nullptr)
		return true;

	Node* new_node = otherList.m_head;
	while (new_node != nullptr) {
		if (new_node->m_data != m_head->m_data)
			return false;

		new_node = new_node->m_next;
		m_head = m_head->m_next;
	}
	return true;
}

bool LinkedList::operator!=(LinkedList& otherList) {
	if (m_head == nullptr && otherList.m_head == nullptr)
		return false;

	Node* new_node = otherList.m_head;
	while (new_node != nullptr) {
		if (new_node->m_data == m_head->m_data)
			return false;
		
		new_node = new_node->m_next;
		m_head = m_head->m_next;
	}
	return true;
}

bool LinkedList::operator<(LinkedList& otherList) {
	return this->m_list_size < otherList.m_list_size;
}

bool LinkedList::operator<=(LinkedList& otherList) {
	return this->m_list_size <= otherList.m_list_size;
}

bool LinkedList::operator>(LinkedList& otherList) {
	return this->m_list_size > otherList.m_list_size;
}

bool LinkedList::operator>=(LinkedList& otherList) {
	return this->m_list_size >= otherList.m_list_size;
}



std::ostream& operator<<(std::ostream& out, const LinkedList& otherList) {
	Node* new_node = new Node;
	new_node = otherList.m_head;

	while (new_node != nullptr) {
		out << new_node->m_data << " ";
		new_node = new_node->m_next;
	}

	return out;
}
