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

TNODE *CreateTNODE(int value)
{
    TNODE *T = new TNODE;
    T->key = value;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
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
void Sum(const TREE &T, int &sum)
{
    if (T == nullptr)
        return;
    if (T->pLeft != nullptr || T->pRight != nullptr)
    {
        sum += T->key;
    }
    Sum(T->pLeft, sum);
    Sum(T->pRight, sum);
}
int SumInternalNode(const TREE &T)
{
    int sum = 0;
    Sum(T, sum);
    return sum;
}

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    cout << SumInternalNode(T);
    return 0;
}
