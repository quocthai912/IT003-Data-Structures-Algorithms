#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int key;
    Node *pNext;
};

Node *CreateNode(int key)
{
    Node *p = new Node;
    p->key = key;
    p->pNext = nullptr;
    return p;
}

struct List
{
    Node *pHead;
    Node *pTail;
};

void CreateEmptyList(List &l)
{
    l.pHead = l.pTail = nullptr;
}

void AddTail(List &l, int key)
{
    Node *p = CreateNode(key);
    if (l.pHead == nullptr)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

struct HashTable
{
    int N;
    int M;
    List *Table;
};

int HF(int key, int M)
{
    return key % M;
}

void CreateEmptyHashTable(HashTable &ht, int M)
{
    ht.Table = new List[M];
    for (int i = 0; i < M; i++)
    {
        CreateEmptyList(ht.Table[i]);
    }
    ht.N = 0;
    ht.M = M;
}

void InsertHashTable(HashTable &ht, int key, vector<int> &mangDungDo)
{
    int index = HF(key, ht.M);
    if (ht.Table[index].pHead != nullptr)
        mangDungDo[index]++;
    AddTail(ht.Table[index], key);
    ht.N++;
}

int main()
{
    int n, M;
    cin >> n >> M;
    HashTable ht;
    CreateEmptyHashTable(ht, M);
    vector<int> mangDungDo(M);
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        InsertHashTable(ht, key, mangDungDo);
    }
    int maxDungDo = -1;
    for (int i = 0; i < mangDungDo.size(); i++)
    {
        if (mangDungDo[i] > maxDungDo)
            maxDungDo = mangDungDo[i];
    }
    for (int i = 0; i < mangDungDo.size(); i++)
    {
        if (mangDungDo[i] == maxDungDo)
            cout << i << endl;
    }
    return 0;
}
