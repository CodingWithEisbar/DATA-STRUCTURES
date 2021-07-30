#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
    int key;
    Node *left, *right; 
};

//Binary Tree Traversal Functions: Các hàm duyệt cây nhị phân
void NodeLeftRight(Node *pRoot);
void LeftNodeRight(Node *pRoot);
void LeftRightNode(Node *pRoot);

//Các hàm thao tác với cây nhị phân
Node *creatNode(int Data);
void Insert(Node *&pRoot, int x);
//Lab 4
void levelOrder(Node *pRoot);
int Height(Node *pRoot);
int countNode(Node *pRoot);
int sumNode(Node *pRoot);
int heightNode(Node *pRoot, int value);
int Level(Node *pRoot, Node *p);
int countLeaf(Node *pRoot);

#endif