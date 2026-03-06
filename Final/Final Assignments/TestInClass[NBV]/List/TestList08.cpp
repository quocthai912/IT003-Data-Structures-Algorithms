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
    if (l.head == nullptr)
    {
        cout << "Empty";
    }
}

double tinhPhanSo(ps key)
{
    return key.ts / (key.ms * 1.0);
}

void Sort(List &l)
{
    // Dieu kien dung
    if (l.head == nullptr || l.head->next == nullptr)
        return;
    // Pivot la head
    node *pivot = CreateNode(l.head->info);
    // Khoi tao 2 list
    List before;
    List after;
    before.head = before.tail = after.head = after.tail = nullptr;
    node *p = l.head->next;
    while (p)
    {
        if (tinhPhanSo(p->info) < tinhPhanSo(pivot->info))
        {
            AddTail(before, CreateNode(p->info));
        }
        else
        {
            AddTail(after, CreateNode(p->info));
        }
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
    for (node *p = l.head; p != NULL; p = p->next)
        cout << p->info.ts << "/" << p->info.ms << endl;
}

int main()
{
    List L;
    CreateList(L);
    Sort(L);
    PrintList(L);
    return 0;
}
