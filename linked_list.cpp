#include "linked_list.h"
#include <iostream>


/*  Constructors and Destructor  */

LinkedList::LinkedList() {
	m_head = nullptr;
	m_tail = nullptr;
	m_list_size = 0;
}

LinkedList::LinkedList(const LinkedList& other_list) {
	//if other list is empty
	if (other_list.m_head == nullptr) {
		m_head = nullptr;
	}
	//if other list is not empty
	else {
		if (other_list.m_head == nullptr) {
			m_head->m_next = nullptr;
		}
		else {
			Node* tmp = other_list.m_head;
			m_head = new Node;
			m_tail = new Node;
			m_head->m_prev = nullptr;
			m_head->m_data = tmp->m_data;
			tmp = tmp->m_next;
			Node* tmp2 = m_head;

			while (tmp != nullptr) {
				tmp2->m_next = new Node;
				tmp2->m_next->m_prev = tmp2;
				tmp2 = tmp2->m_next;
				tmp2->m_data = tmp->m_data;
				tmp = tmp->m_next;
			}

			tmp2->m_next = nullptr;
			m_tail = tmp2;
		}
	}

	m_list_size = other_list.m_list_size;
}

//move constructor
LinkedList::LinkedList(LinkedList&& other_list) :
	m_head(other_list.m_head),
	m_tail(other_list.m_tail),
	m_list_size(other_list.m_list_size) {
	m_head = nullptr;
	m_tail = nullptr;
	m_list_size = 0;
}

LinkedList::LinkedList(int size) : m_list_size(size) {};

LinkedList::LinkedList(const std::initializer_list<int>& other_list) : LinkedList(other_list.size()) {
	Node* tmp = m_head;
	for (auto it = other_list.begin(); it != other_list.end(); ++it) {
		std::cout << *it << " ";
	}
}

LinkedList::~LinkedList() {
	while (m_head) {
		Node* tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
	m_list_size = 0;
}


/*  Functions and Overloaded Operators  */

LinkedList::Node* LinkedList::front() {
	return m_head;
}

LinkedList::Node* LinkedList::back() {
	return m_tail;
}

Iterator LinkedList::begin() {
	return Iterator(&(m_head->m_data));
}

Iterator LinkedList::end() {
	return Iterator(&(m_tail->m_data));
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
	if (m_head->m_next != nullptr) {
		Node* tmp = m_head;
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
	if (m_head->m_next != nullptr) {
		Node* tmp = m_tail;
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
	if (m_head == nullptr) {
		return;
	}

	Node* tmp = nullptr;
	while (m_head) {
		tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
	m_list_size = 0;
}

void LinkedList::print() {
	if (m_head != nullptr) {
		Node* current = m_head;

		while (current != nullptr) {
			std::cout << current->m_data << " ";
			current = current->m_next;
		}
	}
	else {
		std::cout << "List is empty!\n";
	}
}

//move operator assignment
LinkedList& LinkedList::operator=(LinkedList&& other_list) {
	if (&other_list == this) {
		return *this;
	}

	delete m_head;
	delete m_tail;

	m_head = other_list.m_head;
	other_list.m_head = nullptr;

	m_tail = other_list.m_tail;
	other_list.m_tail = nullptr;

	return *this;
}

//copy operator assignment
LinkedList& LinkedList::operator=(LinkedList& other_list) {
	if (this != &other_list) {
		//if list is not empty
		if (m_head != nullptr) {
			while (m_head) {
				Node* tmp = m_head;
				m_head = m_head->m_next;
				delete tmp;
			}

			m_head = nullptr;
			m_tail = nullptr;
			m_list_size = 0;
		}

		//if other list is empty
		if (other_list.m_head == nullptr) {
			m_head = nullptr;
		}
		//if other list is not empty
		else {
			Node* current1 = other_list.m_head;
			m_head->m_prev = nullptr;
			m_head->m_data = current1->m_data;
			current1 = current1->m_next;

			if (current1 == nullptr) {
				m_head->m_next = nullptr;
			}
			else {
				Node* current2 = m_head;

				while (current1 != nullptr) {
					current2->m_next = new Node;
					current2->m_next->m_prev = current2;
					current2 = current2->m_next;

					current2->m_data = current1->m_data;
					current1 = current1->m_next;
				}

				current2->m_next = nullptr;
				m_tail = current2;
			}
		}
	}

	return *this;
}

LinkedList& LinkedList::operator+(LinkedList& other_list) {
	LinkedList new_list;

	if (m_head == nullptr) {
		new_list = other_list;
	}
	else if (other_list.m_head == nullptr) {
		new_list = *this;
	}
	else {
		while (m_head != nullptr) {
			Node* tmp = other_list.m_head;
			Node* new_node = new_list.m_head;

			new_node->m_data = m_head->m_data + new_node->m_data;

			m_head = m_head->m_next;
			tmp = tmp->m_next;
			new_node = new_node->m_next;
		}
	}

	return new_list;
}

LinkedList& LinkedList::operator+=(LinkedList& otherList) {
	if (m_head == nullptr) {
		*this = otherList;
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

std::ostream& operator<<(std::ostream& out, const LinkedList& other_list) {
	LinkedList::Node* new_node;
	new_node = other_list.m_head;

	while (new_node != nullptr) {
		out << new_node->m_data << " ";
		new_node = new_node->m_next;
	}

	return out;
}


int LinkedList::operator[](int index) {
	int counter = 0;
	Node* tmp = m_head;

	if (index <= m_list_size / 2) {
		while (tmp != nullptr) {
			if (counter == index) {
				return tmp->m_data;
			}
			tmp = tmp->m_next;
			++counter;
			return tmp->m_data;
		}
	}
	else {
		counter = m_list_size - 1;
		tmp = m_tail;
		while (tmp != nullptr) {
			if (counter == index) {
				return tmp->m_data;
			}
			tmp = tmp->m_prev;
			--counter;
			return tmp->m_data;
		}
	}
}

void LinkedList::insert(int data, int index) {
	if (index == 0) {
		push_front(data);
	}
	else if (index < 0 || index > m_list_size + 1) {
		std::cout << "Invalid index!";
	}
	else {
		if (index < m_list_size / 2) {
			Node* tmp = m_head;
			for (int i = 0; i < index - 1; ++i) {
				tmp = tmp->m_next;
			}

			Node* new_node = new Node(data, tmp->m_next, tmp);
			tmp->m_next = new_node;
			new_node->m_next->m_prev = new_node;
		}
		else {
			Node* tmp = m_tail;
			for (int i = m_list_size - 1; i > index - 1; --i) {
				tmp = tmp->m_prev;
			}

			Node* new_node = new Node(data, tmp->m_next, tmp);
			tmp->m_next = new_node;
			if (new_node->m_next != nullptr) {
				new_node->m_next->m_prev = new_node;
			}
			else {
				m_tail = new_node;
			}
		}
		++m_list_size;
	}
}

Iterator LinkedList::emplace(Iterator it, int data) {
	if (it == begin()) {
		push_front(data);
		return it;
	}
	else if (it == end()) {
		push_back(data);
		return it;
	}
	else {
		Node* tmp = m_head;
		for (auto iterator = begin(); iterator != end(); ++iterator) {
			*it = tmp->m_data;
			tmp = tmp->m_next;
		}

		Node* new_node = new Node(data, tmp->m_next, tmp);
		tmp->m_next = new_node;
		new_node->m_next->m_prev = new_node;
	}

	return it;
}