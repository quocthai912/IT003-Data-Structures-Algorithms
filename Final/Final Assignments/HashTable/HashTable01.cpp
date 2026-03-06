// Hàm băm giải quyết đụng độ theo phương pháp địa chỉ mở
#include <iostream>
#include <vector>
using namespace std;
#define EMPTY -1
struct HashTable
{
    int M;
    int N;
    int *Table;
};

int HF(int key, int M)
{
    return key % M;
}

int HF_LinearProbling(int key, int M, int i)
{
    return (HF(key, M) + i) % M;
}

void CreateEmptyHashTable(HashTable &ht, int M)
{
    ht.Table = new int[M];
    for (int i = 0; i < M; i++)
    {
        ht.Table[i] = EMPTY;
    }
    ht.M = M;
    ht.N = 0;
}

void InsertHashTable(HashTable &ht, int key, vector<int> &mangDungDo)
{
    int i = 0;
    int index = HF(key, ht.M);
    while (ht.Table[index] != EMPTY && i < ht.M)
    {
        mangDungDo[index]++;
        i++;
        index = HF_LinearProbling(key, ht.M, i);
    }
    if (i >= ht.M)
        return;
    ht.Table[index] = key;
    ht.N++;
}

int main()
{
    HashTable ht;
    int N, M;
    cin >> N >> M;
    vector<int> mangDungDo(M, 0);
    CreateEmptyHashTable(ht, M);
    for (int i = 0; i < N; i++)
    {
        int key;
        cin >> key;
        InsertHashTable(ht, key, mangDungDo);
    }
    // Tìm số lần đụng độ lớn nhất
    int maxDungDo = -1;
    for (int i = 0; i < mangDungDo.size(); i++)
    {
        if (mangDungDo[i] > maxDungDo)
            maxDungDo = mangDungDo[i];
    }
    for (int i = 0; i < mangDungDo.size(); i++)
    {
        if (mangDungDo[i] == maxDungDo)
            cout << i << " ";
    }
    return 0;
}
