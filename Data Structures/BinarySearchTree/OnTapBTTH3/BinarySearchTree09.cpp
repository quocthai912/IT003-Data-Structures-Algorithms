// Tìm và liệt kê tất cả các node lá nằm ở tầng sâu nhất của cây (có độ sâu tối đa).
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
void DFS(TREE T, int level, int height)
{
    if (T == nullptr)
        return;
    DFS(T->pLeft, level + 1, height);
    if (T->pLeft == nullptr && T->pRight == nullptr)
    {
        if (level == height)
            cout << T->key << " ";
    }
    DFS(T->pRight, level + 1, height);
}
void PrintTree(TREE T)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    int height = Height(T);
    DFS(T, 0, height);
}
int main()
{
    TREE T;
    CreateTree(T);
    PrintTree(T);
    return 0;
}
