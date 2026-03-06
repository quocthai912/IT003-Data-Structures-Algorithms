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
// Insert Binary Search Tree
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
// Create Binary Search Tree
void CreateTree(TREE &T)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        InsertTree(T, temp);
        cin >> temp;
    }
}
// LNR Not Recursion
void LNR(TREE T)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    stack<TNODE *> st;
    TNODE *curr = T;
    while (curr != nullptr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->pLeft;
        }
        curr = st.top();
        st.pop();
        cout << curr->key << " ";
        curr = curr->pRight;
    }
}

// NLR Not Recursion
void NLR(TREE T)
{
    stack<TNODE *> st;
    st.push(T);
    while (!st.empty())
    {
        TNODE *top = st.top();
        cout << top->key << " ";
        st.pop();
        // Do sử dụng Stack, nếu muốn in Left-Right thì phải Push Right trước
        if (top->pRight)
            st.push(top->pRight);
        if (top->pLeft)
            st.push(top->pLeft);
    }
}
// LRN Not Recursion
void LRN(TREE T)
{
    stack<TNODE *> st;
    stack<TNODE *> printTree;
    st.push(T);
    while (!st.empty())
    {
        TNODE *top = st.top();
        st.pop();
        printTree.push(top);
        if (top->pLeft)
            st.push(top->pLeft);
        if (top->pRight)
            st.push(top->pRight);
    }
    while (!printTree.empty())
    {
        cout << printTree.top()->key << " ";
        printTree.pop();
    }
}

// RNL Not Recursion
void RNL(TREE T)
{
    stack<TNODE *> st;
    TNODE *curr = T;
    while (curr != nullptr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->pRight;
        }
        curr = st.top();
        st.pop();
        cout << curr->key << " ";
        curr = curr->pLeft;
    }
}

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    LNR(T);
    return 0;
}
