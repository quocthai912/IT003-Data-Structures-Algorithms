// Dùng danh sách liên kết đơn để quản lý và tìm kiếm n điểm trong không gian 3 chiều
#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x, y, z;
};

struct Node
{
    Point data;
    Node *pNext;
};

Node *CreateNode(Point data)
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

void AddTail(List &l, Node *p)
{
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

double Distance(Point data)
{
    // Căn của x^2 + y^2 + z^2
    return sqrt(data.x * data.x + data.y * data.y + data.z * data.z);
}

int main()
{
    int n;
    cin >> n;
    List A;
    CreateEmptyList(A);
    for (int i = 0; i < n; i++)
    {
        Point data;
        cin >> data.x >> data.y >> data.z;
        AddTail(A, CreateNode(data));
    }
    double b, e;
    cin >> b >> e;
    Node *p = A.pHead;
    bool found = false;
    while (p)
    {
        if (Distance(p->data) >= b && Distance(p->data) <= e)
        {
            found = true;
            cout << p->data.x << " " << p->data.y << " " << p->data.z << endl;
        }
        p = p->pNext;
    }
    if (!found)
    {
        cout << "KHONG";
    }
    return 0;
}