#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *CreateNode(int data)
{
    Node *p = new Node;
    p->data = data;
    p->next = nullptr;
    return p;
}

struct List
{
    Node *head;
    Node *tail;
};

void AddTail(List &l, int data)
{
    Node *p = CreateNode(data);
    if (l.head == nullptr)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void AddHead(List &l, int data)
{
    Node *p = CreateNode(data);
    if (l.head == nullptr)
    {
        l.head = l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

int main()
{
    int n;
    cin >> n;
    List l;
    l.head = l.tail = nullptr;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        if (data >= 90)
        {
            count++;
            if (count <= 10)
                AddHead(l, data);
        }
    }
    Node *p = l.head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "END";
    return 0;
}
