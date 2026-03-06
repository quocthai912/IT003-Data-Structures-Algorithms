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

void AddHead(List &l, node *p)
{
    if (l.head == nullptr)
    {
        l.head = l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
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
        AddHead(l, CreateNode(t));
    }
}

int TongThoiGian(TIME t)
{
    return (t.gio * 3600) + (t.phut * 60) + t.giay;
}

void PrintList(List l)
{
    if (l.head == nullptr)
    {
        cout << "Empty";
        return;
    }
    bool found = false;
    TIME target;
    cin >> target.gio >> target.phut >> target.giay;
    node *p = l.head;
    while (p)
    {
        if (TongThoiGian(p->info) == TongThoiGian(target))
        {
            cout << p->info.gio << "h" << p->info.phut << "p" << p->info.giay << "s" << endl;
            found = true;
        }
        p = p->next;
    }
    if (!found)
    {
        cout << "NotFound";
    }
}

int main()
{
    List L;
    CreateList(L);
    PrintList(L);
    return 0;
}
