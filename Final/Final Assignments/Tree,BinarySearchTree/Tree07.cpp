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

int CountEvenLeaves(TREE);

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
    cout << CountEvenLeaves(r);
    return 0;
}
// Đếm số nút là lá và có khóa chẵn
int CountEvenLeaves(TREE root)
{
    // Node rỗng không tính
    if (root == nullptr)
        return 0;
    // Biến đếm
    int count = 0;
    if (root->left == nullptr && root->right == nullptr)
    {
        // Nếu là nút lá và có giá trị khóa chẵn
        if (root->key % 2 == 0)
            count++;
    }
    // Trả về 1 (Tính là 1 Node thỏa mãn) cùng với số lượng Node thỏa mãn ở 2 cây con của nó
    return count + CountEvenLeaves(root->left) + CountEvenLeaves(root->right);
}
