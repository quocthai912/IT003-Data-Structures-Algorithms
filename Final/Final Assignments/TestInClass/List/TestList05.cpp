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

int Euclid(int ts, int ms)
{
    while (ms > 0)
    {
        int temp = ts % ms;
        ts = ms;
        ms = temp;
    }
    return ts;
}

void RutGon(ps &PS)
{
    int ucln = Euclid(PS.ts, PS.ms);
    PS.ts /= ucln;
    PS.ms /= ucln;
}

node *CreateNode(ps PS)
{
    node *p = new node;
    p->info = PS;
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
    int n;
    cin >> n;
    l.head = l.tail = nullptr;
    for (int i = 0; i < n; i++)
    {
        ps PS;
        cin >> PS.ts >> PS.ms;
        RutGon(PS);
        AddTail(l, CreateNode(PS));
    }
}

void PrintList(List l)
{
    node *p = l.head;
    while (p)
    {
        cout << p->info.ts << "/" << p->info.ms << endl;
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
