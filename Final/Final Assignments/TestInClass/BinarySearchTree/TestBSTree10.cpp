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

TNODE *Search(TREE T, int key)
{
    if (T == nullptr)
        return nullptr;
    if (T->key == key)
        return T;
    else if (T->key < key)
        return Search(T->pRight, key);
    return Search(T->pLeft, key);
}

int MinRight(TREE T)
{
    if (T->pLeft != nullptr)
        return MinRight(T->pLeft);
    return T->key;
}

void Fun(TREE T)
{
    int x;
    cin >> x;
    TNODE *X = Search(T, x);
    if (X == nullptr)
    {
        cout << "No Find";
        return;
    }
    if (X->pLeft == nullptr || X->pRight == nullptr)
    {
        cout << "No Node 2";
        return;
    }
    cout << MinRight(X->pRight);
}

int main()
{
    TREE T;
    CreateTree(T);
    Fun(T);
    return 0;
}
