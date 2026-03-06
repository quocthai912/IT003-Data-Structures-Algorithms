/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *pNext;
};
Node *initNode(int value)
{
    Node *p = new Node;
    p->value = value;
    p->pNext = nullptr;
    return p;
}
struct LIST
{
    Node *pHead;
    Node *pTail;
};
void CreateEmptyList(LIST &l)
{
    l.pHead = nullptr;
    l.pTail = nullptr;
}
void addTail(LIST &l, Node *addNode)
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
void PrintList(Node *head)
{
    if (head == nullptr)
    {
        cout << "Empty List.";
    }
    else
    {
        Node *p = head;
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
    PrintList(L.pHead);

    return 0;
}
