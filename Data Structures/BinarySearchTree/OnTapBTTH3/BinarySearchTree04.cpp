// Tìm maxLeft, minRight của một Node X, nếu không tìm thấy Node X, xuất NotFound.
// Nếu cây rỗng, xuất Empty Tree.
// No Template.
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
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        InsertTree(T, temp);
        cin >> temp;
    }
}
TNODE *search(TREE T, int x)
{
    if (T == nullptr)
        return nullptr;
    if (T->key == x)
        return T;
    else if (T->key < x)
        return search(T->pRight, x);
    return search(T->pLeft, x);
}
int findMaxLeft(TNODE *x)
{
    if (x == nullptr)
        return -1;
    if (x->pRight == nullptr)
        return x->key;
    return findMaxLeft(x->pRight);
}
int findMinRight(TNODE *x)
{
    if (x == nullptr)
        return -1;
    if (x->pLeft == nullptr)
        return x->key;
    return findMinRight(x->pLeft);
}
void PrintTree(TREE T, int x)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    TNODE *nodeX = search(T, x);
    if (nodeX == nullptr)
    {
        cout << "NotFound";
    }
    else
    {
        cout << "MAX LEFT: " << findMaxLeft(nodeX->pLeft) << endl;
        cout << "MIN RIGHT: " << findMinRight(nodeX->pRight);
    }
}
int main()
{
    int x;
    cin >> x;
    TREE T;
    CreateTree(T);
    PrintTree(T, x);
    return 0;
}
