/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
template
class
typedef
vector
pair
set
map
###End banned keyword*/

#include <iostream>
using namespace std;
struct TIME
{
    int gio, phut, giay;
};

struct node
{
    TIME info;
    node *next;
};

struct List
{
    node *head;
    node *tail;
};

node *CreateNode(TIME t)
{
    node *p = new node;
    p->info = t;
    p->next = nullptr;
    return p;
}

void AddTail(List &l, node *p)
{
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

void CreateList(List &l)
{
    l.head = l.tail = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TIME t;
        cin >> t.gio >> t.phut >> t.giay;
        AddTail(l, CreateNode(t));
    }
}

bool SoSanhThoiGian(TIME &x, TIME &y)
{
    if (x.gio == y.gio)
    {
        if (x.phut == y.phut)
        {
            return x.giay < y.giay;
        }
        return x.phut < y.phut;
    }
    return x.gio < y.gio;
}

void Sort(List &l)
{
    if (l.head == nullptr || l.head->next == nullptr)
        return;
    // Pivot la phan tu dau
    node *pivot = CreateNode(l.head->info);
    // Khai bao hai list
    List before;
    List after;
    before.head = before.tail = after.head = after.tail = nullptr;
    node *p = l.head->next;
    while (p)
    {
        if (SoSanhThoiGian(pivot->info, p->info))
            AddTail(before, CreateNode(p->info));
        else
            AddTail(after, CreateNode(p->info));
        p = p->next;
    }
    Sort(before);
    Sort(after);
    // Noi before
    if (before.head == nullptr)
    {
        l.head = pivot;
    }
    else
    {
        l.head = before.head;
        before.tail->next = pivot;
    }
    // Noi after
    if (after.head == nullptr)
    {
        l.tail = pivot;
    }
    else
    {
        pivot->next = after.head;
        l.tail = after.tail;
    }
}

void PrintList(List l)
{
    if (l.head == nullptr)
    {
        cout << "Empty";
        return;
    }
    node *p = l.head;
    while (p)
    {
        cout << p->info.gio << "h" << p->info.phut << "p" << p->info.giay << "s" << endl;
        p = p->next;
    }
}

int main()
{
    List L;
    CreateList(L);
    Sort(L);
    PrintList(L);
    return 0;
}