/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
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
int Height(TREE root)
{
    if (root == nullptr)
        return -1;
    int a = Height(root->left);
    int b = Height(root->right);
    return (a > b ? a : b) + 1;
}
void tongKhoaCuaMuc(TREE root, int mucCanTinh, int &sum, int mucHienTai)
{
    if (root == nullptr)
        return;
    if (mucCanTinh == mucHienTai)
    {
        sum += root->key;
        return;
    }
    if (mucHienTai < mucCanTinh)
    {
        tongKhoaCuaMuc(root->left, mucCanTinh, sum, mucHienTai + 1);
        tongKhoaCuaMuc(root->right, mucCanTinh, sum, mucHienTai + 1);
    }
}
void Fun(TREE root)
{
    if (root == nullptr)
    {
        cout << "Empty Tree";
        return;
    }
    int mucCanTinh;
    cin >> mucCanTinh;
    if (mucCanTinh > Height(root))
        cout << "No Find";
    else
    {
        int sum = 0;
        tongKhoaCuaMuc(root, mucCanTinh, sum, 0);
        cout << sum;
    }
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
