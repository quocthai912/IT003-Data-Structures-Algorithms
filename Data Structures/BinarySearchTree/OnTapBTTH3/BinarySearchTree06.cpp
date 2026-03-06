// Liệt kê các node trong cây có chiều cao lớn hơn chiều cao của Node X.
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
    T = nullptr;
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        Insert(T, temp);
        cin >> temp;
    }
}
int Height(TREE T)
{
    if (T == nullptr)
        return -1;
    int left = Height(T->pLeft);
    int right = Height(T->pRight);
    return (left > right ? left : right) + 1;
}
TNODE *search(TREE T, int key)
{
    if (T == nullptr)
        return nullptr;
    if (T->key == key)
        return T;
    else if (T->key < key)
        return search(T->pRight, key);
    return search(T->pLeft, key);
}
void DFS(TREE T, int height, bool &find)
{
    if (T == nullptr)
        return;
    if (Height(T) > height)
    {
        cout << T->key << " ";
        find = true;
    }
    DFS(T->pLeft, height, find);
    DFS(T->pRight, height, find);
}
void PrintTree(TREE T)
{
    int x;
    cin >> x;
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    TNODE *X = search(T, x);
    if (X == nullptr)
    {
        cout << "NotFound";
        return;
    }
    bool find = false;
    int heightX = Height(X);
    DFS(T, heightX, find);
    if (!find)
    {
        cout << "NotFound";
        return;
    }
}
int main()
{
    TREE T;
    CreateTree(T);
    PrintTree(T);
    return 0;
}
