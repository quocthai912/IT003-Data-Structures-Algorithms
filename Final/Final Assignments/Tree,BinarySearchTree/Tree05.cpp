/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>
#include <iomanip>

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

double AverageByLevel(TREE, int);

int main()
{
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> key;
        nlr.push_back(key);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> key;
        lnr.push_back(key);
    }

    TREE r = CreateTree(nlr, lnr, 0, nlr.size() - 1, 0, lnr.size() - 1);

    cin >> m;

    cout << setprecision(2) << fixed;

    for (int i = 0; i < m; i++)
    {
        cin >> lvl;
        cout << AverageByLevel(r, lvl) << endl;
    }

    return 0;
}

// Tính chiều cao trước, nếu vượt quá chiều cao thì trung bình mức bằng 0
int Height(TREE root)
{
    if (root == nullptr)
        return -1;
    int Left = Height(root->left);
    int Right = Height(root->right);
    return (Left > Right ? Left : Right) + 1;
}

// Tính tổng khóa và tìm số nút tại mức k
void FindCountAndSum(TREE root, int level, int k, int &sum, int &count)
{
    if (root == nullptr)
        return;
    if (level == k)
    {
        sum += root->key;
        count += 1;
    }
    FindCountAndSum(root->left, level + 1, k, sum, count);
    FindCountAndSum(root->right, level + 1, k, sum, count);
}

double AverageByLevel(TREE root, int k)
{
    // Mức lớn hơn chiều cao của cây, trả về 0
    if (k > Height(root))
        return 0;
    int sum = 0;
    int count = 0;
    FindCountAndSum(root, 0, k, sum, count);
    // Đảm bảo kết quả trả về là số thập phân
    return sum / (count * 1.0);
}
