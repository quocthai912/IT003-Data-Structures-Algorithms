#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;
#include <vector>
vector<int> mangThoaDieuKien;
TNODE *CreateTNODE(int key)
{
    TNODE *T = new TNODE;
    T->key = key;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
}
bool Insert(TREE &root, int key)
{
    if (root)
    {
        if (root->key == key)
            return false;
        else if (root->key < key)
            return Insert(root->pRight, key);
        else
            return Insert(root->pLeft, key);
    }
    root = CreateTNODE(key);
    return true;
}
void CreateTree(TREE &root)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        Insert(root, temp);
        cin >> temp;
    }
}
void CountNode(TREE T, int &count)
{
    if (T == nullptr)
        return;
    count++;
    CountNode(T->pLeft, count);
    CountNode(T->pRight, count);
}
void LeftRight(TREE T)
{
    if (T == nullptr)
        return;
    int countLeft = 0;
    int countRight = 0;
    CountNode(T->pLeft, countLeft);
    CountNode(T->pRight, countRight);
    if (countLeft - countRight == 1)
        mangThoaDieuKien.push_back(T->key);
}
void TimNodeThoa(TREE T)
{
    if (T == nullptr)
        return;
    TimNodeThoa(T->pLeft);
    TimNodeThoa(T->pRight);
    LeftRight(T);
}
void TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(TREE T)
{
    TimNodeThoa(T);
    for (int i = 0; i < mangThoaDieuKien.size(); i++)
        cout << mangThoaDieuKien[i] << " ";
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)

    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T);

    return 0;
}
