/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
template
class
typedef
vector
pair
set
map
exit
###End banned keyword*/

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
    if (ht.n == 0)
    {
        cout << "Empty";
        return;
    }
    for (int i = 0; i < ht.M; i++)
        cout << i << "\t";
    cout << "\n---------------------------------------------------------------------------" << endl;
    for (int i = 0; i < ht.M; i++)
    {
        if (ht.table[i] == -1)
            cout << "NULL\t";
        else
            cout << ht.table[i] << "\t";
    }
}

void InsertHashTable(Hashtable &ht, int key)
{
    int nprob = 0;
    int index = HF(key, ht.M);
    while (ht.table[index] != -1 && nprob < ht.M)
    {
        nprob++;
        index = HF_QuadraticProbing(key, ht.M, nprob);
    }
    if (nprob >= ht.M)
        return;
    ht.table[index] = key;
    ht.n++;
}

void CreateHashTable(Hashtable &ht)
{
    int M;
    cin >> M;
    InitHashTable(ht, M);
    int key;
    cin >> key;
    while (key != -1)
    {
        InsertHashTable(ht, key);
        cin >> key;
    }
}

void Fun(Hashtable ht)
{
    if (ht.n == 0)
        return;
    cout << endl;
    cout << "Non-Collision: ";
    for (int i = 0; i < ht.M; i++)
    {
        int index = HF(ht.table[i], ht.M);
        if (index == i)
            cout << ht.table[i] << " ";
    }
}

int main()
{
    Hashtable H;
    CreateHashTable(H);
    Traverse(H);
    Fun(H);
    return 0;
}
