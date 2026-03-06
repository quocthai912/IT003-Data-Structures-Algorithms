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
    int N;
    int M;
    List *table;
    double LOAD;
};

void CreateEmptyHashTable(HashTable &ht, int M, double LOAD)
{
    ht.table = new List[M];
    for (int i = 0; i < M; i++)
    {
        CreateEmptyList(ht.table[i]);
    }
    ht.N = 0;
    ht.M = M;
    ht.LOAD = LOAD;
}

int HF(int key, int M)
{
    return key % M;
}

void InsertHashTable(HashTable &ht, int key)
{
    ht.N++;
    if (ht.N > ht.M * ht.LOAD)
        return;
    int index = HF(key, ht.M);
    AddTail(ht.table[index], key);
}

int Search(HashTable ht, int key)
{
    int index = HF(key, ht.M);
    Node *p = ht.table[index].head;
    int compareKey = 0;
    while (p)
    {
        compareKey++;
        if (p->data == key)
            return compareKey;
        p = p->next;
    }
    return -1;
}

int main()
{
    int M, N;
    double LOAD;
    cin >> M >> LOAD >> N;
    HashTable ht;
    CreateEmptyHashTable(ht, M, LOAD);
    for (int i = 0; i < N; i++)
    {
        int key;
        cin >> key;
        InsertHashTable(ht, key);
    }
    int k;
    cin >> k;
    List result;
    CreateEmptyList(result);
    for (int i = 0; i < k; i++)
    {
        int key;
        cin >> key;
        int compareKey = Search(ht, key);
        AddTail(result, compareKey);
    }
    Node *p = result.head;
    while (p)
    {
        if (p->data == -1)
        {
            cout << "KHONG" << endl;
        }
        else
        {
            cout << p->data << endl;
        }
        p = p->next;
    }
    return 0;
}