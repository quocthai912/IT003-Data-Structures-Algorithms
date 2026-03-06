// Địa chỉ ít đụng độ nhất
// Bảng băm xử lí đụng độ bằng phương pháp nối kết
#include <iostream>
#include <vector>
using namespace std;
#define EMPTY nullptr

struct Node
{
    int key;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

Node *CreateNode(int key)
{
    Node *p = new Node;
    p->key = key;
    p->pNext = nullptr;
    return p;
}

void CreateEmptyList(List &l)
{
    l.pHead = l.pTail = nullptr;
}

void AddTail(List &l, Node *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

struct HashTable
{
    int M;
    int N;
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
    ht.M = M;
    ht.N = 0;
}

void InsertHashTable(HashTable &ht, int key, vector<int> &mangDungDo)
{
    int index = HF(key, ht.M);
    // Nếu địa chỉ đó không còn rỗng, tức xảy ra đụng độ
    if (ht.Table[index].pHead != EMPTY)
    {
        mangDungDo[index]++;
    }
    AddTail(ht.Table[index], CreateNode(key));
    ht.N++;
}

int main()
{
    HashTable ht;
    int N, M;
    cin >> N >> M;
    CreateEmptyHashTable(ht, M);
    vector<int> mangDungDo(M, 0);
    for (int i = 0; i < N; i++)
    {
        int key;
        cin >> key;
        InsertHashTable(ht, key, mangDungDo);
    }
    int minDungDo;
    // Không sử dụng Trick
    // Ta tìm vị trí có số lần đụng độ > 0 và gán Min
    for (int i = 0; i < mangDungDo.size(); i++)
    {
        if (mangDungDo[i] > 0)
        {
            minDungDo = mangDungDo[i];
            break;
        }
    }
    // Tìm số lần đụng độ ít nhất
    for (int i = 0; i < mangDungDo.size(); i++)
    {
        // Phải xảy ra đụng độ mới được tính
        if (mangDungDo[i] != 0 && mangDungDo[i] < minDungDo)
            minDungDo = mangDungDo[i];
    }
    // Xuất các vị trí thỏa mãn điều kiện
    for (int i = 0; i < mangDungDo.size(); i++)
    {
        if (mangDungDo[i] == minDungDo)
            cout << i << " ";
    }
    return 0;
}
