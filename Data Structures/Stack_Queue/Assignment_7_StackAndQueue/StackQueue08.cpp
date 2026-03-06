/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;
struct NODE
{
    char kiTu;
    NODE *pNext;
};
NODE *initNode(char c)
{
    NODE *p = new NODE;
    p->kiTu = c;
    p->pNext = nullptr;
    return p;
}
struct stack
{
    NODE *pHead;
};
bool isEmpty(const stack &st)
{
    return st.pHead == nullptr;
}
void push(stack &st, NODE *add)
{
    if (isEmpty(st))
    {
        st.pHead = add;
        return;
    }
    add->pNext = st.pHead;
    st.pHead = add;
}
bool pop(stack &st)
{
    if (isEmpty(st))
        return false;
    NODE *xoaNode = st.pHead;
    st.pHead = st.pHead->pNext;
    delete xoaNode;
    return true;
}
char top(const stack &st)
{
    return st.pHead->kiTu;
}
void BracketMatching(stack s, char st[])
{
    string bieuThuc;
    getline(cin, bieuThuc);
    for (int i = 0; i < bieuThuc.length(); i++)
    {
        if (bieuThuc[i] == '(')
            push(s, initNode(bieuThuc[i]));
        else if (bieuThuc[i] == ')')
        {
            if (isEmpty(s))
            {
                cout << "False";
                return;
            }
            else
            {
                pop(s);
            }
        }
    }
    if (isEmpty(s))
        cout << "True";
    else
        cout << "False";
}
int main()
{
    stack s;
    char st[100];
    BracketMatching(s, st);
    return 0;
}
