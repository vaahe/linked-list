#include "linked_list.h"
#include <iostream>


/*  Constructors and Destructor  */

template <class T>
LinkedList<T>::LinkedList() {
	m_head = nullptr;
	m_tail = nullptr;
	m_list_size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other_list) {
	//if other list is empty
	if (other_list.m_head == nullptr) {
		m_head = nullptr;
		m_tail = nullptr;
	}
	//if other list is not empty
	else {
		if (other_list.m_head == nullptr) {
			m_head->m_next = nullptr;
		}
		else {
			Node<T>* tmp = other_list.m_head;
			m_head = new Node<T>;
			m_tail = new Node<T>;
			m_head->m_prev = nullptr;
			m_head->m_data = tmp->m_data;
			tmp = tmp->m_next;
			Node<T>* tmp2 = m_head;

			while (tmp != nullptr) {
				tmp2->m_next = new Node<T>;
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
template <class T>
LinkedList<T>::LinkedList(LinkedList<T>&& other_list) :
	m_head(other_list.m_head),
	m_tail(other_list.m_tail),
	m_list_size(other_list.m_list_size) {
	m_head = nullptr;
	m_tail = nullptr;
	m_list_size = 0;
}

template <class T>
LinkedList<T>::LinkedList(int size) : m_list_size(size) {
	m_head = nullptr;
	m_tail = nullptr;
};

template <class T>
LinkedList<T>::LinkedList(const std::initializer_list<T>& other_list) : LinkedList<T>(other_list.size()) {
	std::cout << "initializer_list works here: ";
	for (auto it = other_list.begin(); it != other_list.end(); ++it) {
		std::cout << *it << " ";
	}
}

template <class T>
LinkedList<T>::~LinkedList() {
	while (m_head) {
		Node<T>* tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
	m_list_size = 0;
}


/*  Functions and Overloaded Operators  */

template <class T>
typename LinkedList<T>::template Node<T>* LinkedList<T>::front() {
	return m_head;
}						

template <class T>
typename LinkedList<T>::template Node<T>* LinkedList<T>::back() {
	return m_tail;
}

template <class T>
LinkedList<T>::Iterator<T> LinkedList<T>::begin() {
	return Iterator<T>(&(m_head->m_data));
}

template <class T>
LinkedList<T>::Iterator<T> LinkedList<T>::end() {
	return Iterator<T>(&(m_tail->m_data));
}

template <class T>
bool LinkedList<T>::empty() {
	if (m_list_size == 0) {
		return true;
	}
	return false;
}

template <class T>
int LinkedList<T>::size() {
	return m_list_size;
}

template <class T>
void LinkedList<T>::push_front(T data) {
	Node<T>* new_node = new Node<T>;
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

template <class T>
void LinkedList<T>::push_back(T data) {
	Node<T>* new_node = new Node<T>;
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

template <class T>
void LinkedList<T>::resize(int new_size) {
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

template <class T>
void LinkedList<T>::pop_front() {
	if (m_head->m_next != nullptr) {
		Node<T>* tmp = m_head;
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

template <class T>
void LinkedList<T>::pop_back() {
	if (m_head->m_next != nullptr) {
		Node<T>* tmp = m_tail;
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

template <class T>
void LinkedList<T>::unique() {
	Node<T>* tmp1 = new Node<T>;
	Node<T>* tmp2 = new Node<T>;
	Node<T>* dup = new Node<T>;

	tmp1 = m_head;

	while (tmp1 != nullptr) {
		tmp2 = tmp1;
		while (tmp2->m_next != nullptr) {
			if (tmp1->m_data == tmp2->m_next->m_data) {
				dup = tmp2->m_next;
				tmp2->m_next = tmp2->m_next->m_next;
				delete dup;
			}
			else {
				tmp2 = tmp2->m_next;
			}
		}
		tmp1 = tmp1->m_next;
	}
}

template <class T>
void LinkedList<T>::clear() {
	if (m_head == nullptr) {
		return;
	}

	Node<T>* tmp = nullptr;
	while (m_head) {
		tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
	m_list_size = 0;
}

template <class T>
void LinkedList<T>::print() {
	if (m_head != nullptr) {
		Node<T>* current = m_head;

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
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& other_list) {
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
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& other_list) {
	if (this != &other_list) {
		//if list is not empty
		if (m_head != nullptr) {
			while (m_head) {
				Node<T>* tmp = m_head;
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
			Node<T>* current1 = other_list.m_head;
			m_head->m_prev = nullptr;
			m_head->m_data = current1->m_data;
			current1 = current1->m_next;

			if (current1 == nullptr) {
				m_head->m_next = nullptr;
			}
			else {
				Node<T>* current2 = m_head;

				while (current1 != nullptr) {
					current2->m_next = new Node<T>;
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

template <class T>
LinkedList<T>& LinkedList<T>::operator+(LinkedList<T>& other_list) {
	LinkedList<T> new_list;

	if (m_head == nullptr) {
		new_list = other_list;
	}
	else if (other_list.m_head == nullptr) {
		new_list = *this;
	}
	else {
		while (m_head != nullptr) {
			Node<T>* tmp = other_list.m_head;
			Node<T>* new_node = new_list.m_head;

			new_node->m_data = m_head->m_data + new_node->m_data;

			m_head = m_head->m_next;
			tmp = tmp->m_next;
			new_node = new_node->m_next;
		}
	}

	return new_list;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator+=(LinkedList<T>& otherList) {
	if (m_head == nullptr) {
		*this = otherList;
	}
	else if (otherList.m_head == nullptr) {
		return *this;
	}
	else {
		while (m_head != nullptr) {
			Node<T>* tmp = otherList.m_head;
			m_head->m_data += tmp->m_data;

			m_head = m_head->m_next;
			tmp = tmp->m_next;
		}
	}

	return *this;
}

template <class T>
bool LinkedList<T>::operator==(LinkedList<T>& other_list) {
	if (m_head == nullptr && other_list.m_head == nullptr) {
		return true;
	}

	Node<T>* new_node = other_list.m_head;
	while (new_node != nullptr) {
		if (new_node->m_data != m_head->m_data) {
			return false;
		}

		new_node = new_node->m_next;
		m_head = m_head->m_next;
	}

	return true;
}

template <class T>
bool LinkedList<T>::operator!=(LinkedList<T>& other_list) {
	if (m_head == nullptr && other_list.m_head == nullptr) {
		return false;
	}

	Node<T>* new_node = other_list.m_head;
	while (new_node != nullptr) {
		if (new_node->m_data == m_head->m_data)
			return false;

		new_node = new_node->m_next;
		m_head = m_head->m_next;
	}
	
	return true;
}

template <class T>
bool LinkedList<T>::operator<(LinkedList<T>& other_list) {
	int sum1 = 0;
	int sum2 = 0;

	Node<T>* tmp1 = m_head;
	Node<T>* tmp2 = other_list.m_head;

	while (tmp1) {
		sum1 += tmp1->m_data;
		tmp1 = tmp1->m_next;
	}

	while (tmp2) {
		sum2 += tmp1->m_data;
		tmp2 = tmp2->m_next;
	}

	return sum1 < sum2 ? true : false;
}

template <class T>
bool LinkedList<T>::operator<=(LinkedList<T>& other_list) {
	int sum1 = 0;
	int sum2 = 0;

	Node<T>* tmp1 = m_head;
	Node<T>* tmp2 = other_list.m_head;

	while (tmp1) {
		sum1 += tmp1->m_data;
		tmp1 = tmp1->m_next;
	}

	while (tmp2) {
		sum2 += tmp1->m_data;
		tmp2 = tmp2->m_next;
	}

	return sum1 <= sum2 ? true : false;
}

template <class T>
bool LinkedList<T>::operator>(LinkedList<T>& other_list) {
	int sum1 = 0;
	int sum2 = 0;

	Node<T>* tmp1 = m_head;
	Node<T>* tmp2 = other_list.m_head;

	while (tmp1) {
		sum1 += tmp1->m_data;
		tmp1 = tmp1->m_next;
	}

	while (tmp2) {
		sum2 += tmp1->m_data;
		tmp2 = tmp2->m_next;
	}

	return sum1 > sum2 ? true : false;
}

template <class T>
bool LinkedList<T>::operator>=(LinkedList<T>& other_list) {
	int sum1 = 0;
	int sum2 = 0;

	Node<T>* tmp1 = m_head;
	Node<T>* tmp2 = other_list.m_head;

	while (tmp1) {
		sum1 += tmp1->m_data;
		tmp1 = tmp1->m_next;
	}

	while (tmp2) {
		sum2 += tmp1->m_data;
		tmp2 = tmp2->m_next;
	}

	return sum1 >= sum2 ? true : false;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& other_list) {
	typename LinkedList<T>::Node* new_node;
	new_node = other_list.m_head;

	while (new_node != nullptr) {
		out << new_node->m_data << " ";
		new_node = new_node->m_next;
	}

	return out;
}

template <class T>
T& LinkedList<T>::operator[](int index) {
	int counter = 0;
	Node<T>* tmp = m_head;

	if (index <= m_list_size / 2) {
		while (tmp != nullptr) {
			if (counter == index) {
				return tmp->m_data;
			}
			tmp = tmp->m_next;
			++counter;
		}
	}

	counter = m_list_size - 1;
	tmp = m_tail;
	while (tmp != nullptr) {
		if (counter == index) {
			return tmp->m_data;
		}
		tmp = tmp->m_prev;
		--counter;
	}

	return tmp->m_data;
}

template <class T>
void LinkedList<T>::insert(T data, int index) {
	if (index == 0) {
		push_front(data);
	}
	else if (index < 0 || index > m_list_size + 1) {
		std::cout << "Invalid index!";
	}
	else {
		if (index < m_list_size / 2) {
			Node<T>* tmp = m_head;
			for (int i = 0; i < index - 1; ++i) {
				tmp = tmp->m_next;
			}

			Node<T>* new_node = new Node<T>(data, tmp->m_next, tmp);
			tmp->m_next = new_node;
			new_node->m_next->m_prev = new_node;
		}
		else {
			Node<T>* tmp = m_tail;
			for (int i = m_list_size - 1; i > index - 1; --i) {
				tmp = tmp->m_prev;
			}

			Node<T>* new_node = new Node<T>(data, tmp->m_next, tmp);
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

template <class T>
LinkedList<T>::Iterator<T> LinkedList<T>::emplace(Iterator<T> it, T data) {
	if (it == begin()) {
		push_front(data);
		return it;
	}
	else if (it == end()) {
		push_back(data);
		return it;
	}
	else {
		Node<T>* tmp = m_head;
		for (auto iterator = begin(); iterator != end(); ++iterator) {
			*it = tmp->m_data;
			tmp = tmp->m_next;
		}

		Node<T>* new_node = new Node<T>(data, tmp->m_next, tmp);
		tmp->m_next = new_node;
		new_node->m_next->m_prev = new_node;
	}

	return it;
}

template <class T>
void LinkedList<T>::splice(Iterator<T> it, LinkedList<T>& other_list) {
	if (it == begin()) {
		Node<T>* tmp = other_list.m_tail;
		while (tmp) {
			push_front(tmp->m_data);
			tmp = tmp->m_prev;
		}
	}
	else if (it == end()) {
		Node<T>* tmp = other_list.m_head;
		while (tmp) {
			push_back(tmp->m_data);
			tmp = tmp->m_next;
		}
	}
}

template <class T>
LinkedList<T>& LinkedList<T>::merge(LinkedList<T>& other_list) {
	if (this == &other_list) {
		return;
	}

	m_tail->m_next = other_list->m_head;

	return *this;
}		