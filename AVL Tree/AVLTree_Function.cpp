#include "AVLTree_Header.h"

Node *createNode(int data)
{
    Node *temp = new Node;
    if (temp == NULL)
        cout << "Error: Not enough memory!\n";
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int Height(Node *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return max(Height(pRoot->left), Height(pRoot->right)) + 1;
}


void leftRotate(Node *&pRoot)
{
    Node *p = pRoot->right;
    pRoot->right = p->left;
    p->left = pRoot->right;
    pRoot = p;
}

void rightRotate(Node *&pRoot)
{
    Node *p = pRoot->left;
    pRoot->left = p->right;
    p->right = pRoot;
    pRoot = p;
}

void Insert(Node *&pRoot, int value)
{
    if (pRoot == NULL)
    {
        pRoot = createNode(value);
    }
    if (pRoot->key == value)
        return;
    if (pRoot->key > value)
        Insert(pRoot->left, value);
    if (pRoot->key < value)
        Insert(pRoot->right, value);
    int balance = Height(pRoot->left)  - Height(pRoot->right);


}