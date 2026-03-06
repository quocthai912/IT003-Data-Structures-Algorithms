// Xây dựng hoàn chỉnh Hash Table
// Xử lí đụng độ bằng phương pháp thăm dò tuyến tính
// In ra tổng số lần đụng độ của các khóa trong bảng băm
#include <iostream>
using namespace std;
#define EMPTY -1
#define DELETE -2

struct HashTable
{
    int M;
    int N;
    int *Table;
};

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

int HF(int key, int M)
{
    return key % M;
}

int HF_LinearProbling(int key, int M, int i)
{
    return (HF(key, M) + i) % M;
}

void InsertHashTable(HashTable &ht, int key, int &sumCollision)
{
    int nprob = 0;
    int index = HF(key, ht.M);
    while (ht.Table[index] != EMPTY && ht.Table[index] != DELETE && nprob < ht.M)
    {
        sumCollision++;
        nprob++;
        index = HF_LinearProbling(key, ht.M, nprob);
    }
    if (nprob >= ht.M)
        return;
    ht.Table[index] = key;
    ht.N++;
}

int main()
{
    HashTable ht;
    int M, n;
    cin >> M >> n;
    CreateEmptyHashTable(ht, M);
    int sumCollision = 0;
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        InsertHashTable(ht, key, sumCollision);
    }
    cout << sumCollision;
    return 0;
}