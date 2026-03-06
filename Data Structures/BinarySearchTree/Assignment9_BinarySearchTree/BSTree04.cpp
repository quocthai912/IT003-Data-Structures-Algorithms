/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
static
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
    TNODE *p = new TNODE;
    p->key = key;
    p->pLeft = nullptr;
    p->pRight = nullptr;
    return p;
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
void Count(TREE T, int &count)
{
    if (T == nullptr)
        return;
    count++;
    Count(T->pLeft, count);
    Count(T->pRight, count);
}
int CountNode(TREE T)
{
    int countNode = 0;
    Count(T, countNode);
    return countNode;
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    cout << CountNode(T);
    return 0;
}
