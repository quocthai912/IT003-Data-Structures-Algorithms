#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

Node *CreateNode(int data)
{
    Node *p = new Node;
    p->data = data;
    p->next = nullptr;
    return p;
}

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
};

int HF(int key, int M)
{
    return key % M;
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

void InsertHashTable(HashTable &ht, int key, vector<int> &mangDungDo)
{
    ht.n++;
    int index = HF(key, ht.M);
    if (ht.table[index].head != nullptr)
        mangDungDo[index]++;
    AddTail(ht.table[index], key);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, M;
    cin >> n >> M;
    vector<int> mangDungDo(M);
    HashTable ht;
    CreateEmptyHashTable(ht, M);
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        InsertHashTable(ht, key, mangDungDo);
    }
    int minDungDo = 0;
    for (int i = 0; i < M; i++)
    {
        if (mangDungDo[i] > minDungDo)
        {
            minDungDo = mangDungDo[i];
            break;
        }
    }
    for (int i = 0; i < M; i++)
    {
        if (mangDungDo[i] != 0 && mangDungDo[i] < minDungDo)
            minDungDo = mangDungDo[i];
    }
    for (int i = 0; i < M; i++)
    {
        if (mangDungDo[i] == minDungDo)
            cout << i << " ";
    }
    return 0;
}
