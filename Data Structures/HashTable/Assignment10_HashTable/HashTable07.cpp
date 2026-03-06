/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

#define MAXTABLESIZE 10000

struct NODE
{
    int key;
};
typedef NODE HASHTABLE[MAXTABLESIZE];

int TableSize;
int M;

int HF(int key)
{
    return key % M;
}
int HF_LinearProbing(int key, int i)
{
    return (HF(key) + i) % TableSize;
}
#define EMPTY -1
#define DELETE -2
void CreateEmptyHashTable(HASHTABLE &H, int CurrentSize)
{
    for (int i = 0; i < CurrentSize; i++)
    {
        H[i].key = EMPTY;
    }
}
void Insert(HASHTABLE &H, int CurrentSize, int key)
{
    int index = HF(key);
    int i = 0;
    while (H[index].key != EMPTY && i < CurrentSize)
    {
        // Khóa trùng nhau
        if (H[index].key == key)
            return;
        i++;
        index = HF_LinearProbing(key, i);
    }
    if (i >= CurrentSize)
        return;
    H[index].key = key;
}
void CreateHashTable(HASHTABLE &H, int &CurrentSize)
{
    cin >> M;
    cin >> CurrentSize;
    TableSize = CurrentSize;
    CreateEmptyHashTable(H, CurrentSize);
    int x;
    cin >> x;
    while (x != -1)
    {
        Insert(H, CurrentSize, x);
        cin >> x;
    }
}
void Traverse(HASHTABLE &H, int CurrentSize)
{
    for (int i = 0; i < CurrentSize; i++)
    {
        cout << i << " --> " << H[i].key << endl;
    }
}
int main()
{
    HASHTABLE H;
    int CurrentSize;

    CreateHashTable(H, CurrentSize);
    Traverse(H, CurrentSize);

    return 0;
}
