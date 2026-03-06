/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>
#include <map>

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

void Input(vector<int> &v)
{
    int tmp;
    cin >> tmp;
    while (tmp > -1)
    {
        v.push_back(tmp);
        cin >> tmp;
    }
}

int Count(TREE);

int main()
{
    vector<int> nlr, lnr;

    Input(nlr);
    Input(lnr);
    for (int i = 0; i < nlr.size(); i++)
        cout << nlr[i] << ' ';
    cout << endl;
    for (int i = 0; i < lnr.size(); i++)
        cout << lnr[i] << ' ';
    cout << endl;

    TREE r = CreateTree(nlr, lnr, 0, nlr.size() - 1, 0, lnr.size() - 1);

    cout << Count(r) << endl;

    return 0;
}

int Count(TREE root)
{
    if (root == nullptr)
        return 0;
    int count = 0;
    if (root->left != nullptr && root->right != nullptr)
    {
        if (root->left->key > root->right->key)
            count++;
    }
    return count + Count(root->left) + Count(root->right);
}
