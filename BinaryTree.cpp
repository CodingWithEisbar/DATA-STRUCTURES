#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

Node *createNode(int Data)
{
    Node *temp = new Node;
    if (temp == NULL)
        cout << "Error: Not enough memory!\n";
    temp->key = Data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//Nguồn: https://www.studytonight.com/post/insertion-adding-a-new-node-in-a-binary-tree-data-structure
void Insert(Node *&pRoot, int x)
{
    if (pRoot == NULL)
    {
        pRoot = createNode(x);
        return;
    }
    Node *temp;
    queue<Node *> q;
    q.push(pRoot);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        //Chèn node bên trái của rễ
        if (temp->left == NULL)
        {
            temp->left = createNode(x);
            break;
        }
        //Nếu node bên trái đó không mang giá trị NULL thì tiến hành push vào queue
        else
            q.push(temp->left);

        //Chèn node về phía tay phải của rễ
        if (temp->right == NULL)
        {
            temp->right = createNode(x);
            break;
        }
        //Nếu node phải đó cũng không mang giá trị NULL thì tiến hành push vào queue
        else
            q.push(temp->right);
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
//Duyệt NLR (PreOrder Travesal)
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

//Duyệt LNR (InOrder Travesal)
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

//Duyệt LRN (PostOrder Travesal)
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
        if (temp->right != NULL)
        {
            q1.push(temp->right);
            q2.push(x + 1);
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

//Xoá cây nhị phân
/*Chúng ta sẽ duyệt cây theo kiểu PostOrder sau đó 
xoá lần lượt ptử bên trái bên phải của cây và cuối cùng là node gốc của cây*/
void deleteTreeMechanism(Node *pRoot)
{
    if (pRoot == NULL)
        return;

    //Đầu tiên chúng ta xoá hai node con của 1 node gốc
    deleteTreeMechanism(pRoot->left);
    deleteTreeMechanism(pRoot->right);

    //Sau đó là delete node gốc
    delete pRoot;
}

void deleteTree(Node **pRoot_ref)
{
    deleteTreeMechanism(*pRoot_ref);
    *pRoot_ref = NULL;
    cout << "Tree Deleted" << endl;
    /*Nếu không set phần tử Root = NULL thì sẽ gây ra lỗi nếu user 
    cố gắng sử dụng con trỏ root để truy cập vào giá trị*/
}

int main()
{
    Node *pRoot = NULL;
    int a[10] = {12, 15, 16, 11, 2, 4, 5, 6, 7, 10};
    pRoot = createTree(a,10);
    LeftNodeRight(pRoot);
    deleteTree(&pRoot);
    return 0;
}