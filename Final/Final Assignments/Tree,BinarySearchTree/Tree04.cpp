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
    while (tmp > 0)
    {
        v.push_back(tmp);
        cin >> tmp;
    }
}

int MaxLevel(TREE);

int main()
{
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    Input(nlr);
    Input(lnr);

    TREE r = CreateTree(nlr, lnr, 0, nlr.size() - 1, 0, lnr.size() - 1);

    cout << MaxLevel(r) << endl;

    return 0;
}

// Bài toán không được phép sử dụng Queue
// Hàm tính tổng khóa của từng mức k
void sumKeyLevel(TREE root, int level, int k, int &sum)
{
    if (root == nullptr)
        return;
    if (level == k)
        sum += root->key;
    sumKeyLevel(root->left, level + 1, k, sum);
    sumKeyLevel(root->right, level + 1, k, sum);
}

// Hàm tính chiều cao cây, mức cao nhất của cây cũng chính là chiều cao cây
// Ví dụ có 4 mức: 0,1,2,3 thì 3 cũng là chiều cao cây
// Ta sẽ dùng điều này để duyệt qua từng mức và tìm Max
int Height(TREE root)
{
    if (root == nullptr)
        return -1;
    int Left = Height(root->left);
    int Right = Height(root->right);
    return (Left > Right ? Left : Right) + 1;
}

int MaxLevel(TREE root)
{
    int height = Height(root);
    int maxLevel = 0;
    int maxSum = -1;
    for (int level = 0; level <= height; level++)
    {
        int sum = 0;
        sumKeyLevel(root, 0, level, sum);
        if (sum > maxSum)
        {
            maxSum = sum;
            maxLevel = level;
        }
    }
    return maxLevel;
}