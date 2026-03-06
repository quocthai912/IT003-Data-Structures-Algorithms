/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>
#include <map>

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

void Input(vector<int> &v)
{
    int tmp;
    cin >> tmp;
    while (tmp > -1)
    {
        v.push_back(tmp);
        cin >> tmp;
    }
}

int SumLeaf(TREE);

int main()
{
    vector<int> nlr, lnr;

    Input(nlr);
    Input(lnr);

    TREE r = CreateTree(nlr, lnr, 0, nlr.size() - 1, 0, lnr.size() - 1);

    cout << SumLeaf(r) << endl;

    return 0;
}

int SumLeaf(TREE root)
{
    // Bài toán (Template) yêu cầu chỉ được cài đặt một hàm duy nhất
    if (root == nullptr)
        return 0;
    // Tổng khóa
    int sumKey = 0;
    if (root->left == nullptr && root->right == nullptr)
    {
        // Nếu là nút lá, tăng tổng khóa
        sumKey += root->key;
    }
    // Trả về tổng khóa tại nút đó, cùng với tổng khóa của 2 nhánh con
    return sumKey + SumLeaf(root->left) + SumLeaf(root->right);
}