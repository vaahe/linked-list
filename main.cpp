#include "linked_list.h"
#include <iostream>


int main() {
	LinkedList<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_back(4);
	std::cout << "list1: " << list << std::endl;


	LinkedList<int> list2;
	list2.push_front(1);
	list2.push_front(2);
	list2.push_front(7);

	list.merge(list2);
	list.splice(list.end(), list2);
	auto it = list.emplace(list.begin(), 41);
	list.insert(list.front(), 110);
	std::cout << "list2: " << list2 << std::endl;
	std::cout << "Iterator: " << *it << std::endl;

	std::cout << "\nMove constructor works here: ";
	LinkedList<int>* $list = new LinkedList<int>;
	$list->push_back(1);
	$list->push_back(2);
	$list->push_back(3);
	LinkedList<int>* list3 = $list;
	std::cout << "list3: " << list3 << std::endl;


	LinkedList<int> list4 = list;
	std::cout << "\nCopy constructor works here: ";
	std::cout << "list4:" << list4 << std::endl;


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
	std::cout << "list5: " << list5 << std::endl;
	

	LinkedList<int> list6 = { 1,2,3 };
	std::cout << std::endl;
	LinkedList<int> list7 = { 11,1,4 };
	std::cout << std::endl;
	std::cout<<list6.operator==(list7);
	return 0;
}