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

void CreateEmptyTree(TREE &T)
{
    T = NULL;
}
TNODE *CreateTNode(int x)
{
    TNODE *p = new TNODE; // cấp phát vùng nhớ động
    p->key = x;           // gán trường dữ liệu của node = x
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
int Insert(TREE &T, TNODE *p)
{
    if (T)
    {
        if (T->key == p->key)
            return 0;
        if (T->key > p->key)
            return Insert(T->pLeft, p);
        return Insert(T->pRight, p);
    }
    T = p;
    return 1;
}
void CreateTree(TREE &root)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        Insert(root, CreateTNode(temp));
        cin >> temp;
    }
}
bool Search(TREE T, int x)
{
    if (T == nullptr)
        return false;
    if (T->key == x)
        return true;
    else if (T->key < x)
        return Search(T->pRight, x);
    return Search(T->pLeft, x);
}
TNODE *FindFather(TREE T, int x)
{
    if (T == nullptr)
        return nullptr;
    if ((T->pLeft != nullptr && T->pLeft->key == x) || T->pRight != nullptr && T->pRight->key == x)
        return T;
    else if (T->key < x)
        return FindFather(T->pRight, x);
    return FindFather(T->pLeft, x);
}
void FindSiblings(TREE T, int x)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    if (T->key == x)
    {
        cout << x << " is Root.";
        return;
    }
    if (!Search(T, x))
    {
        cout << "Not found " << x << ".";
        return;
    }
    TNODE *Father = FindFather(T, x);
    if (Father->pLeft != nullptr && Father->pLeft->key == x)
    {
        if (Father->pRight == nullptr)
        {
            cout << x << " has no siblings.";
            return;
        }
        else
        {
            cout << x << " and " << Father->pRight->key << " are siblings.";
            return;
        }
    }
    if (Father->pRight != nullptr && Father->pRight->key == x)
    {
        if (Father->pLeft == nullptr)
        {
            cout << x << " has no siblings.";
            return;
        }
        else
        {
            cout << Father->pLeft->key << " and " << x << " are siblings.";
            return;
        }
    }
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;

    FindSiblings(T, x);

    return 0;
}
