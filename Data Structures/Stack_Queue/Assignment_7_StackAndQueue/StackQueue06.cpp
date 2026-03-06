/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;
// ###INSERT CODE HERE -
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
void Testing_Push_Pop_Top_Stack(stack s)
{
    int mangLuuTruPop[10001];
    int dem = 0;
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        if (temp != 0)
        {
            push(s, initNode(temp));
        }
        else if (temp == 0)
        {
            if (!isEmpty(s))
            {
                mangLuuTruPop[dem++] = top(s);
                pop(s);
            }
        }
        cin >> temp;
    }
    cout << "output: ";
    if (dem > 0)
    {
        for (int i = 0; i < dem; i++)
            cout << mangLuuTruPop[i] << " ";
    }
    cout << endl
         << "top: ";
    if (!isEmpty(s))
        cout << top(s);
}
int main()
{
    stack s;
    Testing_Push_Pop_Top_Stack(s);
    return 0;
}
