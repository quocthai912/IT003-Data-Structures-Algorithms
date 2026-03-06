#include <iostream>
#include <queue>
using namespace std;
// Độ Phức Tạp Thuật Toán Duyệt Cây Theo Chiều Rộng BFS O(N).
struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;
TNODE *createTNODE(int value)
{
    TNODE *T = new TNODE;
    T->key = value;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
}
bool insertNode(TREE &T, int value)
{
    if (T)
    {
        if (T->key == value)
            return false;
        else if (T->key < value)
            return insertNode(T->pRight, value);
        else
            return insertNode(T->pLeft, value);
    }
    T = createTNODE(value);
    return true;
}
void createTree(TREE &T)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        insertNode(T, temp);
        cin >> temp;
    }
}
void BFS(const TREE &root)
{
    if (root == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    queue<TNODE *> duyetNut;
    duyetNut.push(root);
    while (!duyetNut.empty())
    {
        TNODE *currentNode = duyetNut.front();
        duyetNut.pop();
        cout << currentNode->key << " ";
        if (currentNode->pLeft != nullptr)
            duyetNut.push(currentNode->pLeft);
        if (currentNode->pRight != nullptr)
            duyetNut.push(currentNode->pRight);
    }
}
int main()
{
    TREE T;
    T = nullptr;
    createTree(T);
    BFS(T);
    return 0;
}