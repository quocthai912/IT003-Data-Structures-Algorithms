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
struct ps
{
    int ts, ms;
};

struct node
{
    ps info;
    node *next;
};

struct List
{
    node *head;
    node *tail;
};

node *CreateNode(ps key)
{
    node *p = new node;
    p->info = key;
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

double tinhPhanSo(ps key)
{
    return key.ts / (key.ms * 1.0);
}

void CreateList(List &l)
{
    l.head = l.tail = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ps key;
        cin >> key.ts >> key.ms;
        AddTail(l, CreateNode(key));
    }
}

void PrintList(List l)
{
    if (l.head == nullptr)
    {
        cout << "Empty";
        return;
    }
    // Tim min phan so
    double minPhanSo = tinhPhanSo(l.head->info);
    node *p = l.head;
    while (p)
    {
        if (tinhPhanSo(p->info) < minPhanSo)
            minPhanSo = tinhPhanSo(p->info);
        p = p->next;
    }
    p = l.head;
    while (p)
    {
        if (tinhPhanSo(p->info) == minPhanSo)
        {
            cout << p->info.ts << "/" << p->info.ms << " ";
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
