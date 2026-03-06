// Tính độ sâu của Node X
// Có template
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <queue>
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
void DFS(TREE T, int x, int level, int &levelNode)
{
    if (T == nullptr)
        return;
    if (T->key == x)
    {
        levelNode = level;
        return;
    }
    DFS(T->pLeft, x, level + 1, levelNode);
    DFS(T->pRight, x, level + 1, levelNode);
}
void PrintLevel(TREE T, int x, int &level)
{
    DFS(T, x, 0, level);
}
int main()
{
    TNODE *T;
    int x, level = -1;

    cin >> x;

    T = NULL;
    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
    {
        PrintLevel(T, x, level);
        cout << level;
    }
    return 0;
}
