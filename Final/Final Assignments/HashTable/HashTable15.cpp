#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *CreateNode(int data)
{
    Node *p = new Node;
    p->data = data;
    p->next = nullptr;
    return p;
}

struct List
{
    Node *head;
    Node *tail;
};

void CreateEmptyList(List &l)
{
    l.head = l.tail = nullptr;
}

void AddTail(List &l, int data)
{
    Node *p = CreateNode(data);
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

struct HashTable
{
    int M;
    int n;
    List *table;
    double load;
};

void CreateEmptyHashTable(HashTable &ht, int M, double load)
{
    ht.table = new List[M];
    for (int i = 0; i < M; i++)
    {
        CreateEmptyList(ht.table[i]);
    }
    ht.load = load;
    ht.M = M;
    ht.n = 0;
}

int HF(int key, int M)
{
    return key % M;
}

void InsertHashTable(HashTable &ht, int key)
{
    ht.n++;
    if (ht.n > ht.load * ht.M)
        return;
    int index = HF(key, ht.M);
    AddTail(ht.table[index], key);
}

int timKiem(HashTable ht, int key)
{
    int chiPhi = 0;
    int index = HF(key, ht.M);
    Node *p = ht.table[index].head;
    while (p)
    {
        chiPhi++;
        if (p->data == key)
            return chiPhi;
        p = p->next;
    }
    return -1;
}

int main()
{
    int M, N;
    double load;
    HashTable ht;
    cin >> M >> load >> N;
    CreateEmptyHashTable(ht, M, load);
    for (int i = 0; i < N; i++)
    {
        int key;
        cin >> key;
        InsertHashTable(ht, key);
    }
    int q;
    cin >> q;
    List soLuongTruyVan;
    CreateEmptyList(soLuongTruyVan);
    for (int i = 0; i < q; i++)
    {
        int truyVan;
        cin >> truyVan;
        AddTail(soLuongTruyVan, truyVan);
    }
    Node *h = soLuongTruyVan.head;
    while (h)
    {
        int chiPhiTimKiem = timKiem(ht, h->data);
        if (chiPhiTimKiem == -1)
            cout << "KHONG" << endl;
        else
            cout << chiPhiTimKiem << endl;
        h = h->next;
    }
    return 0;
}
