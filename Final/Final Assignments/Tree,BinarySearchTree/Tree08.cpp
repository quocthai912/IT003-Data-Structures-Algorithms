/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>

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

int MaxGroup(TREE);

int main()
{
    vector<int> nlr, lnr;
    int n, key;

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
    cout << MaxGroup(r);
    return 0;
}
// Được xem là bài tập kỉ niệm
// Ngày xưa chưa học DSA đã thấy bài này đầu tiên, trong một kì thi thử DSA
int MaxGroup(TREE root)
{
    if (root == nullptr)
        return 0;
    // Tính tổng khóa tại Node đó
    int sum = root->key;
    if (root->left != nullptr)
        sum += root->left->key;
    if (root->right != nullptr)
        sum += root->right->key;
    // Tính tổng khóa của nhánh cây con bên trái
    int sumLeft = MaxGroup(root->left);
    // Tính tổng khóa của nhánh cây con bên phải
    int sumRight = MaxGroup(root->right);
    // Trả về tổng khóa lớn nhất
    if (sum > sumLeft)
    {
        if (sum > sumRight)
            return sum;
        else
            return sumRight;
    }
    return (sumLeft > sumRight ? sumLeft : sumRight);
}
