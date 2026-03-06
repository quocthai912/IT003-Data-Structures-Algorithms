#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *pNext;
};

Node *CreateNode(int data)
{
    Node *p = new Node;
    p->data = data;
    p->pNext = nullptr;
    return p;
}

struct List
{
    Node *pHead;
    Node *pTail;
};

void CreateEmptyList(List &l)
{
    l.pHead = l.pTail = nullptr;
}

void AddTail(List &l, int data)
{
    Node *p = CreateNode(data);
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

int midDataList(List l, int count)
{
    if (l.pHead == nullptr)
        return -1;
    Node *fast = l.pHead;
    Node *slow = l.pHead;
    Node *prev = nullptr;
    while (fast && fast->pNext)
    {
        fast = fast->pNext->pNext;
        prev = slow;
        slow = slow->pNext;
    }
    if (count % 2 != 0)
    {
        return slow->data;
    }
    return prev->data;
}

int main()
{
    int n;
    cin >> n;
    List l;
    CreateEmptyList(l);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        if (data % 2 == 0)
        {
            count++;
            AddTail(l, data);
        }
    }
    cout << midDataList(l, count);
    return 0;
}