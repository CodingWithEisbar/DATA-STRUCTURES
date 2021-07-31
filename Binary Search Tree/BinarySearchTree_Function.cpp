#include "Header.h"

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

void Insert(Node *&pRoot, int x)
{
    if (pRoot == NULL)
    {
        pRoot = createNode(x);
        return;
    }
    if (pRoot->key > x)
        Insert(pRoot->left, x);
    if (pRoot->key < x)
        Insert(pRoot->right, x);
}

void LevelOrder(Node *pRoot)
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
        cout << temp->key << "  ";
    }
}

void Remove(Node *&pRoot, int x)
{
    if (pRoot == NULL)
        return;
    if (pRoot->key > x)
    {
        Remove(pRoot->left, x);
    }
    if (pRoot->key < x)
    {
        Remove(pRoot->right, x);
    }
    if (pRoot->key == x)
    {
        if (pRoot->left == NULL && pRoot->right == NULL)
        {
            //Trường hợp cây không có con
            delete pRoot;
            pRoot = NULL;
            return;
        }
        if (pRoot->left != NULL && pRoot->right == NULL)
        {
            //Trường hợp có 1 con bên trái
            Node *p = pRoot;
            pRoot = pRoot->left;
            delete p;
            return;
        }
        if (pRoot->left == NULL && pRoot->right != NULL)
        {
            //Trường hợp có 1 con bên phải
            Node *p = pRoot;
            pRoot = pRoot->right;
            delete p;
            return;
        }
        if (pRoot->left != NULL && pRoot->right != NULL)
        {
            //Trường hợp có 2 con
            Node *p = pRoot->right;
            while (p->left != NULL)
            {
                p = p->left; //Node con trái nhất của bên phải
                //Có thể thay thế bằng node phải nhất của bên trái
            }
            pRoot->key = p->key;
            Remove(pRoot->right, pRoot->key);
        }
    }
}

Node *createTree(int a[], int n)
{
    Node *pRoot = NULL;
    for (int i = 0; i < n; i++)
    {
        Insert(pRoot, a[i]);
    }
    return pRoot;
}

void removeTree(Node *&pRoot)
{
    while (pRoot != NULL)
    {
        Remove(pRoot, pRoot->key);
    }
}

int Level(Node *pRoot, Node *p)
{
    if (pRoot == NULL)
        return 0;
    queue<Node *> q1;
    queue<int> q2;
    q1.push(pRoot);
    q2.push(1);
    while (!q1.empty())
    {
        Node *temp = q1.front();
        q1.pop();
        int level = q2.front();
        q2.pop();
        if (temp == p)
            return level;
        if (temp->left != NULL)
        {
            q1.push(temp->left);
            q2.push(level + 1);
        }
        if (temp->right != NULL)
        {
            q1.push(temp->right);
            q2.push(level + 1);
        }
    }
    return 0;
}

int countLeaf(Node *pRoot)
{
    if (pRoot == NULL)
        return 0;
    if (pRoot->left == NULL && pRoot->right == NULL)
        return 1;
    return countLeaf(pRoot->left) + countLeaf(pRoot->right);
}

int countNode(Node *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return countNode(pRoot->left) + countNode(pRoot->right) + 1;
}

int countLess(Node *pRoot, int x)
{
    if (pRoot == NULL)
        return 0;
    if (pRoot->key == x)
    {
        return countNode(pRoot->left);
    }
    if (pRoot->key < x)
    {
        return countNode(pRoot->left) + 1 + countLess(pRoot->right, x);
    }
    if (pRoot->key > x)
    {
        return countLess(pRoot->left, x);
    }
}

int countMore(Node *pRoot, int x)
{
    if (pRoot == NULL)
        return 0;
    if (pRoot->key == x)
    {
        return countNode(pRoot->right);
    }
    if (pRoot->key > x)
    {
        return countNode(pRoot->right) + 1 + countMore(pRoot->left, x);
    }
    if (pRoot->key < x)
    {
        return countMore(pRoot->right, x);
    }
}

int findMin(Node *pRoot)
{
    if (pRoot == NULL)
        return 1000000;
    return min(min(findMin(pRoot->left), findMin(pRoot->right)), pRoot->key);
}

int findMax(Node *pRoot)
{
    if (pRoot == NULL)
        return 1000000;
    return max(max(findMax(pRoot->left), findMax(pRoot->right)), pRoot->key);
}

bool isBST(Node *pRoot)
{
    if (pRoot == NULL)
        return true;
    if (pRoot->key < findMin(pRoot->right) && pRoot->key > findMax(pRoot->left))
    {
        return isBST(pRoot->left) && isBST(pRoot->right);
    }
}

bool isFullBST(Node *pRoot)
{
    if (pRoot == NULL)
        return true;
    if (pRoot->left == NULL && pRoot->right == NULL)
        return true;
    if (pRoot->left != NULL && pRoot->right != NULL)
        return isBST(pRoot) && isFullBST(pRoot->left) && isFullBST(pRoot->right);
}