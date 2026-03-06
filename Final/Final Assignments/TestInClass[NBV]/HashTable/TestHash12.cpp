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

int mangSoNguyenTo[10001];
int SoLuongSoNguyenTo = 0;

bool isPrime(int number)
{
    if (number < 2)
        return false;
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

void DuyetBangBam(Hashtable ht)
{
    for (int i = 0; i < ht.M; i++)
    {
        Node *p = ht.table[i].head;
        while (p)
        {
            if (isPrime(p->key))
                mangSoNguyenTo[SoLuongSoNguyenTo++] = p->key;
            p = p->next;
        }
    }
}

bool DeleteKey(Hashtable &ht, int key)
{
    int index = HF(key, ht.M);
    Node *p = ht.table[index].head;
    if (p == nullptr)
        return false;
    if (p->key == key)
    {
        RemoveHead(ht.table[index]);
        ht.n--;
        return true;
    }
    while (p->next)
    {
        if (p->next->key == key)
        {
            Node *q = p->next;
            p->next = q->next;
            delete q;
            ht.n--;
            return true;
        }
        p = p->next;
    }
    return false;
}

void DeleteHash(Hashtable &ht)
{
    DuyetBangBam(ht);
    if (SoLuongSoNguyenTo == 0)
    {
        cout << "Delete Failed" << endl;
        return;
    }
    for (int i = 0; i < SoLuongSoNguyenTo; i++)
    {
        if (!DeleteKey(ht, mangSoNguyenTo[i]))
        {
            cout << "Delete Failed" << endl;
            return;
        }
    }
    cout << "Delete Successful: ";
    for (int i = 0; i < SoLuongSoNguyenTo; i++)
    {
        cout << mangSoNguyenTo[i] << " ";
    }
    cout << endl;
}

int main()
{
    Hashtable H;
    int M, x;
    CreateEmptyHashtable(H, M);
    InputHashtable(H);
    cout << "Hash table before deletion" << endl;
    OutputHashtable(H);
    DeleteHash(H);
    cout << "Hash table after deletion" << endl;
    OutputHashtable(H);
    return 0;
}
