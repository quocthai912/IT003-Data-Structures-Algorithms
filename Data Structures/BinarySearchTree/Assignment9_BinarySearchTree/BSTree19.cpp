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

TNODE *CreateTNODE(int x)
{
    TNODE *T = new TNODE;
    T->key = x;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
}
bool Insert(TREE &Root, int x)
{
    if (Root)
    {
        if (Root->key == x)
            return false;
        else if (Root->key < x)
            return Insert(Root->pRight, x);
        else
            return Insert(Root->pLeft, x);
    }
    Root = CreateTNODE(x);
    return true;
}
void CreateTree(TREE &Root)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        Insert(Root, temp);
        cin >> temp;
    }
}
void ThayTheNode(TREE &T, TREE &deleteNode)
{
    if (T->pLeft != nullptr)
        ThayTheNode(T->pLeft, deleteNode);
    else
    {
        deleteNode->key = T->key;
        deleteNode = T;
        T = T->pRight;
    }
}
bool DeleteNode(TREE &T, int x)
{
    if (T == nullptr)
        return false;
    else
    {
        if (T->key == x)
        {
            TNODE *deleteNode = T;
            if (T->pLeft != nullptr && T->pRight != nullptr)
                ThayTheNode(T->pRight, deleteNode);
            else
            {
                if (T->pLeft != nullptr)
                    T = T->pLeft;
                else
                    T = T->pRight;
            }
            delete deleteNode;
            return true;
        }
        else if (T->key < x)
            return DeleteNode(T->pRight, x);
        else
            return DeleteNode(T->pLeft, x);
    }
    return false;
}
void Preorder(TREE T)
{
    if (T == nullptr)
        return;
    cout << T->key << " ";
    Preorder(T->pLeft);
    Preorder(T->pRight);
}
void PrintTree(TREE T)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    Preorder(T);
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;

    DeleteNode(T, x);
    PrintTree(T);
    return 0;
}
