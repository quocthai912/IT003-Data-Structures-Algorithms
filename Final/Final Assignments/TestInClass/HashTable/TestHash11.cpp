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
exit
###End banned keyword*/

#include <iostream>
using namespace std;
#define LOAD 0.7

struct Node
{
    int key;
    Node *next;
};
struct List
{
    Node *head;
    Node *tail;
};

struct Hashtable
{
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List *table;
};

Node *CreateNode(int x)
{
    Node *p = new Node;
    p->key = x;
    p->next = NULL;
    return p;
}

void AddTail(List &l, int x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

int RemoveHead(List &l)
{
    if (l.head == NULL)
        return 0;
    Node *p = l.head;
    l.head = p->next;
    if (l.head == NULL)
        l.tail = NULL;
    delete p;
    return 1;
}

int RemoveAfter(List &l, Node *q)
{
    if (l.head == NULL)
        return 0;
    if (q == NULL)
        return RemoveHead(l);
    if (q->next == NULL)
        return 0;
    Node *p = q->next;
    q->next = p->next;
    if (l.tail == p)
        l.tail = q;
    delete p;
    return 1;
}

void DeleteList(List &l)
{
    while (l.head)
    {
        Node *p = l.head;
        l.head = p->next;
        delete p;
    }
    l.head = l.tail = NULL;
}

void CreateEmptyList(List &l)
{
    l.head = NULL;
    l.tail = NULL;
}

void CreateEmptyHashtable(Hashtable &ht, int &m)
{
    cin >> m;
    ht.table = new List[m];
    for (int i = 0; i < m; i++)
        CreateEmptyList(ht.table[i]);
    ht.M = m;
    ht.n = 0;
}

int HF(int key, int M)
{
    return key % M;
}

void InputHashtable(Hashtable &ht)
{
    int x;
    cin >> x;
    while (x != -1)
    {
        int i = HF(x, ht.M);
        AddTail(ht.table[i], x);
        ht.n++;
        cin >> x;
    }
}

void OutputHashtable(Hashtable ht)
{
    for (int i = 0; i < ht.M; i++)
    {
        cout << i << ": ";
        Node *p = ht.table[i].head;
        if (p == NULL)
        {
            cout << "NULL" << endl;
            continue;
        }
        cout << p->key;
        p = p->next;
        while (p != NULL)
        {
            cout << " --> " << p->key;
            p = p->next;
        }
        cout << endl;
    }
    cout << "----------------------------" << endl;
}

void DeleteHashtable(Hashtable &ht, int x)
{
    int index = HF(x, ht.M);
    Node *p = ht.table[index].head;
    if (p == nullptr)
    {
        cout << x << ": Delete Failed" << endl;
        return;
    }
    if (p->key == x)
    {
        RemoveHead(ht.table[index]);
        cout << x << ": Delete Successful" << endl;
        return;
    }
    while (p->next)
    {
        if (p->next->key == x)
        {
            Node *q = p->next;
            p->next = q->next;
            delete q;
            cout << x << ": Delete Successful" << endl;
            return;
        }
        p = p->next;
    }
    cout << x << ": Delete Failed" << endl;
}

int main()
{
    Hashtable H;
    int M, x;
    CreateEmptyHashtable(H, M);
    InputHashtable(H);
    cin >> x;
    cout << "Hash table before deletion" << endl;
    OutputHashtable(H);
    DeleteHashtable(H, x);
    cout << "Hash table after deletion" << endl;
    OutputHashtable(H);
    return 0;
}
