#include "linked_list.h"

template <class T>
LinkedList<T>::Iterator::Iterator(T* ptr) : m_ptr(ptr) {}

template <class T>
T& LinkedList<T>::Iterator::operator*() const {
	return *m_ptr;
}

template <class T>
T* LinkedList<T>::Iterator::operator->() const {
	return m_ptr;
}

template <class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++() {
	++m_ptr;
	return *this;
}

template <class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++(int) {
	Iterator* tmp = *this;
	++(*this);
	return tmp;
}

template <class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--() {
	--m_ptr;
	return *this;
}

template <class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--(int) {
	Iterator tmp = *this;
	--(*this);
	return tmp;
}

template <class T>
bool LinkedList<T>::Iterator::operator==(const Iterator& other) {
	return m_ptr == other.m_ptr;
}

template <class T>
bool LinkedList<T>::Iterator::operator!=(const Iterator& other) {
	return m_ptr != other.m_ptr;
}

/*  Constructors and Destructor  */
template <class T>
LinkedList<T>::LinkedList() {
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other_list) {
	if (other_list.m_head == nullptr) {
		m_head = nullptr;
		m_tail = nullptr;
		m_size = 0;
	}
	else {
		Node* tmp = other_list.m_head;
		m_head = new Node(tmp->m_data, nullptr, nullptr);
		m_tail = new Node;
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

	m_size = other_list.m_size;
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T>&& other_list) :
	m_head(other_list.m_head),
	m_tail(other_list.m_tail),
	m_size(other_list.m_size) {
	other_list.m_head = nullptr;
	other_list.m_tail = nullptr;
	other_list.m_size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const std::initializer_list<T>& other_list) {
	std::cout << "initializer_list works here: ";
	for (auto it = other_list.begin(); it != other_list.end(); ++it) {
		std::cout << *it << " ";
	}
}

template <class T>
LinkedList<T>::~LinkedList() {
	Node* tmp;
	while (m_head) {
		tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
	m_size = 0;
}

/*  Functions and Overloaded Operators  */

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::front() {
	return m_head;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::back() {
	return m_tail;
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() {
	return Iterator(&(m_head->m_data));
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::end() {
	return Iterator(&(m_tail->m_data));
}

template <class T>
bool LinkedList<T>::empty() const {
	if (m_size == 0) {
		return true;
	}
	return false;
}

template <class T>
int LinkedList<T>::size() const {
	return m_size;
}

template <class T>
void LinkedList<T>::push_front(T data) {
	Node* new_node = new Node(data, m_head, nullptr);

	if (m_head != nullptr) {
		new_node->m_next->m_prev = new_node;
	}
	else {
		m_tail = new_node;
	}

	m_head = new_node;
	++m_size;
}

template <class T>
void LinkedList<T>::push_back(T data) {
	Node* new_node = new Node(data, nullptr, m_tail);

	if (m_tail != nullptr) {
		new_node->m_prev->m_next = new_node;
	}
	else {
		m_head = new_node;
	}

	m_tail = new_node;
	++m_size;
}

template <class T>
void LinkedList<T>::resize(int new_size) {
	if (new_size < m_size) {
		while (new_size != m_size) {
			pop_back();
		}
	}
	else if (new_size > m_size) {
		while (new_size != m_size) {
			push_back(0);
		}
	}
	else {
		return;
	}

	m_size = new_size;
}

template <class T>
void LinkedList<T>::pop_front() {
	if (m_head != nullptr) {
		Node* tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
	else {
		return;
	}

	--m_size;
}

template <class T>
void LinkedList<T>::pop_back() {
	Node* tmp = m_head;
		while (tmp->m_next != nullptr)
		{
			tmp = tmp->m_next;
		}
		tmp = tmp->m_prev;
		delete tmp->m_next;
		tmp->m_next = nullptr;
}

template <class T>
void LinkedList<T>::unique() {
	Node* tmp1 = m_head;
	Node* tmp2 = new Node;
	Node* dup = new Node;

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

	Node* tmp = nullptr;
	while (m_head) {
		tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
	m_size = 0;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& other_list) {
	if (&other_list == this) {
		return *this;
	}

	if (m_head != nullptr) {
		clear();
	}

	m_head = new Node;
	m_tail = new Node;
	m_head->m_next = m_tail;
	m_tail->m_prev = m_head;

	*this = std::move(other_list);
	return *this;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other_list) {
	if (this == &other_list) {
		return *this;
	}

	if (m_head != nullptr) {
		Node* tmp = nullptr;
		while (m_head) {
			tmp = m_head;
			m_head = m_head->m_next;
			delete tmp;
		}
	}

	if (other_list.m_head == nullptr) {
		m_head = nullptr;
	}
	else {
		Node* current1 = other_list.m_head;
		m_head = new Node(current1->m_data, nullptr, nullptr);
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
		Node* tmp = m_head;
		Node* tmp2 = other_list.m_head;

		if (m_size > other_list.m_size) {
			while (tmp2 != nullptr) {
				tmp->m_data += tmp2->m_data;
				tmp = tmp->m_next;
				tmp2 = tmp2->m_next;
			}
			while (tmp != nullptr) {
				push_back(tmp->m_data);
			}
		}
		else if (m_size < other_list.m_size) {
			while (tmp != nullptr) {
				tmp->m_data += tmp2->m_data;
				tmp = tmp->m_next;
				tmp2 = tmp2->m_next;
			}
			while (tmp2 != nullptr) {
				push_back(tmp2->m_data);
			}
		}
		else {
			while (tmp != nullptr) {
				tmp->m_data += tmp2->m_data;
				tmp = tmp->m_next;
				tmp2 = tmp2->m_next;
			}
		}
	}

	return new_list;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator+=(const LinkedList<T>& other_list) {
	if (m_head == nullptr) {
		*this = other_list;
	}
	else if (other_list.m_head == nullptr) {
		return *this;
	}
	else {
		Node* tmp = m_head;
		Node* tmp2 = other_list.m_head;

		if (m_size > other_list.m_size) {
			while (tmp2 != nullptr) {
				tmp->m_data += tmp2->m_data;
				tmp = tmp->m_next;
				tmp2 = tmp2->m_next;
			}
			while (tmp != nullptr) {
				push_back(tmp->m_data);
			}
		}
		else if (m_size < other_list.m_size) {
			while (tmp != nullptr) {
				tmp->m_data += tmp2->m_data;
				tmp = tmp->m_next;
				tmp2 = tmp2->m_next;
			}
			while (tmp2 != nullptr) {
				push_back(tmp2->m_data);
			}
		}
		else {
			while (tmp != nullptr) {
				tmp->m_data += tmp2->m_data;
				tmp = tmp->m_next;
				tmp2 = tmp2->m_next;
			}
		}
	}

	return *this;
}

template <class T>
bool LinkedList<T>::operator==(LinkedList<T>& other_list) {
	return sum() == other_list.sum();
}

template <class T>
bool LinkedList<T>::operator!=(LinkedList<T>& other_list) {
	return sum() != other_list.sum();
}

template <class T>
bool LinkedList<T>::operator<(LinkedList<T>& other_list) {
	return sum() < other_list.sum();
}

template <class T>
bool LinkedList<T>::operator<=(LinkedList<T>& other_list) {
	return sum() <= other_list.sum();
}

template <class T>
bool LinkedList<T>::operator>(LinkedList<T>& other_list) {
	return sum() > other_list.sum();
}

template <class T>
bool LinkedList<T>::operator>=(LinkedList<T>& other_list) {
	return sum() >= other_list.sum();
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& other_list) {
	typename LinkedList<T>::template Node* tmp = other_list.m_head;

	while (tmp != nullptr) {
		out << tmp->m_data << " ";
		tmp = tmp->m_next;
	}

	return out;
}

template <class T>
typename LinkedList<T>::Node LinkedList<T>::insert(Node* node, const T& data) {
	Node* new_node = new Node(data);
	new_node->m_next = node->m_next;
	node->m_next = new_node;

	++m_size;
	return *node;
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::emplace(Iterator it, T&& data) {
	if (begin() == it) {
		push_front(data);
		it = begin();
	}
	else if (end() == it) {
		push_back(data);
		it = end();
	}
	else {
		Node* tmp = m_head;
		Node* new_node = new Node(data);
		for (auto iterator = begin(); iterator != end(); ++iterator) {
			tmp = tmp->m_next;
			if (iterator == it) {
				new_node->m_next = tmp->m_next;
				tmp->m_next = new_node;
			}
		}
	}

	return it;
}

template <class T>
void LinkedList<T>::splice(Iterator it, LinkedList<T>& other_list) {
	if (it == begin()) {
		Node* tmp = other_list.m_tail;
		while (tmp) {
			push_front(tmp->m_data);
			tmp = tmp->m_prev;
		}
	}
	else if (it == end()) {
		Node* tmp = other_list.m_head;
		while (tmp) {
			push_back(tmp->m_data);
			tmp = tmp->m_next;
		}
	}
}

template <class T>
LinkedList<T>& LinkedList<T>::merge(LinkedList<T>& other_list) {
	if (this == &other_list) {
		return *this;
	}

	Node* tmp = other_list.m_head;
	while (tmp != nullptr) {
		push_back(tmp->m_data);
		tmp = tmp->m_next;
	}

	return *this;
}

template <class T>
T LinkedList<T>::sum() {
	if (m_head == nullptr) {
		return true;
	}

	T result = T();

	while (m_head) {
		result += m_head->m_data;
		m_head = m_head->m_next;
	}

	return result;
}

template <class T>
void LinkedList<T>::print() {
	Node* tmp = m_head;
	if (tmp != nullptr) {
		while (tmp) {
			std::cout << tmp->m_data << " ";
			tmp = tmp->m_next;
		}
	}
	else {
		std::cout << "List is empty";
	}
}