#include <iostream>
#include <algorithm>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    // int height;
    // Một số bài toán sẽ yêu cầu có thêm giá trị height trong Node AVL
};

//1.
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

void balance(Node *&pRoot)
{
    int bal = Height(pRoot->left) - Height(pRoot->right);
    if (bal > 1)
    {                                                                //Cây lệch trái
        if (Height(pRoot->left->left) >= Height(pRoot->left->right)) //Cây lệch trái trái
            rightRotate(pRoot);
        if (Height(pRoot->left->left) < Height(pRoot->left->right))
        { //Cây lệch trái phải
            leftRotate(pRoot->left);
            rightRotate(pRoot);
        }
    }
    if (bal < -1)
    {                                                                  //Cây lệch phải
        if (Height(pRoot->right->right) >= Height(pRoot->right->left)) //Cây lệch phải phải
            leftRotate(pRoot);
        if (Height(pRoot->right->right) < Height(pRoot->right->left))
        { //Cây lệch phải trái
            rightRotate(pRoot->right);
            leftRotate(pRoot);
        }
    }
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
    int balance = Height(pRoot->left) - Height(pRoot->right);
    if (balance > 1)
    { //Mất cân bằng trái
        //Trường hợp mất cân bằng trái-trái
        if (Height(pRoot->left->left) > Height(pRoot->left->right))
        {
            rightRotate(pRoot);
        }
        //Trường hợp mất cân bằng trái-phải
        if (Height(pRoot->left->left) < Height(pRoot->left->right))
        {
            leftRotate(pRoot->left);
            rightRotate(pRoot);
        }
    }
    if (balance < -1)
    { //Mất cân bằng phải
        //Trường hợp mất cân bằng phải phải
        if (Height(pRoot->right->right) > Height(pRoot->right->left))
        {
            leftRotate(pRoot);
        }
        //Trường hợp mất cân bằng trái trái
        if (Height(pRoot->right->right) < Height(pRoot->right->left))
        {
            rightRotate(pRoot->right);
            leftRotate(pRoot);
        }
    }
}

Node *createTree(int a[], int n)
{
    Node *p = NULL;
    for (int i = 0; i < n; i++)
    {
        Insert(p, a[i]);
    }
    return p;
}

void LevelOrder(Node *pRoot)
{
    if(pRoot == NULL) return;
    queue <Node*> q;
    q.push(pRoot);

    while(!q.empty()){
        Node *p = q.front();
        q.pop();
        if(p->left != NULL){
            q.push(p->left);
        }
        if(p->right != NULL){
            q.push(p->right);
        }
        cout << p->key << "  ";
    }
}

void Remove(Node* &pRoot, int x)
{
    if(pRoot == NULL) return;
    if(pRoot->key > x)
        Remove(pRoot->left,x);
    else if(pRoot->key < x)
        Remove(pRoot->right,x);
    else if(pRoot->key == x){
        if(pRoot->left == NULL && pRoot->right == NULL){
            //Giả sử node 0 có con
            delete pRoot;
            pRoot = NULL;
        }
        else if(pRoot->left != NULL && pRoot->right == NULL){
            Node* p = pRoot->left;
            pRoot = pRoot->left;
            delete p;
        }
        else if(pRoot->left == NULL && pRoot->right == NULL){
            Node* p = pRoot->right;
            pRoot = pRoot->right;
            delete p;
        }
        else if(pRoot->left == NULL && pRoot->right == NULL){
            Node* p = pRoot->right;
            while(p->left != NULL){
                p = p->left;
            }
            pRoot->key = p->key;
            Remove(pRoot->right, pRoot->key);
        }
    }
    if(pRoot == NULL) return;
    balance(pRoot);
}

//Check AVL Tree
int minNode(Node *pRoot)
{
    if (pRoot == NULL)
        return 1000000;
    return min(min(minNode(pRoot->left), minNode(pRoot->right)), pRoot->key);
}

int maxNode(Node *pRoot)
{
    if (pRoot == NULL)
        return 1000000;
    return max(max(maxNode(pRoot->left), maxNode(pRoot->right)), pRoot->key);
}

//.19
bool isBST(Node *pRoot)
{
    if (pRoot == NULL)
        return true;
    if (pRoot->key < minNode(pRoot->right) && pRoot->key > maxNode(pRoot->left))
    {
        return isBST(pRoot->left) && isBST(pRoot->right);
    }
}

bool isAVL(Node *pRoot)
{
    if(pRoot == NULL) return true;
    int bal = Height(pRoot->left) - Height(pRoot->right);
    return (bal > -2) && (bal < 2) && isBST(pRoot) && isAVL(pRoot->left) && isAVL(pRoot->right);
}


int main()
{
    int a[9] = {10, 30, 50, 40, 45, 60, 5, 1, 9};
    Node *pRoot = createTree(a, 9);
    Remove(pRoot, 100);
    LevelOrder(pRoot);

    return 0;
}