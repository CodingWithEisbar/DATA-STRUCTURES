#ifndef _BST_FUNCTION_H_
#define _BST_FUNCTION_H_

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

Node *createNode(int data);
void Insert (Node* &pRoot, int x);
void LevelOrder(Node* pRoot);
void Remove(Node *&pRoot, int x);
Node *createTree(int a[], int n);
void removeTree(Node *&pRoot);
Node *Search (Node* pRoot, int key);
int sumNode(Node *pRoot);
int CountNode(Node *pRoot);
int Height(Node* pRoot);
int Level(Node *pRoot, Node *p);
int countLeaf(Node *pRoot);
int countNode(Node *pRoot);
int countLess(Node *pRoot, int x);
int countGreater(Node *pRoot, int x);
bool isBST(Node *pRoot);
bool isFullBST(Node *pRoot);

//Stuff
int findMin(Node *pRoot);
int findMax(Node *pRoot);
bool isBST(Node *pRoot);



#endif