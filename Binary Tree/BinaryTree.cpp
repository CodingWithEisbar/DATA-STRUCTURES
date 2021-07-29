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

//Lever Order:
//In ra các node từ mức cao tới thấp, từ trái sang phải
void levelOrder(Node *pRoot)
{
    if (pRoot == NULL)
        return;
    queue<Node *> q;
    q.push(pRoot);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
        cout << temp->key;
    }
}
