#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


struct Node{
    int key;
    Node *left, *right;
    // int height; 
    // Một số bài toán sẽ yêu cầu có thêm giá trị height trong Node AVL
};

//Stuff
Node *createNode(int data);
int Height(Node *pRoot);

//Các hàm thao tác với cây AVL
void leftRotate(Node* &pRoot);
void rightRotate(Node *&pRoot);



#endif