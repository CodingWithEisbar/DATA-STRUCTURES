#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

//Create Node
struct Node {
	int Data;
	Node* pNext; //==> Next-Data
};

struct List {
	Node* pHead;
};

//Miscellaneous stuff
int length(List list)
{
	Node* tmp;
	int count = 0;
	for (tmp = list.pHead; tmp /*tmp->pNext!=NULL*/; tmp = tmp->pNext)
		count++;
	return count;
}

void printVec(vector<int> res)
{
	for (int i = 0; i < res.size(); i++) {
		cout << res[i]<<" ";
	}
}
//--------------------------------------------------------------------------------

Node* creatNode(int value)
{
	Node* temp = new Node;
	if (temp == NULL)
	{
		cout << "Error: Not enough memory!\n";

	}
	temp->Data = value;
	temp->pNext = NULL;
	return temp;
}

bool checkEmpty(Node* pHead)
{
	if (pHead == NULL) return true;
	return false;
}

void addHead(List &list, Node* p)
{
	if (checkEmpty(list.pHead))
	{
		//If pHead is empty
		list.pHead = p;
	}
	else
	{
		p->pNext = list.pHead;
		list.pHead = p;
	}
}

void addMiddle(List& list, Node* p, int position) 
{
	int n = length(list);
	
	if (checkEmpty(list.pHead))
		list.pHead = p;
	else if(position > n) {
		cout << "\n\tInvalid value!\n";
		return;

	}
	else {
		Node* temp = list.pHead;
		for (int i = 1; i < position; i++)
		{
			temp = temp->pNext;
		}
		p->pNext = temp->pNext;
		temp->pNext = p;
	}
}

void addTail(List &list, Node *p)
{
	if (checkEmpty(list.pHead))
	{
		list.pHead = p;
	}
	else
	{
		//Find last element
		Node* temp = list.pHead;
		while (temp->pNext != NULL)
			temp = temp->pNext;

		temp->pNext = p;
	}
}

void findIthElement(List list, int ith)
{
	Node* temp = list.pHead;
	for (int i = 1; i < ith; i++)
	{
		temp = temp->pNext;
	}
	cout << temp->Data << endl;
}

vector<int> findElementHasDataX(List list, int x)
{
	vector<int> res;
	int flag = 0;
	Node* temp = list.pHead;
	int n = length(list);
	for (int i = 1; i < n; i++) {
		if (temp->Data == x) {
			res.push_back(i);
			flag++;
		}
		temp = temp->pNext;
	}
	if (flag == 0) {
		cout << "\nValue not found.";
		return res;
	}
	
	return res;
	

}

void findLastElement(List list)
{
	Node* temp;
	for (temp = list.pHead; temp->pNext != NULL; temp = temp->pNext);
	cout << temp->Data;
}

void delFirstElement(List& list)
{
	Node* tail=list.pHead, *temp;
	//Locate tail
	while (tail->pNext != NULL)
		tail = tail->pNext;
	if (list.pHead == tail)
	{
		delete list.pHead;
		list.pHead = tail = NULL;
	}
	else {
		temp = list.pHead;
		list.pHead = list.pHead->pNext;
		delete temp;
	}
}



void delMidElement(List& list, int position)
{
	int n = length(list);
	if (position <= 1||position > n) {
		cout << "\n\tInvalid value!\n";
		return;
	}
	Node* del = list.pHead;
	Node* preDelElements = list.pHead ;
	for (int i = 1; i < position; i++) del = del->pNext;
	for (; preDelElements->pNext != del; preDelElements = preDelElements->pNext);
	preDelElements->pNext = del->pNext;
	delete del;
}

void delLastElement(List& list)
{
	
	Node* tail = list.pHead, *temp;
	//Locate tail
	while (tail->pNext != NULL)
		tail = tail->pNext;
	if (list.pHead == tail)
	{
		delete list.pHead;
		list.pHead = tail = NULL;
	}
	else {
	
		for (temp = list.pHead; temp->pNext != tail; temp = temp->pNext);
		delete tail;
		tail = temp;
		temp->pNext = NULL;
	}
}

void delAllElement(List& list)
{
	Node* del = list.pHead;
	while (del != NULL)
	{
		del = del->pNext;
		delete list.pHead;
		list.pHead = del;
	}
	cout << "\nLinked list remove succesfully!\n";
}

void printList(List list)
{
	Node* temp = list.pHead;
	while (temp != NULL) {
		cout << temp->Data<<endl;
		temp = temp->pNext;
	}


}

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