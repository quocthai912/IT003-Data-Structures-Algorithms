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
void RNL(const TREE &root)
{
    if (root == nullptr)
        return;
    RNL(root->pRight);
    cout << root->key << " ";
    RNL(root->pLeft);
}
void PrintTree(const TREE &T)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    RNL(T);
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    PrintTree(T);
    return 0;
}
