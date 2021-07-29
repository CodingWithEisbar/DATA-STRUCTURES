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

//Lever Order: In ra các node từ mức cao tới thấp, từ trái sang phải
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

//Height: Số node trên đường đi dài nhất từ node gốc tới node lá
int Height(Node *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return max(Height(pRoot->left), Height(pRoot->right)) + 1;
}

int countNode(Node *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return countNode(pRoot->left) + countNode(pRoot->right) + 1;
}

int sumNode(Node *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return sumNode(pRoot->left) + sumNode(pRoot->right) + pRoot->key;
}

//Height-of-Node: Chiều cao của 1 node là chiều cao của cây được tạo bởi node đó
int heightNode(Node *pRoot, int value)
{
    if (pRoot == NULL)
        return 0;
    if (pRoot->key == value)
        return Height(pRoot);
    return heightNode(pRoot->left, value) + heightNode(pRoot->right, value);
}

int Level(Node *pRoot, Node *p)
{
    if (pRoot == NULL)
        return 0;
    queue<Node *> q1; //Chứa các node trên cây
    queue<int> q2;    //chứa level tương ứng của node trong q1

    q1.push(pRoot);
    q2.push(1);
    while (!q1.empty())
    {
        Node *temp = q1.front(); //Lấy giá trị phần tử đầu tiên của q1
        q1.pop();                //Xoá giá trị đầu tiên khỏi q1
        int x = q2.front();
        q2.pop();
        if (temp == p)
        {
            return x;
        }
        if (temp->left != NULL)
        {
            q1.push(temp->left);
            q2.push(x + 1);
        }
        if(temp->right != NULL){
            q1.push(temp->right);
            q2.push(x + 1);
        }
    }
    return 0;
}

int countLeaf(Node *pRoot)
{
    if(pRoot == NULL) return 0;
    if(pRoot->left == NULL && pRoot->right == NULL) return 1;
    return countLeaf(pRoot->left) + countLeaf(pRoot->right);
}