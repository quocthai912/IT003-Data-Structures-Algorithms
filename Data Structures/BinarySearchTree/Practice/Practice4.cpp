// Xuất các Node có chiều cao cây con Trái < chiều cao cây con Phải
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *Tree;

TNODE *CreateTNODE(int val)
{
    TNODE *T = new TNODE;
    T->key = val;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
}

bool InsertNode(Tree &T, int val)
{
    if (T)
    {
        if (T->key == val)
            return false;
        else if (T->key < val)
            return InsertNode(T->pRight, val);
        else
            return InsertNode(T->pLeft, val);
    }
    T = CreateTNODE(val);
    return true;
}
int Height(Tree T)
{
    if (T == nullptr)
        return -1;
    int a = Height(T->pLeft);
    int b = Height(T->pRight);
    return (a > b ? a : b) + 1;
}
void CreateTree(Tree &T)
{
    T = nullptr;
    int temp;
    cin >> temp;

    while (temp != -1)
    {
        InsertNode(T, temp);
        cin >> temp;
    }
}
void DuyetDFS(Tree T, bool &found)
{
    if (T == nullptr)
        return;
    if (Height(T->pLeft) < Height(T->pRight))
    {
        cout << T->key << " ";
        found = true;
    }
    DuyetDFS(T->pLeft, found);
    DuyetDFS(T->pRight, found);
}
void Find(Tree T)
{
    if (T == nullptr)
    {
        cout << "Empty";
        return;
    }
    bool found = false;
    DuyetDFS(T, found);
    if (!found)
    {
        cout << "NotFound";
        return;
    }
}
int main()
{
    Tree T;
    CreateTree(T);
    Find(T);
    return 0;
}
