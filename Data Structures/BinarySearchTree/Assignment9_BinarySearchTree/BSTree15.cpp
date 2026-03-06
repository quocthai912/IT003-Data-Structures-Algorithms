/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <queue>
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
void PrintLevel(TREE T, int x, int &levelNode, int currentLevel = 0)
{
    if (T == nullptr)
        return;
    if (T->key == x)
    {
        levelNode = currentLevel;
        return;
    }
    PrintLevel(T->pLeft, x, levelNode, currentLevel + 1);
    PrintLevel(T->pRight, x, levelNode, currentLevel + 1);
}

int main()
{
    TNODE *T;
    int x, level = -1;

    cin >> x;

    T = NULL;
    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
    {
        PrintLevel(T, x, level);
        cout << level;
    }
    return 0;
}
