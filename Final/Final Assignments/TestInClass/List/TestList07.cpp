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
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ps key;
        cin >> key.ts >> key.ms;
        AddTail(l, CreateNode(key));
    }
}

double tinhPhanSo(ps key)
{
    return key.ts / (key.ms * 1.0);
}

void PrintList(List l)
{
    if (l.head == nullptr)
    {
        cout << "Empty";
        return;
    }
    ps T;
    cin >> T.ts >> T.ms;
    bool found = false;
    node *p = l.head;
    while (p)
    {
        if (tinhPhanSo(p->info) == tinhPhanSo(T))
        {
            cout << p->info.ts << "/" << p->info.ms << endl;
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