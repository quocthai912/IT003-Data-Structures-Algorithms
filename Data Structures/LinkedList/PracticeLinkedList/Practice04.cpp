#include <bits/stdc++.h>
using namespace std;
struct Book
{
    int maSach;
    string tenSach;
    char loaiSach;
};
struct NODE
{
    Book b;
    NODE *pNext;
};
NODE *CreateNode(Book b)
{
    NODE *p = new NODE;
    p->b = b;
    p->pNext = nullptr;
    return p;
}
struct List
{
    NODE *pHead;
    NODE *pTail;
};
void addTail(List &l, NODE *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
        return;
    }
    l.pTail->pNext = p;
    l.pTail = p;
}
void Input(List &l)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Book temp;
        cin >> temp.maSach >> temp.tenSach >> temp.loaiSach;
        addTail(l, CreateNode(temp));
    }
}
int demSoLanXuatHien(const List &l, char kiTu)
{
    int count = 0;
    NODE *p = l.pHead;
    while (p)
    {
        if (p->b.loaiSach == kiTu)
            count++;
        p = p->pNext;
    }
    return count;
}
bool linearSearch(const List &l, NODE *p)
{
    if (l.pHead == nullptr)
        return false;
    NODE *q = l.pHead;
    while (q)
    {
        if (q->b.loaiSach == p->b.loaiSach)
            return true;
        q = q->pNext;
    }
    return false;
}
void Output(const List &l)
{
    List result;
    result.pHead = result.pTail = nullptr;
    NODE *p = l.pHead;
    while (p)
    {
        int soLanXuatHien = demSoLanXuatHien(l, p->b.loaiSach);
        if (!linearSearch(result, p))
        {
            cout << p->b.loaiSach << ": " << soLanXuatHien << endl;
            addTail(result, CreateNode(p->b));
        }
        p = p->pNext;
    }
}
int main()
{
    List L;
    Input(L);
    Output(L);
    return 0;
}
