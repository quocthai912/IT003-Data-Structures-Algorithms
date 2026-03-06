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
void RemoveTail(LIST &L)
{
    if (L.pHead == nullptr)
    {
        return;
    }
    if (L.pHead == L.pTail)
    {
        L.pHead = L.pTail = nullptr;
        return;
    }
    NODE *p = L.pHead;
    while (p->pNext != L.pTail)
    {
        p = p->pNext;
    }
    NODE *deleteNode = p->pNext;
    p->pNext = nullptr;
    L.pTail = p;
    delete deleteNode;
}
void PrintList(LIST L)
{
    if (L.pHead == nullptr)
        cout << "Empty List.";
    else
    {
        NODE *p = L.pHead;
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
    RemoveTail(L);
    PrintList(L);

    return 0;
}
