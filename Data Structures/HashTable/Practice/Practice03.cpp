#include <iostream>
using namespace std;
#define LOAD 0.7
#define MAXTABLESIZE 10000

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
    if (l.tail == p)
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

void CreateEmptyHashtable(Hashtable &ht, int m)
{
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
void Insert(Hashtable &ht, int key)
{
    int index = HF(key, ht.M);
    AddTail(ht.table[index], key);
    ht.n++;
}
void InputHashtable(Hashtable &ht)
{
    int x;
    cin >> x;
    while (x != -1)
    {
        Insert(ht, x);
        cin >> x;
    }
}

void OutputHashtable(Hashtable ht)
{
    if (ht.n == 0)
    {
        cout << "Empty";
        return;
    }
    bool find = false;
    for (int i = 0; i < ht.M; i++)
    {
        Node *p = ht.table[i].head;
        if (p == nullptr)
        {
            cout << i << " ";
            find = true;
        }
    }
    if (!find)
    {
        cout << "NotFound";
    }
}

int main()
{
    Hashtable H;
    int M;
    cin >> M;
    CreateEmptyHashtable(H, M);
    InputHashtable(H);
    OutputHashtable(H);
    return 0;
}
