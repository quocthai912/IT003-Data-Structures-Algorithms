// Liệt kê node có chiều cao > độ sâu
#include <iostream>
#include <queue>
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
void DuyetDFS(const Tree &T, int Depth, bool &check)
{
    if (T == nullptr)
        return;
    if (Height(T) > Depth)
    {
        check = true;
        cout << T->key << " ";
    }
    DuyetDFS(T->pLeft, Depth + 1, check);
    DuyetDFS(T->pRight, Depth + 1, check);
}
void Find(Tree T)
{
    if (T == nullptr)
    {
        cout << "Empty";
        return;
    }
    bool check = false;
    DuyetDFS(T, 0, check);
    if (!check)
    {
        cout << "NotFound";
    }
}

int main()
{
    Tree T;
    CreateTree(T);
    Find(T);
    return 0;
}
