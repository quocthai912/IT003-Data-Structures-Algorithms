/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
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

TNODE *CreateTNODE(int value)
{
    TNODE *T = new TNODE;
    T->key = value;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
}
bool Insert(TREE &T, int value)
{
    if (T)
    {
        if (T->key == value)
            return false;
        else if (T->key < value)
            return Insert(T->pRight, value);
        else
            return Insert(T->pLeft, value);
    }
    T = CreateTNODE(value);
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
void CountLeaf(const TREE &T, int &count)
{
    if (T == nullptr)
        return;
    if (T->pLeft == nullptr && T->pRight == nullptr)
        count++;
    CountLeaf(T->pLeft, count);
    CountLeaf(T->pRight, count);
}

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int count = 0;
    CountLeaf(T, count);
    cout << count;
    return 0;
}
