#Doubly Linked List

Doubly Linked List is a variation of Linked list in which navigation is possible in both ways, either forward and backward easily as compared to Single Linked List.

<center><img src="https://www.studytonight.com/code/python/ds/images/doubly-linked-list-1.png"></center>

<hr>

Following are the important terms to understand the concept of doubly linked list.

<li> <b>Link</b> - Each link of a linked list can store a data called an element.
<li> <b>Next</b> - Each link of a linked list contains a link to the next link called Next.
<li> <b>Prev</b> - Each link of a linked list contains a link to the previous link called Prev.
<li> <b>LinkedList</b> - A Linked List contains the connection link to the first link called First and to the last link called Last.

<br>

<li> Doubly Linked List contains a link element called head and tail.
<li> Each link carries a data field(s) and two link fields called next and prev.
<li> Each link is linked with its next link using its next link.
<li> Each link is linked with its previous link using its previous link.
<li> The last link carries a link as null to mark the end of the list.

<br>

 * ### Functions involved in list: 
      * front() – Returns the value of the first element in the list.
      * back() – Returns the value of the last element in the list .
      * push_front(g) – Adds a new element ‘g’ at the beginning of the list .
      * push_back(g) – Adds a new element ‘g’ at the end of the list.
      * pop_front() – Removes the first element of the list, and reduces size of the list by 1.
      * pop_back() – Removes the last element of the list, and reduces size of the list by 1
      * list::begin() and list::end() in C++ STL– begin() function returns an iterator pointing to the first element of the list
      * end()– end() function returns an iterator pointing to the theoretical last element which follows the last element.
      * empty() – Returns whether the list is empty(1) or not(0).
      * insert() – Inserts new elements in the list before the element at a specified position.
      * size() – Returns the number of elements in the list.
      * list resize()function in C++ STL– Used to resize a list container.
      * list unique() in C++ STL– Removes all duplicate consecutive elements from the list.
      * list::emplace() in C++ STL– emplace() function is used to insert a new element into the list container.
      * list::clear() in C++ STL– clear() function is used to remove all the elements of the list container, thus making it size 0.
      * list::operator= in C++ STL– This operator is used to assign new contents to the container by replacing the existing contents.
      * list splice() function in C++ STL– Used to transfer elements from one list to another.
      * list merge() function in C++ STL– Merges two sorted lists into one
      * list emplace() function in C++ STL– Extends list by inserting new element at a given position.
