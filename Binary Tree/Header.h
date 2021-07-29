#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

struct Node{
    int key;
    Node *left, *right; 
};

//Binary Traversal Functions: Các hàm duyệt cây nhị phân
void NodeLeftRight(Node *pRoot);
void LeftNodeRight(Node *pRoot);
void LeftRightNode(Node *pRoot);


#endif