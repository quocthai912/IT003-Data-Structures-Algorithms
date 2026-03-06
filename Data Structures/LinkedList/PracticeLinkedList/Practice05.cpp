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
    l.pHead = l.pTail = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Book temp;
        cin >> temp.maSach >> temp.tenSach >> temp.loaiSach;
        addTail(l, CreateNode(temp));
    }
}
void Delete(List &l)
{
    if (l.pHead == nullptr)
        return;
    if (l.pHead == l.pTail)
    {
        if (l.pHead->b.maSach < 10)
        {
            NODE *p = l.pHead;
            l.pHead = l.pTail = nullptr;
            delete p;
        }
    }
    NODE dummyNode;
    dummyNode.pNext = l.pHead;
    NODE *currentNode = &dummyNode;
    while (currentNode->pNext)
    {
        if (currentNode->pNext->b.maSach < 10)
        {
            NODE *xoaNode = currentNode->pNext;
            currentNode->pNext = xoaNode->pNext;
            delete xoaNode;
        }
        else
            currentNode = currentNode->pNext;
    }
    l.pHead = dummyNode.pNext;
}
void Output(List &l)
{
    if (l.pHead == nullptr)
    {
        cout << "Empty";
        return;
    }
    NODE *p = l.pHead;
    while (p)
    {
        cout << p->b.maSach << " " << p->b.tenSach << " " << p->b.loaiSach << endl;
        p = p->pNext;
    }
}
int main()
{
    List L;
    Input(L);
    Delete(L);
    Output(L);
    return 0;
}
