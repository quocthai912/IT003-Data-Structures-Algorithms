#include <iostream>
#include <vector>
using namespace std;
vector<int> danhSach;
#define MAXTABLESIZE 10000
#define EMPTY -1
struct Hashtable
{
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    int *table;
};

int HF(int key, int M)
{
    return key % M;
}
int HF_LinearProbing(int key, int M, int i)
{
    return (HF(key, M) + i) % M;
}

int HF_QuadraticProbing(int key, int M, int i)
{
    return (HF(key, M) + i * i) % M;
}

int HF_DoubleHashing(int key, int M, int i, int f)
{
    return (HF(key, M) + i * f) % M;
}

void InitHashTable(Hashtable &ht, int M)
{
    ht.table = new int[M];
    if (ht.table == NULL)
        exit(1);
    for (int i = 0; i < M; i++)
    {
        ht.table[i] = -1;
    }
    ht.M = M;
    ht.n = 0;
}
int hamBamPhu(int key)
{
    return 7 - key % 7;
}
void Traverse(Hashtable ht)
{
    if (ht.n == 0)
    {
        cout << "Empty";
        return;
    }
    if (danhSach.empty())
    {
        cout << "NotFound";
    }
    else
    {
        for (int i = 0; i < danhSach.size(); i++)
        {
            cout << danhSach[i] << " ";
        }
    }
}
void InsertHashTable(Hashtable &ht, int key)
{
    int i = 0;
    int f = hamBamPhu(key);
    int index = HF(key, ht.M);
    while (ht.table[index] != -1 && i < ht.M)
    {
        i++;
        index = HF_DoubleHashing(key, ht.M, i, f);
    }
    if (i >= ht.M)
    {
        danhSach.push_back(key);
    }
    ht.table[index] = key;
    ht.n++;
}
void CreateHashTable(Hashtable &ht)
{
    int M;
    cin >> M;
    InitHashTable(ht, M);
    int x;
    cin >> x;
    while (x != -1)
    {
        InsertHashTable(ht, x);
        cin >> x;
    }
}

int main()
{
    Hashtable H;
    CreateHashTable(H);
    Traverse(H);
    return 0;
}
