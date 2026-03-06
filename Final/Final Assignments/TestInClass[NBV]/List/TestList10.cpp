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

int tongGiay(TIME t)
{
    return t.gio * 3600 + t.phut * 60 + t.giay;
}

void PrintList(List l)
{
    if (l.head == nullptr)
    {
        cout << "Empty";
        return;
    }
    int tongGiayLonNhat = 0;
    node *p = l.head;
    while (p)
    {
        if (tongGiay(p->info) > tongGiayLonNhat)
            tongGiayLonNhat = tongGiay(p->info);
        p = p->next;
    }
    p = l.head;
    while (p)
    {
        if (tongGiay(p->info) == tongGiayLonNhat)
        {
            cout << p->info.gio << "h" << p->info.phut << "p" << p->info.giay << "s" << endl;
        }
        p = p->next;
    }
}

int main()
{
    List L;
    CreateList(L);
    PrintList(L);
    return 0;
}
