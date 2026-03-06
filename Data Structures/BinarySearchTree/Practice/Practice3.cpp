// Node 2 con có chiều cao thấp nhất
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
int Height(const Tree &T)
{
    if (T == nullptr)
        return -1;
    int Left = Height(T->pLeft);
    int Right = Height(T->pRight);
    return (Left > Right ? Left : Right) + 1;
}
void minHeightTwoChildren(const Tree &T, int &minHeight, bool &check)
{
    if (T == nullptr)
        return;
    if (T->pLeft != nullptr && T->pRight != nullptr)
    {
        if (Height(T) < minHeight)
            minHeight = Height(T);
        check = true;
    }
    minHeightTwoChildren(T->pLeft, minHeight, check);
    minHeightTwoChildren(T->pRight, minHeight, check);
}
void DuyetDFS(const Tree &T, int minHeight)
{
    if (T == nullptr)
        return;
    if (T->pLeft != nullptr && T->pRight != nullptr)
    {
        if (Height(T) == minHeight)
            cout << T->key << " ";
    }
    DuyetDFS(T->pLeft, minHeight);
    DuyetDFS(T->pRight, minHeight);
}
void Find(Tree T)
{
    if (T == nullptr)
    {
        cout << "Empty";
        return;
    }
    int minHeight = INT_MAX;
    bool check = false;
    minHeightTwoChildren(T, minHeight, check);
    if (!check)
    {
        cout << "NotFound";
        return;
    }
    DuyetDFS(T, minHeight);
}
int main()
{
    Tree T;
    CreateTree(T);
    Find(T);
    return 0;
}
