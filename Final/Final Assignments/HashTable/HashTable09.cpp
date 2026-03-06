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
    int N;
    List *table;
};

void CreateEmptyHashTable(HashTable &ht, int M)
{
    ht.table = new List[M];
    for (int i = 0; i < M; i++)
    {
        CreateEmptyList(ht.table[i]);
    }
    ht.N = 0;
    ht.M = M;
}

int HF(int key, int M)
{
    return key % M;
}

void InsertHashTable(HashTable &ht, int key, int &soLanDungDo)
{
    int index = HF(key, ht.M);
    if (ht.table[index].head != nullptr)
    {
        soLanDungDo++;
    }
    AddTail(ht.table[index], key);
    ht.N++;
}

int main()
{
    int N, M;
    HashTable ht;
    cin >> N >> M;
    CreateEmptyHashTable(ht, M);
    int soLanDungDo = 0;
    for (int i = 0; i < N; i++)
    {
        int key;
        cin >> key;
        InsertHashTable(ht, key, soLanDungDo);
    }
    double tyLe = soLanDungDo / (N * 1.0);
    if (tyLe > 0.33)
    {
        cout << "BAD";
    }
    else
    {
        cout << "GOOD";
    }
    return 0;
}
