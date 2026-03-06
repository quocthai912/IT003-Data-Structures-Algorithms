/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;
struct NODE
{
    int value;
    NODE *pNext;
};
NODE *initNode(int value)
{
    NODE *p = new NODE;
    p->value = value;
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
int top(const stack &st)
{
    return st.pHead->value;
}
void array_reverse(stack s, int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        push(s, initNode(a[i]));
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = top(s);
        pop(s);
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    stack s;
    int a[100], n;
    array_reverse(s, a, n);
    return 0;
}
