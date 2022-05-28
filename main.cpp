#include "linked_list.h"
#include <iostream>


LinkedList* generateList() {
	LinkedList* list = new LinkedList;
	std::cout << "\nMove constructor works here!\n";
	return list;
}

int main() {
	LinkedList list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_back(4);
	

	LinkedList list2 = { 1,2,3,4,5 };

	LinkedList* list3 = generateList();

	LinkedList list4 = list;
	std::cout << "Copy constructor works here: ";
	list4.print();
	

	list.insert(4, 1);
	auto it = list.emplace(list.begin(), 4);
	//LinkedList list4;
	//list4.push_front(5);
	//list4.push_front(6);
	//list4.push_front(7);
	list.print();


	return 0;
}