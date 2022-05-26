#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList() {
	m_head = nullptr;
	m_tail = nullptr;
	m_list_size = 0;
}

LinkedList::LinkedList(const LinkedList& other_list) {
	Node* tmp = other_list.m_head;
	Node* prev = m_head;
	while (tmp) {
		prev = new Node(tmp->m_data, tmp->m_next, tmp->m_prev);
		tmp = current->m_next;
		prev = prev->m_next;
	}
}

LinkedList::~LinkedList() {
	while (m_head) {
		Node* temp = m_head;
		m_head = m_head->m_next;
		delete temp;
	}
	m_list_size = 0;
}

Node* LinkedList::front() {
	return m_head;
}

Node* LinkedList::back() {
	return m_tail;
}

bool LinkedList::empty() {
	if (m_list_size == 0) {
		return true;
	}
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

	if (m_head != nullptr) {
		new_node->m_next->m_prev = new_node;
	}
	else {
		m_tail = new_node;
	}

	m_head = new_node;
	++m_list_size;
}

void LinkedList::push_back(int data) {
	Node* new_node = new Node;
	new_node->m_data = data;

	new_node->m_prev = m_tail;
	new_node->m_next = nullptr;

	if (m_tail != nullptr) {
		new_node->m_prev->m_next = new_node;
	}
	else {
		m_head = new_node;
	}

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
		while (new_size != m_list_size) {
			push_back(0);
		}
	}
	else {
		return;
	}

	m_list_size = new_size;
}

void LinkedList::pop_front() {
	Node* tmp = m_head;
	if (m_head->m_next != nullptr) {
		m_head = m_head->m_next;
		m_head->m_prev = nullptr;
		delete tmp;
	}
	else {
		delete m_tail;
		m_head = nullptr;
		m_tail = nullptr;
	}

	--m_list_size;
}

void LinkedList::pop_back() {
	Node* tmp = m_tail;
	if (m_head->m_next != nullptr) {
		m_tail = m_tail->m_prev;
		m_tail->m_next = nullptr;
		delete tmp;
	}
	else {
		delete m_head;
		m_tail = nullptr;
		m_head = nullptr;
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
		Node* tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
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
	else {
		std::cout << "List is empty!\n";
	}
}

//copy assignment operator
/*
LinkedList& LinkedList::operator=(LinkedList& other_list) {
	if (&other_list == this)
		return *this;
	else
		clear();

	return *this;
}
*/

//move operator assignment
LinkedList& LinkedList::operator=(LinkedList&& other_list) {
	if (&other_list == this) {
		return *this;
	}

	Node* new_node = new Node;
	new_node = other_list.m_head;

	return other_list;
}

//copy operator assignment
LinkedList& LinkedList::operator=(LinkedList& other_list) {
	m_head = other_list.m_head;

	if (this == &other_list) {
		return *this;
	}

	while (m_head != nullptr) {
		m_head->m_next = other_list.m_head->m_next;
	}

	return *this;
}

LinkedList& LinkedList::operator+(LinkedList& other_list) {
	LinkedList new_list;
	
	if (m_head == nullptr) {
		new_list = other_list;
	}
	else if (other_list.m_head == nullptr) {
		new_list = this;
	}
	else {
		while (m_head != nullptr) {
		Node* tmp = other_list.m_head;
		Node* new_node = new_node.m_head;
		new_node = m_head->m_data + other_list.m_data;

		m_head = m_head->m_next;
		tmp = tmp->m_next;
		new_node = new_node->m_next;
		}
	}

	return new_list;
}

LinkedList& LinkedList::operator+=(LinkedList& otherList) {
	if (m_head == nullptr) {
		this = otherList;
	}
	else if (otherList.m_head == nullptr) {
		return *this;
	}
	else {
		while (m_head != nullptr) {
		Node* tmp = otherList.m_head;
		m_head->m_data += tmp->m_data;

		m_head = m_head->m_next;
		tmp = tmp->m_next;
		}
	}

	return *this;
}

bool LinkedList::operator==(LinkedList& other_list) {
	if (m_head == nullptr && other_list.m_head == nullptr) {
		return true;
	}

	Node* new_node = other_list.m_head;
	while (new_node != nullptr) {
		if (new_node->m_data != m_head->m_data) {
			return false;
		}

		new_node = new_node->m_next;
		m_head = m_head->m_next;
	}
	return true;
}

bool LinkedList::operator!=(LinkedList& other_list) {
	if (m_head == nullptr && other_list.m_head == nullptr) {
		return false;
	}

	Node* new_node = other_list.m_head;
	while (new_node != nullptr) {
		if (new_node->m_data == m_head->m_data)
			return false;
		
		new_node = new_node->m_next;
		m_head = m_head->m_next;
	}
	return true;
}

bool LinkedList::operator<(LinkedList& other_list) {
	return this->m_list_size < other_list.m_list_size;
}

bool LinkedList::operator<=(LinkedList& other_list) {
	return this->m_list_size <= other_list.m_list_size;
}

bool LinkedList::operator>(LinkedList& other_list) {
	return this->m_list_size > other_list.m_list_size;
}

bool LinkedList::operator>=(LinkedList& other_list) {
	return this->m_list_size >= other_list.m_list_size;
}

std::ostream& LinkedList::operator<<(std::ostream& out, const LinkedList& other_list) {
	Node* new_node = other_list.m_head;

	while (new_node != nullptr) {
		out << new_node->m_data << " ";
		new_node = new_node->m_next;
	}

	return out;
}
