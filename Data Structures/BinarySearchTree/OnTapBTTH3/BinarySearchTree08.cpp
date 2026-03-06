// Liệt kê Node lá có độ sâu thấp nhất
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
void DFS(TREE T, int level, int &MinLevel)
{
    if (T == nullptr)
        return;
    // Nếu là Node lá, so sánh và tìm Level
    if (T->pLeft == nullptr && T->pRight == nullptr)
    {
        if (level < MinLevel)
        {
            MinLevel = level;
        }
    }
    DFS(T->pLeft, level + 1, MinLevel);
    DFS(T->pRight, level + 1, MinLevel);
}
int Height(TREE T)
{
    if (T == nullptr)
        return -1;
    int Left = Height(T->pLeft);
    int Right = Height(T->pRight);
    return (Left > Right ? Left : Right) + 1;
}
void PrintTree(TREE T, int level, int minLevel)
{
    if (T == nullptr)
        return;
    PrintTree(T->pLeft, level + 1, minLevel);
    if (T->pLeft == nullptr && T->pRight == nullptr)
    {
        if (level == minLevel)
            cout << T->key << " ";
    }
    PrintTree(T->pRight, level + 1, minLevel);
}
void Print(TREE T)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    int minLevel = Height(T);
    DFS(T, 0, minLevel);
    PrintTree(T, 0, minLevel);
}
int main()
{
    TREE T;
    CreateTree(T);
    Print(T);
    return 0;
}
