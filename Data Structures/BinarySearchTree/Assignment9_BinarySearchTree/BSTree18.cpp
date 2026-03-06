/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <queue>
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

int search(TREE T, int x, vector<int> &ancestors)
{
    if (T == nullptr)
        return -1;
    if (T->key == x)
        return 1;
    else
    {
        ancestors.push_back(T->key);
        if (T->key < x)
            return search(T->pRight, x, ancestors);
        else
            return search(T->pLeft, x, ancestors);
    }
    return -1;
}
void PrintAncestors(TREE T, int x)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    if (T->key == x)
    {
        cout << "Node is root.";
        return;
    }
    vector<int> ancestors;
    if (search(T, x, ancestors) == -1)
    {
        cout << -1;
    }
    else
    {
        for (int i = ancestors.size() - 1; i >= 0; i--)
        {
            cout << ancestors[i] << " ";
        }
    }
}
int main()
{
    TNODE *T;
    int x;

    cin >> x;

    T = NULL;
    CreateTree(T);

    PrintAncestors(T, x);

    return 0;
}
