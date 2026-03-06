// Ít ra nhưng vẫn nên biết
// Tạo cây nhị phân từ dãy INPUT lạ: 1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R
#include <iostream>
#include <unordered_map>
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

unordered_map<int, TNODE *> HashMap;
// Time Complexity: O(N)
// Space Complexity: O(N)
TREE BuildBinaryTree()
{
    TREE root;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        char z;
        cin >> x >> y >> z;
        if (!HashMap[x])
            HashMap[x] = CreateTNODE(x);
        if (!HashMap[y])
            HashMap[y] = CreateTNODE(y);
        if (z == 'L')
            HashMap[x]->pLeft = HashMap[y];
        else
            HashMap[x]->pRight = HashMap[y];
        if (i == 0)
            root = HashMap[x];
    }
    return root;
}

void Preorder(TREE root)
{
    if (root == nullptr)
        return;
    cout << root->key << " ";
    Preorder(root->pLeft);
    Preorder(root->pRight);
}

int main()
{
    TREE root = BuildBinaryTree();
    Preorder(root);
    return 0;
}