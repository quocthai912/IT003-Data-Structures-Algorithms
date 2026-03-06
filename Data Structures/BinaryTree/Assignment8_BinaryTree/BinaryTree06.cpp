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

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE)
{
    int i;
    TREE root;
    if (inE < inB)
        return NULL;
    root = new TNode;
    if (root != NULL)
    {
        root->key = pre[preB];
        for (i = inB; i <= inE; i++)
            if (in[i] == pre[preB])
                break;
        root->left = CreateTree(pre, in, preB + 1, preE, inB, i - 1);
        root->right = CreateTree(pre, in, preB + i - inB + 1, preE, i + 1, inE);
    }
    return root;
}

void Input(vector<int> &danhSachNode)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        danhSachNode.push_back(temp);
        cin >> temp;
    }
}
void findMin(TREE root, int &minKey)
{
    if (root == nullptr)
        return;
    findMin(root->left, minKey);
    if (root->key < minKey)
        minKey = root->key;
    findMin(root->right, minKey);
}
void Fun(TREE root)
{
    if (root == nullptr)
    {
        cout << "Empty Tree";
        return;
    }
    int minKey = root->key;
    findMin(root, minKey);
    cout << minKey;
}
int main()
{
    vector<int> duyetNLR;
    vector<int> duyetLNR;
    Input(duyetNLR);
    Input(duyetLNR);
    int Num = duyetNLR.size() - 1;
    TREE root = CreateTree(duyetNLR, duyetLNR, 0, Num, 0, Num);
    Fun(root);
    return 0;
}
