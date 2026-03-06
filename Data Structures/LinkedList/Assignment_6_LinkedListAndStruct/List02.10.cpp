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
void addHead(LIST &L, NODE *addNode)
{
    if (L.pHead == nullptr)
    {
        L.pHead = L.pTail = addNode;
    }
    else
    {
        addNode->pNext = L.pHead;
        L.pHead = addNode;
    }
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
void addAfterValue(LIST &L, int X, int Y)
{

    NODE *p = L.pHead;
    NODE *addNode = initNode(Y);
    while (p)
    {
        if (p->value == X)
        {
            addNode->pNext = p->pNext;
            p->pNext = addNode;
            if (addNode->pNext == nullptr)
            {
                L.pTail = addNode;
            }
            break;
        }
        p = p->pNext;
    }
}
void CreateList(LIST &L)
{
    int type, value;
    cin >> type;
    while (type != -1)
    {
        if (type == 0)
        {
            cin >> value;
            addHead(L, initNode(value));
        }
        else if (type == 1)
        {
            cin >> value;
            addTail(L, initNode(value));
        }
        else if (type == 2)
        {
            int X, Y;
            cin >> X >> Y;
            addAfterValue(L, X, Y);
        }
        cin >> type;
    }
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

    L.pHead = L.pTail = NULL;

    CreateList(L);

    PrintList(L);

    return 0;
}
