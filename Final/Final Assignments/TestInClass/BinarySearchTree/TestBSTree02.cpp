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

TNODE *searchNode(TREE T, int key)
{
    if (T == nullptr)
        return nullptr;
    if (T->key == key)
        return T;
    else if (T->key < key)
        return searchNode(T->pRight, key);
    return searchNode(T->pLeft, key);
}

void Fun(TREE T)
{
    int key;
    cin >> key;
    TNODE *X = searchNode(T, key);
    if (X == nullptr)
    {
        cout << "No Find";
    }
    else
    {
        if (X->pLeft == nullptr && X->pRight == nullptr)
        {
            cout << "Node la";
            return;
        }
        if (X->pLeft != nullptr && X->pRight != nullptr)
        {
            cout << "Node 2 con";
            return;
        }
        if (X->pLeft != nullptr && X->pRight == nullptr || X->pRight != nullptr && X->pLeft == nullptr)
        {
            cout << "Node 1 con";
            return;
        }
    }
}

int main()
{
    TREE T;
    CreateTree(T);
    Fun(T);
    return 0;
}
