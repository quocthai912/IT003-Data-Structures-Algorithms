// Duyệt BFS theo từng Level.
// Với Mỗi Level, chỉ in Node có 1 con.
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
TNODE *CreateTNODE(int val)
{
    TNODE *T = new TNODE;
    T->key = val;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
}
bool InsertNode(TREE &T, int val)
{
    if (T)
    {
        if (T->key == val)
            return false;
        else if (T->key < val)
            return InsertNode(T->pRight, val);
        else
            return InsertNode(T->pLeft, val);
    }
    T = CreateTNODE(val);
    return true;
}
void CreateTree(TREE &T)
{
    T = nullptr;
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        InsertNode(T, temp);
        cin >> temp;
    }
}
void Find(const TREE &root)
{
    if (root == nullptr)
    {
        cout << "Empty";
        return;
    }
    queue<TNODE *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        cout << "Level " << level << ": ";
        bool find = false;
        for (int i = 0; i < size; i++)
        {
            TNODE *T = q.front();
            if (T->pLeft == nullptr && T->pRight != nullptr || T->pLeft != nullptr && T->pRight == nullptr)
            {
                cout << T->key << " ";
                find = true;
            }
            q.pop();
            if (T->pLeft != nullptr)
                q.push(T->pLeft);
            if (T->pRight != nullptr)
                q.push(T->pRight);
        }
        if (!find)
            cout << "NotFound";
        level++;
        cout << endl;
    }
}
int main()
{
    TREE T;
    CreateTree(T);
    Find(T);
    return 0;
}
