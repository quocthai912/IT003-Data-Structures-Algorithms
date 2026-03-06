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
void PrintList_Odd(NODE *head)
{
    if (head == nullptr)
    {
        cout << "Empty List.";
    }
    else
    {
        bool odd = false;
        NODE *p = head;
        while (p)
        {
            if (p->value % 2 != 0)
            {
                odd = true;
                cout << p->value << " ";
            }
            p = p->pNext;
        }
        if (!odd)
        {
            cout << "Không có số lẻ trong mảng.";
        }
    }
}

int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList_Odd(L.pHead);

    return 0;
}
