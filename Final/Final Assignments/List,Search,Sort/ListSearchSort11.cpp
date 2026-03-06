#include <iostream>
#include <vector>
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
        l.head = l.tail = p;
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
};

int HF(int key, HashTable ht)
{
    return key % ht.M;
}

void CreateEmptyHashTable(HashTable &ht, int M)
{
    ht.table = new List[M];
    for (int i = 0; i < M; i++)
    {
        CreateEmptyList(ht.table[i]);
    }
    ht.n = 0;
    ht.M = M;
}

void InsertHashTable(HashTable &ht, int key, vector<int> &collisions)
{
    int index = HF(key, ht);
    if (ht.table[index].head != nullptr)
        collisions[index]++;
    AddTail(ht.table[index], key);
    ht.n++;
}

int main()
{
    int n, M;
    cin >> n >> M;
    vector<int> collisions(M, 0);
    HashTable ht;
    CreateEmptyHashTable(ht, M);
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        InsertHashTable(ht, key, collisions);
    }
    int maxDungDo = -1;
    for (int i = 0; i < collisions.size(); i++)
    {
        if (collisions[i] > maxDungDo)
            maxDungDo = collisions[i];
    }
    for (int i = 0; i < collisions.size(); i++)
    {
        if (collisions[i] == maxDungDo)
            cout << i << endl;
    }
    return 0;
}
