#include "linked_list.h"


int main() {	
	LinkedList<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_back(7);
	std::cout << "list1: " << list << std::endl;


	LinkedList<int> list2;
	list2.push_front(1);
	list2.push_front(2);
	list2.push_front(5);
	std::cout << "list2: " << list2 << std::endl;


	std::cout << std::boolalpha << (list >= list2) << std::endl;
	std::cout << std::boolalpha << (list <= list2) << std::endl;
	std::cout << std::boolalpha << (list > list2) << std::endl;
	std::cout << std::boolalpha << (list < list2) << std::endl;
	std::cout << std::boolalpha << (list != list2) << std::endl;
	std::cout << std::boolalpha << (list == list2) << std::endl;


	list.merge(list2);
	list.splice(list.end(), list2);
	auto it = list.emplace(list.begin(), 41);
	list.insert(list.front(), 110);
	std::cout << *it << std::endl;

	
	std::cout << "\nMove constructor works here: ";
	LinkedList<int>* $list = new LinkedList<int>;
	$list->push_back(1);
	$list->push_back(2);
	$list->push_back(3);
	LinkedList<int>* list3 = $list;
	std::cout << "list3: " << list3 << std::endl;

	
	LinkedList<int> list4 = std::move(list);
	std::cout << "list4: " << list4 << std::endl;


	LinkedList<int> list5 = {1,2,3,4};
	std::cout << "\nCopy constructor works here: ";
	std::cout << "list5: " << list5 << std::endl;
	

	LinkedList<int> list6;
	list6.push_front(5);
	list6.push_front(6);
	list6.push_front(6);
	list6.pop_front();
	list6.push_front(7);
	list6.push_front(7);
	list6.push_front(7);
	list.splice(list.begin(), list6);
	list6.unique();
	std::cout << "list6: " << list6 << std::endl;
	

	LinkedList<int> list7 = { 1,2,3 };

	std::cout << std::endl;

	LinkedList<int> list8 = { 11,1,4 };
	
	return 0;
}