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

bool SearchNode(TREE T, int key)
{
    if (T == nullptr)
        return false;
    if (T->key == key)
        return true;
    else if (T->key < key)
    {
        return SearchNode(T->pRight, key);
    }
    return SearchNode(T->pLeft, key);
}

bool PrintAncestor(TREE T, int key)
{
    if (T == nullptr)
        return false;
    if (T->key == key)
        return true;
    else if (T->key < key)
    {
        cout << T->key << " ";
        return PrintAncestor(T->pRight, key);
    }
    cout << T->key << " ";
    return PrintAncestor(T->pLeft, key);
}

void Fun(TREE T)
{
    int x;
    cin >> x;
    if (T->key == x)
    {
        cout << "Root no ancestor";
        return;
    }
    if (!SearchNode(T, x))
    {
        cout << "No Find";
    }
    else
    {
        PrintAncestor(T, x);
    }
}

int main()
{
    TREE T;
    CreateTree(T);
    Fun(T);
    return 0;
}
