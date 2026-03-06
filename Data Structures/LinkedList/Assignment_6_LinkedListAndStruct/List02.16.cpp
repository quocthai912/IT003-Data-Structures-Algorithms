/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <cmath>
#include <iostream>

using namespace std;
struct Point
{
    int x, y;
};
double khoangCachHaiDiem(Point A, Point B)
{
    return sqrt(pow((B.x - A.x), 2) + pow(B.y - A.y, 2));
}
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
NODE *DiemGanGocToaDoNhat(LIST L)
{
    Point gocToaDo = {0, 0};
    double min = khoangCachHaiDiem(gocToaDo, L.pHead->value);
    NODE *result = L.pHead;
    NODE *p = L.pHead->pNext;
    while (p)
    {
        if (khoangCachHaiDiem(gocToaDo, p->value) < min)
        {
            min = khoangCachHaiDiem(gocToaDo, p->value);
            result = p;
        }
        p = p->pNext;
    }
    return result;
}
void Xuat(NODE *result)
{
    cout << "(" << result->value.x << ", " << result->value.y << ")";
}
int main()
{
    LIST points;
    CreateEmptyList(points);
    Nhap(points);

    std::cout << "Diem gan goc toa do nhat la: ";
    Xuat(DiemGanGocToaDoNhat(points));

    return 0;
}
