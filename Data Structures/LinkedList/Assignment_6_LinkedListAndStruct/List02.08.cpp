/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <cmath>
#include <iostream>

using namespace std;
struct Point
{
    int x, y;
};
struct NODE
{
    Point value;
    NODE *pNext;
};
NODE *initNode(Point value)
{
    NODE *p = new NODE;
    p->value.x = value.x;
    p->value.y = value.y;
    p->pNext = nullptr;
    return p;
}
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
void CreateEmptyList(LIST &L)
{
    L.pHead = nullptr;
    L.pTail = nullptr;
}
void addTail(LIST &L, NODE *addNode)
{
    if (L.pHead == nullptr)
    {
        L.pHead = L.pTail = addNode;
    }
    else
    {
        L.pTail->pNext = addNode;
        L.pTail = addNode;
    }
}
void Nhap(LIST &L)
{
    int size;
    cin >> size;
    Point diem;
    for (int i = 0; i < size; i++)
    {
        cin >> diem.x >> diem.y;
        addTail(L, initNode(diem));
    }
}
void Xuat(LIST L)
{
    NODE *p = L.pHead;
    while (p)
    {
        cout << "(" << p->value.x << ", " << p->value.y << ")" << endl;
        p = p->pNext;
    }
}
int main()
{
    LIST points;
    CreateEmptyList(points);
    Nhap(points);

    Xuat(points);

    return 0;
}
