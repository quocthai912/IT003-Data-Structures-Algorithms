// Xuất các Lá có độ sâu thấp nhất
#include <iostream>
#include <queue>
#include <climits>
using namespace std;
// Ý tưởng: Tìm lá có độ sâu thấp nhất, sau đó liệt kê các lá có độ sâu = độ sâu thấp nhất này
struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *Tree;

TNODE *CreateTNODE(int val)
{
    TNODE *T = new TNODE;
    T->key = val;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
}

bool InsertNode(Tree &T, int val)
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

void CreateTree(Tree &T)
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
// mindepth ban đầu là MAX
void minDepth(const Tree &T, int depth, int &mindepth)
{
    if (T == nullptr)
        return;
    if (T->pLeft == nullptr && T->pRight == nullptr)
    {
        if (depth < mindepth)
            mindepth = depth;
    }
    minDepth(T->pLeft, depth + 1, mindepth);
    minDepth(T->pRight, depth + 1, mindepth);
}
void duyetDFS(const Tree &T, int depth, int minDepth)
{
    if (T == nullptr)
        return;
    if (T->pLeft == nullptr && T->pRight == nullptr)
    {
        if (depth == minDepth)
            cout << T->key << " ";
    }
    duyetDFS(T->pLeft, depth + 1, minDepth);
    duyetDFS(T->pRight, depth + 1, minDepth);
}
void Find(Tree T)
{
    if (T == nullptr)
    {
        cout << "Empty";
        return;
    }
    int mindepth = INT_MAX;
    minDepth(T, 0, mindepth);
    duyetDFS(T, 0, mindepth);
}
int main()
{
    Tree T;
    CreateTree(T);
    Find(T);
    return 0;
}
