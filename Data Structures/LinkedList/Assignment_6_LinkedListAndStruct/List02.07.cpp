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
void RemoveX(LIST &L, int X)
{
    if (L.pHead == nullptr)
        return;
    if (L.pHead == L.pTail)
    {
        if (L.pHead->value == X)
        {
            L.pHead = L.pTail = nullptr;
            return;
        }
    }
    NODE dummyNode;
    dummyNode.pNext = L.pHead;
    NODE *curr = &dummyNode;
    while (curr->pNext != nullptr)
    {
        if (curr->pNext->value == X)
        {
            NODE *deleteNode = curr->pNext;
            curr->pNext = curr->pNext->pNext;
            delete deleteNode;
            break;
        }
        else
        {
            curr = curr->pNext;
        }
    }
    L.pHead = dummyNode.pNext;
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
    int X;
    CreateEmptyList(L);

    CreateList(L);
    std::cin >> X;
    RemoveX(L, X);
    PrintList(L);

    return 0;
}
