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
void Print_Middle(LIST L)
{
    if (L.pHead == nullptr)
    {
        cout << "Empty List.";
        return;
    }
    if (L.pHead == L.pTail)
    {
        cout << L.pHead->value;
        return;
    }
    NODE *fast = L.pHead->pNext;
    NODE *slow = L.pHead;
    while (fast != nullptr && fast->pNext != nullptr)
    {
        fast = fast->pNext->pNext;
        slow = slow->pNext;
    }
    cout << slow->value;
}

int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    Print_Middle(L);

    return 0;
}
