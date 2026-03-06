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
bool InsertTree(TREE &root, int key)
{
    if (root)
    {
        if (root->key == key)
            return false;
        else if (root->key < key)
            return InsertTree(root->pRight, key);
        else
            return InsertTree(root->pLeft, key);
    }
    root = CreateTNODE(key);
    return true;
}
void CreateTree(TREE &root)
{
    int key;
    cin >> key;
    while (key != -1)
    {
        InsertTree(root, key);
        cin >> key;
    }
}
bool searchNode(TREE root, int x)
{
    if (root == nullptr)
        return false;
    if (root->key == x)
        return true;
    else if (root->key < x)
        return searchNode(root->pRight, x);
    return searchNode(root->pLeft, x);
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;
    if (searchNode(T, x))
        cout << "true";
    else
        cout << "false";
    return 0;
}
