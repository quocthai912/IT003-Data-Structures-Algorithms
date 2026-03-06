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
    int left = Height(T->pLeft);
    int right = Height(T->pRight);
    return (left > right ? left : right) + 1;
}

void DFS(TREE T, int h)
{
    if (T == nullptr)
        return;
    DFS(T->pLeft, h);
    if (Height(T) == h)
        cout << T->key << " ";
    DFS(T->pRight, h);
}

void Fun(TREE T)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    int h;
    cin >> h;
    if (h < 0 || h > Height(T))
    {
        cout << "No Node";
        return;
    }
    DFS(T, h);
}

int main()
{
    TREE T;
    CreateTree(T);
    Fun(T);
    return 0;
}