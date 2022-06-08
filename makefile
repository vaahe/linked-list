  all: linked_list.x

  linked_list.x: linked_list.hpp main.cpp
				g++ main.cpp -o linked_list.x -std=c++20

  clean: 
	  $(RM) linked_list