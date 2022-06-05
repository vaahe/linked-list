/*  Constructors and Destructor  */
template <class T>
LinkedList<T>::LinkedList() {
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other_list) {
	Node<T>* tmp = nullptr;
	Node<T>* tmp2 = nullptr;

	if (other_list.m_head == nullptr) {
		Node<T> node;
	}
	else {
			tmp = other_list.m_head;
			m_head = new Node<T>;
			m_tail = new Node<T>;
			m_head->m_prev = nullptr;
			m_head->m_data = tmp->m_data;
			tmp = tmp->m_next;
			tmp2 = m_head;

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

	m_size = other_list.m_size;
}

//move constructor
template <class T>
LinkedList<T>::LinkedList(LinkedList<T>&& other_list) :
	m_head(other_list.m_head),
	m_tail(other_list.m_tail),
	m_size(other_list.m_size) {
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
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
	while (m_head) {
		Node<T>* tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
	m_size = 0;
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
	Node<T>* new_node = new Node<T>(data, m_head, nullptr);

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
	Node<T>* new_node = new Node<T>(data, nullptr, m_tail);

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

	--m_size;
}

template <class T>
void LinkedList<T>::pop_back() {
	if (m_head != nullptr) {
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

	--m_size;
}


template <class T>
void LinkedList<T>::unique() {
	Node<T>* tmp1 = m_head;
	Node<T>* tmp2 = new Node<T>;
	Node<T>* dup = new Node<T>;

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
	m_size = 0;
}


//move operator assignment
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& other_list) {
	if (&other_list == this) {
		return *this;
	}

	Node<T>* tmp = nullptr;
	while (m_head != nullptr) {
		tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
	
	m_head = other_list.m_head;
	m_tail = other_list.m_tail;
	
	Node<T>* tmp2 = nullptr;
	while (other_list.m_head != nullptr) {
		tmp2 = other_list.m_head;
		other_list.m_head = other_list.m_head->m_next;
		tmp2 = nullptr;
	}

	return *this;
}

//copy operator assignment
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other_list) {
	if (this == &other_list) {
		return *this;
	}

	if (m_head != nullptr) {
		Node<T>* tmp = nullptr;
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
		Node<T>* current1 = other_list.m_head;
		m_head = new Node<T>(current1->m_data, nullptr, nullptr);
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
		Node<T>* tmp = m_head;
		Node<T>* tmp2 = other_list.m_head;

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
		Node<T>* tmp = m_head;
		Node<T>* tmp2 = other_list.m_head;

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
bool LinkedList<T>::operator==(const LinkedList<T>& other_list) {
	if (m_head == nullptr && other_list.m_head == nullptr) {
		return true;
	}

	T sum1 = T();
	T sum2 = T();

	Node<T>* tmp1 = m_head;
	Node<T>* tmp2 = other_list.m_head;

	while (tmp1 != nullptr) {
		sum1 += tmp1->m_data;
		tmp1 = tmp1->m_next;
	}

	while (tmp2 != nullptr) {
		sum2 += tmp1->m_data;
		tmp2 = tmp2->m_next;
	}

	return sum1 == sum2;
}

template <class T>
bool LinkedList<T>::operator!=(const LinkedList<T>& other_list) {
	if (m_head == nullptr && other_list.m_head == nullptr) {
		return false;
	}

	T sum1 = T();
	T sum2 = T();

	Node<T>* tmp1 = m_head;
	Node<T>* tmp2 = other_list.m_head;

	while (tmp1 != nullptr) {
		sum1 += tmp1->m_data;
		tmp1 = tmp1->m_next;
	}

	while (tmp2 != nullptr) {
		sum2 += tmp1->m_data;
		tmp2 = tmp2->m_next;
	}

	return sum1 != sum2;
}

template <class T>
bool LinkedList<T>::operator<(const LinkedList<T>& other_list) {
	if (m_head == nullptr && other_list.m_head == nullptr) {
		return false;
	}

	T sum1 = T();
	T sum2 = T();

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

	return sum1 < sum2;
}

template <class T>
bool LinkedList<T>::operator<=(const LinkedList<T>& other_list) {
	if (m_head == nullptr && other_list.m_head == nullptr) {
		return true;
	}

	T sum1 = T();
	T sum2 = T();

	Node<T>* tmp1 = m_head;
	Node<T>* tmp2 = other_list.m_head;

	while (tmp1 != nullptr) {
		sum1 += tmp1->m_data;
		tmp1 = tmp1->m_next;
	}

	while (tmp2 != nullptr) {
		sum2 += tmp1->m_data;
		tmp2 = tmp2->m_next;
	}

	return sum1 <= sum2;
}

template <class T>
bool LinkedList<T>::operator>(const LinkedList<T>& other_list) {
	if (m_head == nullptr && other_list.m_head == nullptr) {
		return false;
	}

	T sum1 = T();
	T sum2 = T();

	Node<T>* tmp1 = m_head;
	Node<T>* tmp2 = other_list.m_head;

	while (tmp1 != nullptr) {
		sum1 += tmp1->m_data;
		tmp1 = tmp1->m_next;
	}

	while (tmp2 != nullptr) {
		sum2 += tmp1->m_data;
		tmp2 = tmp2->m_next;
	}

	return sum1 > sum2;
}

template <class T>
bool LinkedList<T>::operator>=(const LinkedList<T>& other_list) {
	if (m_head == nullptr && other_list.m_head == nullptr) {
		return true;
	}

	T sum1 = T();
	T sum2 = T();

	Node<T>* tmp1 = m_head;
	Node<T>* tmp2 = other_list.m_head;

	while (tmp1 != nullptr) {
		sum1 += tmp1->m_data;
		tmp1 = tmp1->m_next;
	}

	while (tmp2 != nullptr) {
		sum2 += tmp1->m_data;
		tmp2 = tmp2->m_next;
	}

	return sum1 >= sum2;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& other_list) {
	typename LinkedList<T>::template Node<T>* tmp = other_list.m_head;

	while (tmp != nullptr) {
		out << tmp->m_data << " ";
		tmp = tmp->m_next;
	}

	return out;
}


template <class T>
LinkedList<T>::Node<T> LinkedList<T>::insert(Node<T>* node, const T& data) {
	Node<T>* new_node = new Node<T>(data);
	new_node->m_next = node->m_next;
	node->m_next = new_node;
	
	++m_size;
	return *node;
}

template <class T>
LinkedList<T>::Iterator<T> LinkedList<T>::emplace(Iterator<T> it, T&& data) {
	if (begin() == it) {
		push_front(data);
		it = begin();
	}
	else if (end() == it) {
		push_back(data);
		it = end();
	}
	else {
		Node<T>* tmp = m_head;
		Node<T>* new_node = new Node<T>(data);
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
		return *this;
	}

	Node<T>* tmp = other_list.m_head;
	while (tmp != nullptr) {
		push_back(tmp->m_data);
		tmp = tmp->m_next;
	}

	return *this;
}