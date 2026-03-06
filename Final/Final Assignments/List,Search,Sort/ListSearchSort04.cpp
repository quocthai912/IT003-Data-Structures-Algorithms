/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
[
]
###End banned keyword*/
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
// Thực hiện tìm kiếm tuyến tính
int LinearSeach(List l, Point target)
{
    if (l.pHead == nullptr)
        return -1;
    Node *p = l.pHead;
    int index = 0;
    while (p)
    {
        if (p->data.x == target.x && p->data.y == target.y && p->data.z == target.z)
        {
            return index;
        }
        index++;
        p = p->pNext;
    }
    return -1;
}

void run()
{
    int n;
    cin >> n;
    List A;
    List B;
    CreateEmptyList(A);
    CreateEmptyList(B);
    for (int i = 0; i < n; i++)
    {
        Point data;
        cin >> data.x >> data.y >> data.z;
        AddTail(A, CreateNode(data));
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        Point data;
        cin >> data.x >> data.y >> data.z;
        AddTail(B, CreateNode(data));
    }
    Node *p = B.pHead;
    while (p)
    {
        int index = LinearSeach(A, p->data);
        if (index != -1)
            cout << index << endl;
        else
            cout << "KHONG" << endl;
        p = p->pNext;
    }
}

int main()
{

    int *a = new int[256];
    int *b = new int[256];
    delete[] a;
    run();
    delete[] b;
}
