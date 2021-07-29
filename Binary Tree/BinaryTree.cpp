#include "Header.h"

//Duyệt NLR (Node-Left-Right):
/*In ra node gốc
Duyệt cây bên trái
Duyệt cây bên phải
*/
void NodeLeftRight(Node *pRoot)
{
    if (pRoot == NULL)
        return;
    cout << pRoot->key;
    NodeLeftRight(pRoot->left);
    NodeLeftRight(pRoot->right);
}

//Duyệt LNR (Left-Node-Right):
/*Duyệt cây bên trái trước
In ra node gốc 
Duyệt cây bên phải 
*/
void LeftNodeRight(Node *pRoot)
{
    if (pRoot == NULL)
        return;
    LeftNodeRight(pRoot->left);
    cout << pRoot->key;
    LeftNodeRight(pRoot->right);
}

//Duyệt LRN (Left-Right-Node):
/* Duyệt cây bên trái
Duyệt cây bên phải 
In ra node gốc 
*/
void LeftRightNode(Node *pRoot)
{
    if (pRoot == NULL)
        return;
    LeftRightNode(pRoot->left);
    LeftRightNode(pRoot->right);
    cout << pRoot->key;
}