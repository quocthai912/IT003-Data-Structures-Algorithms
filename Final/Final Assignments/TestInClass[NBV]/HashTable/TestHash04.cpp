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

int H2(int key)
{
    return 7 - key % 7;
}

// Them khoa
void InsertHash(Hashtable &ht, int key)
{
    int i = 0;
    int index = HF(key, ht.M);
    while (ht.table[index] != -1 && i < ht.M)
    {
        i++;
        index = HF_DoubleHashing(key, ht.M, i, H2(key));
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
        InsertHash(ht, key);
        cin >> key;
    }
}

void Fun(Hashtable &ht, int x)
{
    int i = 0;
    int index = HF(x, ht.M);
    cout << endl
         << "H1(" << x << ")=" << index;
    if (ht.table[index] != -1)
    {
        cout << " (Collision)";
    }
    else
    {
        ht.table[index] = x;
        ht.n++;
        cout << endl
             << x << ": Add Successful in bucket " << index;
        return;
    }
    cout << endl;
    cout << "H2(" << x << ")=" << H2(x) << endl;
    while (ht.table[index] != -1 && i < ht.M)
    {
        if (i != 0)
        {
            cout << " (Collision)" << endl;
        }
        i++;
        if (i >= ht.M)
            break;
        index = HF_DoubleHashing(x, ht.M, i, H2(x));
        cout << "prob(" << x << "," << i << ")=" << index;
    }
    if (i >= ht.M)
    {
        cout << x << ": Add Failed";
        return;
    }
    ht.table[index] = x;
    ht.n++;
    cout << endl
         << x << ": Add Successful in bucket " << index;
}

int main()
{
    Hashtable H;
    CreateHashTable(H);
    int x;
    cin >> x;
    Traverse(H);
    Fun(H, x);
    return 0;
}
