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

int Count(TREE T, int X, bool &found)
{
    if (T == nullptr)
        return 0;
    int Left = Count(T->pLeft, X, found);
    int Right = Count(T->pRight, X, found);
    if (T->key == X)
    {
        found = true;
        if (Left == Right)
        {
            cout << "cLeft=cRight";
        }
        else if (Left < Right)
        {
            cout << "cLeft<cRight";
        }
        else
            cout << "cLeft>cRight";
    }
    return Left + Right + 1;
}

void Fun(TREE T)
{
    int X;
    cin >> X;
    bool found = false;
    Count(T, X, found);
    if (!found)
    {
        cout << "No Find";
    }
}

int main()
{
    TREE T;
    CreateTree(T);
    Fun(T);
    return 0;
}
