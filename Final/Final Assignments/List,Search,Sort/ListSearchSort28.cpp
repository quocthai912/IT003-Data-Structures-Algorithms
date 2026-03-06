#include <iostream>
using namespace std;

struct Point
{
    double x, y, z;
};

struct Node
{
    Point data;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

Node *CreateNode(Point data)
{
    Node *p = new Node;
    p->data = data;
    p->next = nullptr;
    return p;
}

void CreateEmptyList(List &l)
{
    l.head = l.tail = nullptr;
}

void AddTail(List &l, Point data)
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

int LinearSearch(const List &A, const Point &target)
{
    int index = 0;
    Node *p = A.head;
    while (p)
    {
        if (p->data.x == target.x && p->data.y == target.y && p->data.z == target.z)
            return index;
        p = p->next;
        index++;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    List A;
    CreateEmptyList(A);
    for (int i = 0; i < n; i++)
    {
        Point data;
        cin >> data.x >> data.y >> data.z;
        AddTail(A, data);
    }
    List P;
    CreateEmptyList(P);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        Point target;
        cin >> target.x >> target.y >> target.z;
        AddTail(P, target);
    }
    Node *p = P.head;
    while (p)
    {
        int index = LinearSearch(A, p->data);
        if (index == -1)
        {
            cout << "KHONG";
        }
        else
        {
            cout << index;
        }
        cout << endl;
        p = p->next;
    }
    return 0;
}