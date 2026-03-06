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
void PrintList(NODE *head)
{
    if (head == nullptr)
    {
        cout << "Empty List.";
    }
    else
    {
        NODE *p = head;
        while (p)
        {
            cout << p->value << " ";
            p = p->pNext;
        }
    }
}
void add_afterX_1(LIST &l, int Y, int X)
{
    if (l.pHead == nullptr)
        return;
    bool addValueY = false;
    NODE *p = l.pHead;
    while (p)
    {
        if (p->value == X)
        {
            if (addValueY == false)
            {
                NODE *addNode = initNode(Y);
                addNode->pNext = p->pNext;
                p->pNext = addNode;
                p = addNode->pNext;
                addValueY = true;
            }
            else
            {
                p = p->pNext;
            }
        }
        else
        {
            p = p->pNext;
        }
    }
}

int main()
{
    LIST L;
    int X, Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> X >> Y;
    add_afterX_1(L, Y, X);

    PrintList(L.pHead);

    return 0;
}
