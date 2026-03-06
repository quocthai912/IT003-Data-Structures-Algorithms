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
    // Time Complexity: O(N), duyệt qua toàn bộ N phần tử và Build từng nhánh.
    // Space Complexity: O(1), không sử dụng Hash Table (map).
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *binaryTree = buildBinaryTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        return binaryTree;
    }

    TreeNode *buildBinaryTree(vector<int> &preorder, vector<int> &inorder, int preL, int preR, int inL, int inR)
    {
        if (preL > preR || inL > inR)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preL]);
        int indexRoot;
        for (int i = inL; i <= inR; i++)
        {
            if (inorder[i] == root->val)
            {
                indexRoot = i;
                break;
            }
        }
        int sizeLeft = indexRoot - inL;
        root->left = buildBinaryTree(preorder, inorder, preL + 1, preL + sizeLeft, inL, indexRoot - 1);
        root->right = buildBinaryTree(preorder, inorder, preL + sizeLeft + 1, preR, indexRoot + 1, inR);
        return root;
    }
};