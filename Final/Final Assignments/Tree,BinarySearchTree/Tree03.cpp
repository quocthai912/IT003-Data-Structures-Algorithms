// Kiểm tra một cây nhị phân có phải là một cây nhị phân tìm kiếm hay không?
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

bool isBST(TREE);

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
    if (isBST(r))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

bool checkBinarySearchTree(TREE root, int valLeft, int valRight)
{
    // Theo tính chất, cây rỗng cũng được tính là một cây nhị phân tìm kiếm 0 Node.
    if (root == nullptr)
        return true;
    if (root->key <= valLeft || root->key >= valRight)
        return false;
    // Cả hai Node trái và phải của Node root đều phải thỏa mãn
    return checkBinarySearchTree(root->left, valLeft, root->key) && checkBinarySearchTree(root->right, root->key, valRight);
}

bool isBST(TREE root)
{
    // Ràng buộc giá trị nhỏ nhất là -1, do giá trị khóa các Node luôn >= 0.
    // Ràng buộc giá trị lớn nhất sao cho không có Node nào có thể có giá trị khóa vượt qua con số này.
    return checkBinarySearchTree(root, -1, 100000000);
}
