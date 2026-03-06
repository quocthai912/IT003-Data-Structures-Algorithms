#include <iostream>
#include <math.h>
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

Node *CreateNode(Point data)
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

double khoangCach(Point data)
{
    return sqrt((data.x * data.x) + (data.y * data.y) + (data.z * data.z));
}

int main()
{
    int n;
    List A;
    CreateEmptyList(A);
    double b, e;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Point data;
        cin >> data.x >> data.y >> data.z;
        AddTail(A, data);
    }
    cin >> b >> e;
    Node *p = A.head;
    bool found = false;
    while (p)
    {
        if (b <= khoangCach(p->data) && khoangCach(p->data) <= e)
        {
            found = true;
            cout << p->data.x << " " << p->data.y << " " << p->data.z << endl;
        }
        p = p->next;
    }
    if (!found)
    {
        cout << "KHONG";
    }
    return 0;
}
