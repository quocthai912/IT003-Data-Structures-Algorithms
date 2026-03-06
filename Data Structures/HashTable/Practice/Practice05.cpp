#include <iostream>
using namespace std;

#define MAXTABLESIZE 10000

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
    for (int i = 0; i < ht.M; i++)
    {
        cout << i << " --> " << ht.table[i];
        cout << endl;
    }
}
void InsertHashTable(Hashtable &ht, int key)
{
    int i = 0;
    int index = HF(key, ht.M);
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
int search(Hashtable ht, int key)
{
    int i = 0;
    int index = HF(key, ht.M);
    cout << "H(" << key << ")=" << index;
    if (ht.table[index] == -1)
    {
        cout << " (Empty)";
        return -1;
    }
    while (ht.table[index] != -1 && i < ht.M)
    {
        if (ht.table[index] == key)
            return index;
        cout << " (Collision)";
        i++;
        if (i < ht.M)
        {
            cout << endl;
            index = HF_LinearProbing(key, ht.M, i);
            cout << "prob(" << key << "," << i << ")=" << index;
        }
    }
    if (ht.table[index] == -1)
    {
        cout << " (Empty)";
        return -1;
    }
    return -1;
}
void Fun(Hashtable ht)
{
    int key;
    cin >> key;
    int x = search(ht, key);
    cout << endl;
    if (x != -1)
    {
        cout << key << " found in bucket " << x;
    }
    else
        cout << key << " not found";
}

int main()
{
    Hashtable H;
    CreateHashTable(H);
    Fun(H);
    return 0;
}
