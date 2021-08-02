//Singly Linked List
#include "SinglyLinkedList_Header.h"
#include <iostream>
using namespace std;

int main() {
	List list;
	list.pHead = NULL;

	//Create node n1
	Node* n1 = creatNode(1);
	addHead(list, n1); //Set n1 to be the head of list

	//Create node n2 and add to head
	Node* n2 = creatNode(2);
	addHead(list, n2);

	//Create node n3 and add to tail
	Node* n3 = creatNode(3);
	addTail(list, n3);

	//Create node n4 and add to the middle of the list
	Node* n4 = creatNode(4);
	int insPosition;
	cout << "\n-----------------------------------";
	cout << "\nEnter position want to insert: ";
	cin >> insPosition;
	addMiddle(list, n4, insPosition);
	printList(list);

	//Find i(th) element
	int i;
	cout << "\n-----------------------------------";
	cout << "\nFind i(th) element.";
	cout << "\nPlease enter i: ";
	cin >> i;
	cout << "\nValue: ";
	findIthElement(list, i);

	//Find element has data x
	int x;
	vector<int> res;
	cout << "\n-----------------------------------";
	cout << "\nFind element has data x.";
	cout << "\nPlease enter x: ";
	cin >> x;
	cout << "\nPositions: ";
	res = findElementHasDataX(list, x);
	printVec(res);

	//Find last element
	cout << "\n-----------------------------------";
	cout << "\nFind last element.";
	cout << "\nThe last element: ";
	findLastElement(list);


	//Remove head
	cout << "\n-----------------------------------";
	cout << "\n -> Add 5 in the end of list: \n";
	Node* n5 = creatNode(5);
	addTail(list, n5);
	printList(list);
	cout << "\n-----------------------------------";
	cout << "\nDelete first element: \n";
	delFirstElement(list);
	printList(list);

	//Remove middle
	cout << "\n-----------------------------------";
	cout << "\n -> Add 7 in the end of list: \n";
	Node* n7 = creatNode(7);
	addTail(list, n7);
	printList(list);
	cout << "\n-----------------------------------";
	cout << "\nDelete middle element";
	int delPosition;
	cout << "\nEnter value position: ";
	cin >> delPosition;
	delMidElement(list,delPosition);
	printList(list);

	
	//Remove tail
	cout << "\n-----------------------------------";
	cout << "\n -> Add 6 in the end of list: \n";
	Node* n6 = creatNode(6);
	addTail(list, n6);
	printList(list);
	cout << "\n-----------------------------------";
	cout << "\nDelete last element: \n";
	delLastElement(list);
	printList(list);

	//Remove all
	cout << "\n-----------------------------------";
	cout << "\nDelete all elements. ";
	cout << "\nBefore delete: \n";
	printList(list);
	cout << "\nAfter delete: ";
	delAllElement(list);
	printList(list);

	return 0;
}