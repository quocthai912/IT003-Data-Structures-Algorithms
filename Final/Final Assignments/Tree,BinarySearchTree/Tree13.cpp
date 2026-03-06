// Khởi tạo cây Nhị Phân
// Kiểm tra các Node lá trên cây nhị phân này có cùng mức hết hay không
#include <iostream>
#include <vector>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};

typedef TNODE *TREE;

TNODE *CreateTNODE(int key)
{
    TNODE *T = new TNODE;
    T->key = key;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
}
// Nhập vào các dãy duyệt cây
void Input(vector<int> &traversal)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        traversal.push_back(temp);
        cin >> temp;
    }
}
// Hàm tạo cây nhị phân từ hai dãy duyệt cây
TREE buildBinaryTree(vector<int> &preorder, vector<int> &inorder, int preL, int preR, int inL, int inR)
{
    if (preL > preR || inL > inR)
        return nullptr;
    TNODE *root = CreateTNODE(preorder[preL]);
    int indexRoot;
    for (int i = inL; i <= inR; i++)
    {
        if (inorder[i] == root->key)
        {
            indexRoot = i;
            break;
        }
    }
    int sizeLeft = indexRoot - inL;
    root->pLeft = buildBinaryTree(preorder, inorder, preL + 1, preL + sizeLeft, inL, indexRoot - 1);
    root->pRight = buildBinaryTree(preorder, inorder, preL + sizeLeft + 1, preR, indexRoot + 1, inR);
    return root;
}
// Tìm level của nút lá cuối cùng
void searchLevelLeaf(TREE root, int level, int &levelLeaf)
{
    if (root == nullptr)
        return;
    if (root->pLeft == nullptr && root->pRight == nullptr)
    {
        levelLeaf = level;
    }
    searchLevelLeaf(root->pLeft, level + 1, levelLeaf);
    searchLevelLeaf(root->pRight, level + 1, levelLeaf);
}
// Kiểm tra xem toàn bộ nút lá có bằng level đã tìm được hay không
void checkSameLeafLevel(TREE root, int level, int levelLeaf, bool &leafSameLevel)
{
    if (root == nullptr)
        return;
    if (root->pLeft == nullptr && root->pRight == nullptr)
    {
        if (level != levelLeaf)
            leafSameLevel = false;
    }
    checkSameLeafLevel(root->pLeft, level + 1, levelLeaf, leafSameLevel);
    checkSameLeafLevel(root->pRight, level + 1, levelLeaf, leafSameLevel);
}

int main()
{
    vector<int> preorder;
    vector<int> inorder;
    Input(preorder);
    Input(inorder);
    TREE root = buildBinaryTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    bool leafSameLevel = true;
    int levelLeaf = 0;
    searchLevelLeaf(root, 0, levelLeaf);
    checkSameLeafLevel(root, 0, levelLeaf, leafSameLevel);
    if (leafSameLevel)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}