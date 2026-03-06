#include <iostream>
#include <stack>

#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
bool Negative = false;
struct Node
{
    int num;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

Node *CreateNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->num = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l)
{
    l.head = l.tail = NULL;
}

void AddHead(List &l, int x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, int x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node *RemoveHead(List &l)
{
    if (l.head == NULL)
        return NULL;
    Node *p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l)
{
    if (Negative)
        cout << "- ";
    Node *p = l.head;
    while (p != NULL)
    {
        cout << p->num << ' ';
        p = p->next;
    }
}
void Tru(List, List, List &);

int main()
{
    List a, b, c;
    CreateList(a);
    CreateList(b);
    CreateList(c);
    int m, n, k;

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        AddTail(a, k);
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        AddTail(b, k);
    }

    Tru(a, b, c);
    PrintList(c);
    return 0;
}

int Count(List a)
{
    int count = 0;
    Node *p = a.head;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

bool Compare(List a, List b)
{
    if (Count(a) == Count(b))
    {
        Node *pA = a.head;
        Node *pB = b.head;
        while (pA)
        {
            if (pA->num < pB->num)
                return true;
            pA = pA->next;
            pB = pB->next;
        }
    }
    return Count(a) < Count(b);
}

void Tru(List a, List b, List &c)
{
    if (Compare(a, b))
    {
        swap(a, b);
        Negative = true;
    }
    stack<Node *> st1;
    stack<Node *> st2;
    Node *pA = a.head;
    Node *pB = b.head;
    while (pA)
    {
        st1.push(pA);
        pA = pA->next;
    }
    while (pB)
    {
        st2.push(pB);
        pB = pB->next;
    }
    int borrow = 0;
    while (!st1.empty() || !st2.empty())
    {
        int num1 = 0;
        int num2 = 0;
        if (!st1.empty())
        {
            num1 = st1.top()->num;
            st1.pop();
        }
        if (!st2.empty())
        {
            num2 = st2.top()->num;
            st2.pop();
        }
        num1 -= borrow;
        if (num1 < num2)
        {
            num1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        AddHead(c, num1 - num2);
    }
    if (c.head->num == 0)
    {
        while (c.head->next != nullptr && c.head->num == 0)
        {
            RemoveHead(c);
        }
    }
}
