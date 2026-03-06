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
void CreateEmptyList(LIST &L)
{
    L.pHead = nullptr;
    L.pTail = nullptr;
}
void addTail(LIST &L, NODE *addNode)
{
    if (L.pHead == nullptr)
    {
        L.pHead = L.pTail = addNode;
    }
    else
    {
        L.pTail->pNext = addNode;
        L.pTail = addNode;
    }
}
void CreateList(LIST &L)
{
    int value;
    cin >> value;
    while (value != -1)
    {
        addTail(L, initNode(value));
        cin >> value;
    }
}
int count_even(NODE *Head)
{
    if (Head == nullptr)
        return 0;
    int count = 0;
    NODE *p = Head;
    while (p)
    {
        if (p->value % 2 == 0)
            count++;
        p = p->pNext;
    }
    return count;
}

int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    cout << count_even(L.pHead);

    return 0;
}
