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
void PrintList(const LIST &l)
{
    if (l.pHead == nullptr)
    {
        cout << "Empty List.";
    }
    else
    {
        NODE *p = l.pHead;
        while (p)
        {
            cout << p->value << " ";
            p = p->pNext;
        }
    }
}
int lengthList(const LIST &l)
{
    if (l.pHead == nullptr)
        return 0;
    else
    {
        int length = 0;
        NODE *p = l.pHead;
        while (p)
        {
            length++;
            p = p->pNext;
        }
        return length;
    }
}
void add_after_k_th(LIST &l, int Y, int k)
{
    if (k > lengthList(l))
        return;
    else
    {
        int viTri = 1;
        NODE *p = l.pHead;
        while (p)
        {
            if (viTri == k)
            {
                NODE *addNode = initNode(Y);
                addNode->pNext = p->pNext;
                p->pNext = addNode;
                break;
            }
            else
            {
                p = p->pNext;
                viTri++;
            }
        }
    }
}
int main()
{
    LIST L;
    int k, Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> k >> Y;
    add_after_k_th(L, Y, k);

    PrintList(L);

    return 0;
}
