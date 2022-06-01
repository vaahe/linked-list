#include "linked_list.h"
#include <iostream>


int main() {
	LinkedList<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_back(4);
	std::cout << "list1: ";
	list.print();
	std::cout << "\nSecond index of list1: " << list[1] << std::endl;


	LinkedList<int> list2 = { 1,2,3,4,5 };


	std::cout << "\nMove constructor works here: ";
	LinkedList<int>* $list = new LinkedList<int>;
	$list->push_back(1);
	$list->push_back(2);
	$list->push_back(3);
	LinkedList<int>* list3 = $list;
	list3->print();


	LinkedList<int> list4 = list;
	std::cout << "\nCopy constructor works here: ";
	list4.print();
	std::cout << std::endl;


	list.insert(4, 1);
	auto it = list.emplace(list.begin(), 4);
	LinkedList<int> list5;
	list5.push_front(5);
	list5.push_front(6);
	list5.push_front(6);
	list5.pop_front();
	list5.push_front(7);
	list5.push_front(7);
	list5.push_front(7);
	list.splice(list.begin(), list5);
	list5.unique();
	std::cout << "list5: ";
	list.print();
	std::cout << std::endl;


	LinkedList<int> list6 = { 1,2,3,4 };
	std::cout << std::endl;
	LinkedList<int> list7 = { 1,1,4 };
	bool state = list6 > list7;
	std::cout << std::endl;
	std::cout << state;

	return 0;
}