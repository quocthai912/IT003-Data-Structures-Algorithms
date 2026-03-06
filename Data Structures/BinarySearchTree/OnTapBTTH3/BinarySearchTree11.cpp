// Xóa 1 Node Trên Cây Nhị Phân Tìm Kiếm
// Node Thay Thế Là Node Con Nhỏ Nhất Bên Cây Con Phải (Min Right)
#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

TNODE *CreateTNODE(int key)
{
    TNODE *T = new TNODE;
    T->key = key;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
}
bool Insert(TREE &T, int key)
{
    if (T)
    {
        if (T->key == key)
            return false;
        else if (T->key < key)
            return Insert(T->pRight, key);
        else
            return Insert(T->pLeft, key);
    }
    T = CreateTNODE(key);
    return true;
}
void CreateTree(TREE &T)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        Insert(T, temp);
        cin >> temp;
    }
}
void SwapNode(TREE &T, TREE &Node)
{
    if (T->pLeft != nullptr)
        SwapNode(T->pLeft, Node);
    else
    {
        Node->key = T->key;
        Node = T;
        T = T->pRight;
    }
}
bool DeleteNode(TREE &T, int x)
{
    if (T == nullptr)
        return false;
    if (T->key < x)
        return DeleteNode(T->pRight, x);
    if (T->key > x)
        return DeleteNode(T->pLeft, x);
    if (T->key == x)
    {
        TNODE *node = T;
        if (T->pLeft != nullptr && T->pRight != nullptr)
        {
            SwapNode(T->pRight, node);
        }
        else if (T->pLeft == nullptr)
            T = T->pRight;
        else
            T = T->pLeft;
        delete node;
        return true;
    }
    return false;
}
void Preorder(TREE T)
{
    if (T == nullptr)
        return;
    cout << T->key << " ";
    Preorder(T->pLeft);
    Preorder(T->pRight);
}
void PrintTree(TREE T)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    Preorder(T);
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;

    DeleteNode(T, x);

    PrintTree(T);
    return 0;
}
