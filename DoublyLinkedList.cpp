#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct d_Node{
    int key;
    d_Node* pNext;
    d_Node* pPrev;

};

struct d_List{
    d_Node* pHead;
    d_Node* pTail;
};

d_Node* createNode(int data)
{
    d_Node* p = new d_Node;
    p->key = data;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}


d_List* createList(d_Node *pNode)
{
    d_List List;
    List.pHead = pNode;
    List.pTail = pNode;
    return List;
}



int main(){

    return 0;
}