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

void InsertHashTable(Hashtable &ht, int key)
{
    int i = 0;
    int index = HF(key, ht.M);
    while (ht.table[index] != -1 && i < ht.M)
    {
        i++;
        index = HF_QuadraticProbing(key, ht.M, i);
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
    int key;
    cin >> key;
    while (key != -1)
    {
        InsertHashTable(ht, key);
        cin >> key;
    }
}

void Fun(Hashtable ht, int x)
{
    int i = 0;
    int index = HF(x, ht.M);
    cout << "H(" << x << ")=" << index;
    while (ht.table[index] != -1 && i < ht.M)
    {
        if (ht.table[index] == x)
        {
            cout << endl
                 << x << " found in bucket " << index;
            return;
        }
        cout << " (Collision)" << endl;
        i++;
        if (i >= ht.M)
            break;
        index = HF_QuadraticProbing(x, ht.M, i);
        cout << "prob(" << x << "," << i << ")=" << index;
    }
    if (ht.table[index] == -1)
        cout << " (Empty)" << endl;
    cout << x << " not found";
}

int main()
{
    Hashtable H;
    CreateHashTable(H);
    int x;
    cin >> x;
    Fun(H, x);
    return 0;
}
