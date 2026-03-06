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
#include <stack>
TNODE *CreateTNODE(int key)
{
    TNODE *T = new TNODE;
    T->key = key;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
}

bool InsertNode(TREE &T, int key)
{
    if (T)
    {
        if (T->key == key)
            return false;
        else if (T->key < key)
            return InsertNode(T->pRight, key);
        else
            return InsertNode(T->pLeft, key);
    }
    T = CreateTNODE(key);
    return true;
}

void CreateTree(TREE &T)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        InsertNode(T, temp);
        cin >> temp;
    }
}

void ThayThe(TREE &T, TREE &q)
{
    if (T->pLeft != nullptr)
        ThayThe(T->pLeft, q);
    else
    {
        q->key = T->key;
        q = T;
        T = T->pRight;
    }
}

bool DeleteNode(TREE &T, int x)
{
    if (T == nullptr)
        return false;
    if (T->key < x)
        return DeleteNode(T->pRight, x);
    else if (T->key > x)
        return DeleteNode(T->pLeft, x);
    TNODE *q = T;
    if (q->pLeft != nullptr && q->pRight != nullptr)
    {
        ThayThe(T->pRight, q);
    }
    else
    {
        if (q->pLeft != nullptr)
            T = T->pLeft;
        else
            T = T->pRight;
    }
    delete q;
    return true;
}

void PrintTree(TREE T)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    stack<TNODE *> st;
    st.push(T);
    while (!st.empty())
    {
        TNODE *top = st.top();
        st.pop();
        cout << top->key << " ";
        if (top->pRight)
            st.push(top->pRight);
        if (top->pLeft)
            st.push(top->pLeft);
    }
}

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;

    DeleteNode(T, x);

    PrintTree(T);
    return 0;
}
