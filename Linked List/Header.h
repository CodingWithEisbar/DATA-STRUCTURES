#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_

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
int length(List list);
bool checkEmpty(Node* pHead);
void printVec(vector<int> res);

Node* creatNode(int value);
void addHead(List& list, Node* p);
void addTail(List& list, Node* p);
void addMiddle(List& list, Node* p, int position);
void findIthElement(List list, int ith);
vector<int> findElementHasDataX(List list, int x);
void findLastElement(List list);
void delFirstElement(List& list);
void delMidElement(List& list, int position);
void delLastElement(List& list);
void delAllElement(List& list);
void printList(List list);


#endif