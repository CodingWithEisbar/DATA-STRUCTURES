#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct d_Node
{
    int key;
    d_Node *pNext;
    d_Node *pPrev;
};

struct d_List
{
    d_Node *pHead;
    d_Node *pTail;
};

d_Node *createNode(int data)
{
    d_Node *p = new d_Node;
    p->key = data;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}

d_List createList(d_Node *pNode)
{
    d_List List;
    List.pHead = pNode;
    List.pTail = pNode;
    return List;
}

bool addHead(d_List &List, int data)
{
    if (List.pHead == NULL)
    {
        d_Node *p = createNode(data);
        if (p != NULL)
        {
            List = createList(p);
            return true;
        }
        return false;
    }
    d_Node *p = createNode(data);
    if (p != NULL)
    {
        p->pNext = List.pHead;
        List.pHead->pPrev = p;
        List.pHead = p;
        return true;
    }
    return false;
}

bool addTail(d_List &List, int data)
{
    if (List.pHead == NULL)
    {
        d_Node *p = createNode(data);
        if (p != NULL)
        {
            List = createList(p);
            return true;
        }
        return false;
    }
    d_Node *p = createNode(data);
    if (p != NULL)
    {
        p->pPrev = List.pTail;
        List.pTail->pNext = p;
        List.pTail = p;
    }
    return false;
}

void printForward(d_List List)
{
    if (List.pHead == NULL)
        return;
    d_Node *temp = List.pHead;
    while (temp != NULL)
    {
        cout << temp->key << " ";
        temp = temp->pNext;
    }
}

void printBackward(d_List List)
{
    if (List.pHead == NULL)
        return;
    d_Node *temp = List.pTail;
    while (temp != NULL)
    {
        cout << temp->key << " ";
        temp = temp->pPrev;
    }
}

void removeHead(d_List &List)
{
    if (List.pHead == NULL)
        return;
    //Nếu list có 1 node
    if (List.pHead == List.pTail)
    {
        d_Node *temp = List.pHead;
        List.pHead = NULL;
        List.pTail = NULL;
        delete temp;
        return;
    }
    d_Node *temp = List.pHead;
    List.pHead = List.pHead->pNext;
    List.pHead->pPrev = NULL;
    delete temp;
}

void removeTail(d_List &List)
{
    if (List.pHead == NULL)
        return;
    //Nếu list có 1 node
    if (List.pHead == List.pTail)
    {
        d_Node *temp = List.pHead;
        List.pHead = NULL;
        List.pTail = NULL;
        delete temp;
        return;
    }
    d_Node *temp = List.pTail;
    List.pTail = List.pTail->pPrev;
    List.pTail->pNext = NULL;
    delete temp;
}

void removeAll(d_List &List)
{
    if (List.pHead == NULL)
        return;
    d_Node *temp = List.pTail;
    while (temp != NULL)
    {
        temp = temp->pPrev;
        removeTail(List);
    }
}

void removeBefore(d_List &List, int value)
{
    if (List.pHead == NULL)
        return;
    if (List.pHead->pNext == NULL)
        return; //TH list có duy nhất 1 node
    d_Node *p1 = List.pHead->pNext;
    while (p1->key != value)
    {
        p1 = p1->pNext;
    }
    d_Node *p2 = p1->pPrev;
    if (p2 == List.pHead){
        return removeHead(List);
    }
    p1->pPrev = p2->pPrev;
    p2->pPrev->pNext = p1;
    delete p2;
}

void removeAfter(d_List &List, int value)
{
    if(List.pHead == NULL) return;
    if(List.pHead->pNext == NULL) return; //List có duy nhất 1 node
    d_Node* p1 = List.pHead;
    while(p1->key != value){
        p1 = p1->pNext;
    }
    d_Node* p2 = p1->pNext;
    if(p2 == List.pTail)
        return removeTail(List);
    p1->pNext = p2->pNext;
    p2->pNext->pPrev = p1;
    delete p2;
}

void removeDuplicate(d_List &List)
{
    if(List.pHead == NULL) return;
    if(List.pHead->pNext == NULL) return;
    d_List List1 = createList(createNode(List.pHead->key));
    d_Node* p = List.pHead->pNext;
    d_Node* p1;
    bool check = false;
    while (p != NULL){
        p1 = List1.pHead;
        while(p1 != NULL){
            if(p1->key == p->key){
                check = true;
                break;
            }
            p1 = p1->pNext;
        }
        if(check == false){
            addTail(List1, p->key);
        }
        check = false;
        p = p->pNext;
    }
    List = List1;
}


int main()
{
    d_List List;
    List.pHead = NULL;
    List.pTail = NULL;
    addHead(List, 1);
    addHead(List, 0);
    addTail(List, 2);
    addTail(List, 2);
    addTail(List, 3);
    addTail(List, 3);
    cout<<"\nBefore: "<<endl;
    printForward(List);
    cout << endl;
    printBackward(List);
    //removeBefore(List, 3);
    removeDuplicate(List);
    cout<<"\nAfter: "<<endl;
    printForward(List);
    cout << endl;
    printBackward(List);

    removeAll(List);
    if (List.pHead == NULL)
        cout << "\nRelax comrade, nothing gonna happen" << endl;
    return 0;
}