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
void CreateTree(TREE &T)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        Insert(T, CreateTNode(temp));
        cin >> temp;
    }
}
void sumNodelevel(const TREE &T, int level, int levelCanTinh, int &sum)
{
    if (T == nullptr)
        return;
    if (level == levelCanTinh)
    {
        sum += T->key;
        return;
    }
    sumNodelevel(T->pRight, level + 1, levelCanTinh, sum);
    sumNodelevel(T->pLeft, level + 1, levelCanTinh, sum);
}
int main()
{
    TREE T;
    T = nullptr;
    CreateTree(T);
    int levelSum;
    cin >> levelSum;
    int sum = 0;
    sumNodelevel(T, 0, levelSum, sum);
    cout << sum;
    return 0;
}
