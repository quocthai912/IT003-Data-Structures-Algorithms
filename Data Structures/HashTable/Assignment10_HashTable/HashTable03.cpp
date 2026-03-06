/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <string>

#define LOAD 0.7
using namespace std;

struct Hocsinh
{
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Node
{
    Hocsinh data;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

Node *CreateNode(Hocsinh);
void CreateList(List &);
void AddTail(List &, Hocsinh);
int RemoveHead(List &);
int RemoveAfter(List &, Node *);
void DeleteList(List &);

struct Hashtable
{
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List *table;
};

void CreateHashtable(Hashtable &, int);
int Hash(Hashtable, int); // Ham bam ma so hoc sinh thanh chi so
int Delete(Hashtable &, int);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &x)
{
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}
int main()
{
    Hashtable hashtable;

    int m, n, k;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        hashtable.n += k;
        for (int j = 0; j < k; j++)
        {
            Input(hs);
            AddTail(hashtable.table[i], hs);
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;

        if (Delete(hashtable, k) == 0)
            cout << "KHONG XOA DUOC\n";
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
void CreateList(List &l)
{
    l.head = l.tail = NULL;
}

Node *CreateNode(Hocsinh x)
{
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->next = NULL;
    p->data = x;
    return p;
}

void AddTail(List &l, Hocsinh x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = l.tail = p;
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

void CreateHashtable(Hashtable &ht, int m)
{
    ht.table = new List[m];
    for (int i = 0; i < m; i++)
        CreateList(ht.table[i]);
    ht.M = m;
    ht.n = 0;
}

int Hash(Hashtable ht, int maso)
{
    return maso % ht.M;
}

void PrintHashtable(Hashtable ht)
{
    for (int i = 0; i < ht.M; i++)
    {
        Node *p = ht.table[i].head;
        while (p)
        {
            Hocsinh hs = p->data;
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "] ";
            p = p->next;
        }
        cout << '\n';
    }
}

void DeleteHashtable(Hashtable &ht)
{
    for (int i = 0; i < ht.M; i++)
    {
        DeleteList(ht.table[i]);
    }
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int Delete(Hashtable &ht, int maso)
{
    int index = Hash(ht, maso);
    Node *p = ht.table[index].head;
    if (p == nullptr)
        return 0;
    if (p->data.Maso == maso)
    {
        RemoveHead(ht.table[index]);
        ht.n--;
        return 1;
    }
    while (p->next)
    {
        if (p->next->data.Maso == maso)
        {
            Node *q = p->next;
            p->next = q->next;
            delete q;
            ht.n--;
            return 1;
        }
        p = p->next;
    }
    return 0;
}