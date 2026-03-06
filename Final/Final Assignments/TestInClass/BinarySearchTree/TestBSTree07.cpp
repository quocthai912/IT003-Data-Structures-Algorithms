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

bool InsertBST(TREE &T, int key)
{
    if (T)
    {
        if (T->key == key)
            return false;
        else if (T->key < key)
            return InsertBST(T->pRight, key);
        else
            return InsertBST(T->pLeft, key);
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
        InsertBST(T, key);
        cin >> key;
    }
}

void DFS(TREE T, int x)
{
    if (T == nullptr)
        return;
    DFS(T->pLeft, x);
    if (T->key != x)
        cout << T->key << " ";
    DFS(T->pRight, x);
}

TNODE *Search(TREE T, int key)
{
    if (T == nullptr)
        return nullptr;
    if (T->key == key)
        return T;
    else if (T->key < key)
        return Search(T->pRight, key);
    return Search(T->pLeft, key);
}

void Fun(TREE T)
{
    int x;
    cin >> x;
    TNODE *X = Search(T, x);
    if (X == nullptr)
    {
        cout << "No Find";
        return;
    }
    if (X->pLeft == nullptr && X->pRight == nullptr)
    {
        cout << "No descendant";
        return;
    }
    DFS(X, x);
}

int main()
{
    TREE T;
    CreateTree(T);
    Fun(T);
    return 0;
}