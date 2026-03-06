// Liệt Kê Các Node Tổ Tiên Của Node X.
// Có Template
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
bool Insert(TREE &T, int key)
{
    if (T)
    {
        if (T->key == key)
            return false;
        else if (T->key < key)
            return Insert(T->pRight, key);
        else
            return Insert(T->pLeft, key);
    }
    T = CreateTNODE(key);
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
bool search(TREE T, int x, vector<int> &danhSach)
{
    if (T == nullptr)
        return false;
    if (T->key == x)
        return true;
    else if (T->key < x)
    {
        danhSach.push_back(T->key);
        return search(T->pRight, x, danhSach);
    }
    else
    {
        danhSach.push_back(T->key);
        return search(T->pLeft, x, danhSach);
    }
    return false;
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
    vector<int> danhSach;
    if (!search(T, x, danhSach))
    {
        cout << -1;
    }
    else
    {
        for (int i = danhSach.size() - 1; i >= 0; i--)
        {
            cout << danhSach[i] << " ";
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
