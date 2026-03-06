// Khởi tạo cây Nhị Phân
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        TreeNode *binaryTree = buildBinaryTree(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
        return binaryTree;
    }

    TreeNode *buildBinaryTree(vector<int> &preorder, vector<int> &postorder, int preL, int preR, int posL, int posR)
    {
        if (preL > preR || posL > posR)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preL]);
        if (preL == preR)
            return root;
        int rootLeftVal = preorder[preL + 1];
        int indexRootLeft;
        for (int i = posL; i <= posR; i++)
        {
            if (postorder[i] == rootLeftVal)
                indexRootLeft = i;
        }
        int sizeLeft = (indexRootLeft - posL) + 1;
        root->left = buildBinaryTree(preorder, postorder, preL + 1, preL + sizeLeft, posL, indexRootLeft);
        root->right = buildBinaryTree(preorder, postorder, preL + sizeLeft + 1, preR, indexRootLeft + 1, posR - 1);
        return root;
    }
};