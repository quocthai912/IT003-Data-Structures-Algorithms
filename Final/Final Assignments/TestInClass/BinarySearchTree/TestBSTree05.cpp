/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
template
class
typedef
vector
pair
set
map
exit
[
]
###End banned keyword*/

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

bool InsertTree(TREE &T, int key)
{
    if (T)
    {
        if (T->key == key)
            return false;
        else if (T->key < key)
            return InsertTree(T->pRight, key);
        else
            return InsertTree(T->pLeft, key);
    }
    T = CreateTNODE(key);
    return true;
}

void CreateTree(TREE &T)
{
    T = nullptr;
    int key;
    cin >> key;
    while (key != -1)
    {
        InsertTree(T, key);
        cin >> key;
    }
}

int Height(TREE T)
{
    if (T == nullptr)
        return -1;
    int Left = Height(T->pLeft);
    int Right = Height(T->pRight);
    return (Left > Right ? Left : Right) + 1;
}

void DFS(TREE T, int level, bool &found)
{
    if (T == nullptr)
        return;
    DFS(T->pLeft, level + 1, found);
    if (level == Height(T))
    {
        cout << T->key << " ";
        found = true;
    }
    DFS(T->pRight, level + 1, found);
}

void Fun(TREE T)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    bool found = false;
    DFS(T, 0, found);
    if (!found)
        cout << "No Node";
}

int main()
{
    TREE T;
    CreateTree(T);
    Fun(T);
    return 0;
}
