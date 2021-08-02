// Đây là tổng hợp các hàm tiện ích dành cho kiểu cấu trúc dữ liệu Singly Linked List 
#include "SinglyLinkedList_Header.h""

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