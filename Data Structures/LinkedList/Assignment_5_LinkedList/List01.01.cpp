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
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
void CreateEmptyList(LIST &l)
{
    l.pHead = nullptr;
    l.pTail = nullptr;
}
void addHead(LIST &l, NODE *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void CreateList(LIST &l)
{
    int value;
    cin >> value;
    while (value != -1)
    {
        addHead(l, initNode(value));
        cin >> value;
    }
}
void PrintList(LIST &l)
{
    if (l.pHead == nullptr)
    {
        cout << "Empty List.";
    }
    else
    {
        NODE *p = l.pHead;
        while (p)
        {
            cout << p->value << " ";
            p = p->pNext;
        }
    }
}
int main()
{
    LIST L;
    CreateEmptyList(L);
    CreateList(L);
    PrintList(L);

    return 0;
}
