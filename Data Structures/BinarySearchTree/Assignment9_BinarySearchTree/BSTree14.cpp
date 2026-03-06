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
    TNODE *T = new TNODE;
    T->key = key;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
}
bool Insert(TREE &root, int key)
{
    if (root)
    {
        if (root->key == key)
            return false;
        else if (root->key < key)
            return Insert(root->pRight, key);
        else
            return Insert(root->pLeft, key);
    }
    root = CreateTNODE(key);
    return true;
}
void CreateTree(TREE &root)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        Insert(root, temp);
        cin >> temp;
    }
}
TNODE *FindMin(TREE T)
{
    if (T->pLeft == nullptr)
        return T;
    return FindMin(T->pLeft);
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        cout << FindMin(T)->key;
    return 0;
}
