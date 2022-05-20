#include "linked_list.h"
#include <iostream>

int main() {
	LinkedList list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.push_front(5);
	list.resize(7);
	list.print();

	return 0;
}