#include <iostream>
using namespace std;

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

void Traverse(Hashtable ht)
{
    if (ht.n == 0){
        cout << "Empty";
        return;
    }
    for (int i = 0; i < ht.M; i++)
    {
        int index = HF_LinearProbing(ht.table[i], ht.M, 0);
        cout << i << "| ";
        if (ht.table[i] != -1)
            cout << ht.table[i];
        else
            cout << "NULL";
        if (index != i && ht.table[i] != -1)
        {
            cout << " (Collision)";
        }
        cout << endl;
    }
}
void InsertHashTable(Hashtable &ht, int key)
{
    int i = 0;
    int index = HF_LinearProbing(key, ht.M, i);
    while (ht.table[index] != -1 && i < ht.M)
    {
        i++;
        index = HF_LinearProbing(key, ht.M, i);
    }
    if (i >= ht.M)
        return;
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
