/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
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
bool Insert(TREE &root, int key)
{
    if (root)
    {
        if (root->key == key)
            return false;
        else if (root->key < key)
            return Insert(root->pRight, key);
        else
            return Insert(root->pLeft, key);
    }
    root = CreateTNODE(key);
    return true;
}
void CreateTree(TREE &root)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        Insert(root, temp);
        cin >> temp;
    }
}
TNODE *search(TREE root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (root->key == key)
        return root;
    else if (root->key < key)
        return search(root->pRight, key);
    return search(root->pLeft, key);
}
int Height(TREE root)
{
    if (root == nullptr)
        return -1;
    int Left = Height(root->pLeft);
    int Right = Height(root->pRight);
    return (Left > Right ? Left : Right) + 1;
}
int HeightOfNode(TREE root, int x)
{
    TNODE *Node = search(root, x);
    return Height(Node);
}
int main()
{
    TREE T;
    int x;

    cin >> x;

    T = NULL;
    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        cout << HeightOfNode(T, x);

    return 0;
}
