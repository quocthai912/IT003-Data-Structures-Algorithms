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
void timSoLonHon(NODE *p, int &result)
{
    result = -1;
    NODE *curr = p->pNext;
    while (curr)
    {
        if (curr->value > p->value)
        {
            result = curr->value;
            break;
        }
        curr = curr->pNext;
    }
}
void Function(NODE *head)
{
    if (head == nullptr)
    {
        cout << "Empty List.";
        return;
    }
    NODE *p = head;
    while (p)
    {
        cout << p->value << " ";
        int result;
        timSoLonHon(p, result);
        cout << result << endl;
        p = p->pNext;
    }
}
int main()
{
    LIST L;
    int X;
    CreateEmptyList(L);

    CreateList(L);

    Function(L.pHead);

    return 0;
}
