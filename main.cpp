#include "linked_list.h"
#include <iostream>

int main() {
	LinkedList list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	
	LinkedList list1;
	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3);

	bool flag = (list == list1);
	std::cout << flag;

	return 0;
}
