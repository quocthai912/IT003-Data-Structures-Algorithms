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
void add_after_middle(LIST &L, int Y)
{
    if (L.pHead == nullptr)
        return;
    if (L.pHead == L.pTail)
    {
        addTail(L, initNode(Y));
        return;
    }
    NODE *fast = L.pHead->pNext;
    NODE *slow = L.pHead;
    while (fast != nullptr && fast->pNext != nullptr)
    {
        fast = fast->pNext->pNext;
        slow = slow->pNext;
    }
    NODE *addNode = initNode(Y);
    addNode->pNext = slow->pNext;
    slow->pNext = addNode;
}

int main()
{
    LIST L;
    int X, Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> Y;
    add_after_middle(L, Y);

    PrintList(L);

    return 0;
}
