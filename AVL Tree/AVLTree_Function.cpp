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
    if(balance > 1){ //Mất cân bằng trái
        //Trường hợp mất cân bằng trái-trái
        if(Height(pRoot->left->left) > Height(pRoot->left->right)){
            rightRotate(pRoot);
        }
        //Trường hợp mất cân bằng trái-phải
        if(Height(pRoot->left->left) < Height(pRoot->left->right)){
            leftRotate(pRoot->left);
            rightRotate(pRoot);
        }
    }
    if(balance < -1){//Mất cân bằng phải
        //Trường hợp mất cân bằng phải phải
        if(Height(pRoot->right->right) > Height(pRoot->right->left)){
            leftRotate(pRoot);
        }
        //Trường hợp mất cân bằng trái trái
        if(Height(pRoot->right->right) < Height(pRoot->right->left)){
            rightRotate(pRoot->right);
            leftRotate(pRoot); 
        }
    }

}