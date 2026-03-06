/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
template
class
typedef
vector
pair
set
map
exit
[
]
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

bool InsertTree(TREE &T, int key)
{
    if (T)
    {
        if (T->key == key)
            return false;
        else if (T->key < key)
            return InsertTree(T->pRight, key);
        else
            return InsertTree(T->pLeft, key);
    }
    T = CreateTNODE(key);
    return true;
}

void CreateTree(TREE &T)
{
    T = nullptr;
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        InsertTree(T, temp);
        cin >> temp;
    }
}

void DFS(TREE T, int &countLeaf, int &sumLeaf, int &countOne, int &sumOne, int &countSecond, int &sumSecond)
{
    if (T == nullptr)
        return;
    if (T->pLeft == nullptr && T->pRight == nullptr)
    {
        countLeaf++;
        sumLeaf += T->key;
    }
    if (T->pLeft != nullptr && T->pRight == nullptr || T->pRight != nullptr && T->pLeft == nullptr)
    {
        countOne++;
        sumOne += T->key;
    }
    if (T->pLeft != nullptr && T->pRight != nullptr)
    {
        countSecond++;
        sumSecond += T->key;
    }
    DFS(T->pLeft, countLeaf, sumLeaf, countOne, sumOne, countSecond, sumSecond);
    DFS(T->pRight, countLeaf, sumLeaf, countOne, sumOne, countSecond, sumSecond);
}

void Fun(TREE T)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    int countLeaf, sumLeaf, countOne, sumOne, countSecond, sumSecond;
    countLeaf = sumLeaf = countOne = sumOne = countSecond = sumSecond = 0;
    DFS(T, countLeaf, sumLeaf, countOne, sumOne, countSecond, sumSecond);
    cout << "Node 0: count = " << countLeaf << " - sum = " << sumLeaf << endl;
    cout << "Node 1: count = " << countOne << " - sum = " << sumOne << endl;
    cout << "Node 2: count = " << countSecond << " - sum = " << sumSecond << endl;
}

int main()
{
    TREE T;
    CreateTree(T);
    Fun(T);
    return 0;
}