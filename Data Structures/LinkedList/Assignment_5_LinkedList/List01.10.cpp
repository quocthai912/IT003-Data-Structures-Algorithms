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
void addTail(LIST &l, NODE *addNode)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = addNode;
    }
    else
    {
        l.pTail->pNext = addNode;
        l.pTail = addNode;
    }
}
void CreateList(LIST &l)
{
    int value;
    cin >> value;
    while (value != -1)
    {
        addTail(l, initNode(value));
        cin >> value;
    }
}
string searchX(NODE *head, int X)
{
    if (head == nullptr)
    {
        return "false";
    }
    NODE *p = head;
    while (p)
    {
        if (p->value == X)
            return "true";
        p = p->pNext;
    }
    return "false";
}

int main()
{
    LIST L;
    int X;
    CreateEmptyList(L);

    CreateList(L);
    std::cin >> X;
    cout << searchX(L.pHead, X);

    return 0;
}
