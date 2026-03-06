/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct TNode
{
    int key;
    TNode *left, *right;
};

typedef TNode *TREE;

void CreateTree(TREE &t)
{
    t = NULL;
}

TNode *CreateTNode(int x)
{
    TNode *p = new TNode;
    if (p == NULL)
        return NULL;
    p->left = p->right = NULL;
    p->key = x;
    return p;
}

void InsertNode(TREE &t, int x)
{
    TNode *p = CreateTNode(x);

    if (t == NULL)
    {
        t = p;
        return;
    }
    TREE q = t;
    while (q != NULL)
    {
        if (x == q->key)
            return;
        if (x > q->key)
        {
            if (q->right == NULL)
            {
                q->right = p;
                return;
            }
            q = q->right;
        }
        else
        {
            if (q->left == NULL)
            {
                q->left = p;
                return;
            }
            q = q->left;
        }
    }
}

void LoadTree(TREE &t)
{
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        InsertNode(t, k);
    }
}

void MaxFindingCost(TREE);

int main()
{
    vector<int> keys;
    TREE t;
    CreateTree(t);
    LoadTree(t);
    MaxFindingCost(t);
    return 0;
}

vector<int> keyTree;
void LNR(TREE T)
{
    if (T == nullptr)
        return;
    LNR(T->left);
    keyTree.push_back(T->key);
    LNR(T->right);
}

int chiPhiTimKiem(TREE T, int key)
{
    int chiPhi = 0;
    while (T)
    {
        chiPhi++;
        if (T->key == key)
            return chiPhi;
        else if (T->key < key)
            T = T->right;
        else
            T = T->left;
    }
    return -1;
}

void MaxFindingCost(TREE T)
{
    LNR(T);
    int maxChiPhi = -1;
    for (int i = 0; i < keyTree.size(); i++)
    {
        if (chiPhiTimKiem(T, keyTree[i]) > maxChiPhi)
            maxChiPhi = chiPhiTimKiem(T, keyTree[i]);
    }
    for (int i = 0; i < keyTree.size(); i++)
    {
        if (chiPhiTimKiem(T, keyTree[i]) == maxChiPhi)
            cout << keyTree[i] << " ";
    }
}