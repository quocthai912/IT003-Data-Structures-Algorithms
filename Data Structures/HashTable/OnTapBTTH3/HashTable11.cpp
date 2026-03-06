// Tìm danh sách các địa chỉ (index) trong bảng băm xảy ra đụng độ nhiều nhất.
#include <iostream>
#include <vector>
#define EMPTY -1
using namespace std;
struct HASHTABLE
{
    int M;
    int N;
    int *table;
};
int HF(int key, int M)
{
    return key % M;
}
int HF2(int key, int M)
{
    return 1 + (key % (M - 2));
}
int HF_Probling(int key, int M, int i)
{
    return (HF(key, M) + i * HF2(key, M)) % M;
}
void CreateEmptyHashTable(HASHTABLE &ht, int M)
{
    ht.table = new int[M];
    for (int i = 0; i < M; i++)
    {
        ht.table[i] = EMPTY;
    }
    ht.N = 0;
    ht.M = M;
}
void InsertHashTable(HASHTABLE &ht, int key, vector<int> &danhSach)
{
    int index = HF(key, ht.M);
    int i = 0;
    while (ht.table[index] != EMPTY && i < ht.M)
    {
        if (ht.table[index] == key)
            return;
        danhSach[index]++;
        i++;
        if (i >= ht.M)
            return;
        index = HF_Probling(key, ht.M, i);
    }
    ht.table[index] = key;
    ht.N++;
}
void CreateHashTable(HASHTABLE &ht, vector<int> &danhSach)
{
    int M;
    cin >> M;
    danhSach.resize(M);
    for (int i = 0; i < M; i++)
    {
        danhSach[i] = 0;
    }
    CreateEmptyHashTable(ht, M);
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        InsertHashTable(ht, temp, danhSach);
        cin >> temp;
    }
}
void PrintHashTable(HASHTABLE ht)
{
    for (int i = 0; i < ht.M; i++)
    {
        cout << i << "| ";
        if (ht.table[i] == EMPTY)
            cout << "EMPTY";
        else
            cout << ht.table[i] << " ";
        cout << endl;
    }
}
void PrintIndex(HASHTABLE ht, vector<int> danhSach)
{
    int maxLanDungDo = -1;
    for (int i = 0; i < danhSach.size(); i++)
    {
        if (danhSach[i] > maxLanDungDo)
            maxLanDungDo = danhSach[i];
    }
    if (maxLanDungDo == 0)
    {
        cout << "NotFound";
        return;
    }
    for (int i = 0; i < danhSach.size(); i++)
    {
        if (danhSach[i] == maxLanDungDo)
            cout << i << " ";
    }
}
int main()
{
    HASHTABLE ht;
    vector<int> danhSach;
    CreateHashTable(ht, danhSach);
    PrintHashTable(ht);
    PrintIndex(ht, danhSach);
    return 0;
}
