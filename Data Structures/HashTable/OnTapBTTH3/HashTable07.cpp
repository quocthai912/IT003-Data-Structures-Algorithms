// Tìm các địa chỉ (bucket) trong bảng băm mà tổng giá trị các khóa tại địa chỉ đó là cao nhất.
#include <iostream>
using namespace std;
struct NODE
{
    int key;
    NODE *pNext;
};
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
NODE *CreateNODE(int key)
{
    NODE *p = new NODE;
    p->key = key;
    p->pNext = nullptr;
    return p;
}
void AddTail(LIST &l, NODE *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
        return;
    }
    l.pTail->pNext = p;
    l.pTail = p;
}
struct HASHTABLE
{
    int M;
    int N;
    LIST *table;
};
int HF(int key, int M)
{
    return key % M;
}
void CreateEmptyHashTable(HASHTABLE &ht, int M)
{
    ht.table = new LIST[M];
    for (int i = 0; i < M; i++)
    {
        ht.table[i].pHead = ht.table[i].pTail = nullptr;
    }
    ht.N = 0;
    ht.M = M;
}
void InsertHashTable(HASHTABLE &ht, int key)
{
    int index = HF(key, ht.M);
    AddTail(ht.table[index], CreateNODE(key));
    ht.N++;
}
void CreateHashTable(HASHTABLE &ht)
{
    int M;
    cin >> M;
    CreateEmptyHashTable(ht, M);
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        InsertHashTable(ht, temp);
        cin >> temp;
    }
}
int sumList(LIST l)
{
    int sum = 0;
    NODE *p = l.pHead;
    while (p)
    {
        sum += p->key;
        p = p->pNext;
    }
    return sum;
}
void PrintHashTable(HASHTABLE ht)
{
    for (int i = 0; i < ht.M; i++)
    {
        cout << i << "| ";
        NODE *p = ht.table[i].pHead;
        if (p == nullptr)
        {
            cout << "EMPTY";
        }
        else
        {
            while (p)
            {
                cout << p->key << " ";
                if (p->pNext != nullptr)
                    cout << "--> ";
                p = p->pNext;
            }
        }
        cout << endl;
    }
}
void PrintIndexMaxSum(HASHTABLE ht)
{
    int maxSum = 0;
    for (int i = 0; i < ht.M; i++)
    {
        NODE *p = ht.table[i].pHead;
        if (p == nullptr)
        {
            continue;
        }
        else
        {
            int sum = sumList(ht.table[i]);
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    for (int i = 0; i < ht.M; i++)
    {
        NODE *p = ht.table[i].pHead;
        if (p == nullptr)
        {
            continue;
        }
        else
        {
            int sum = sumList(ht.table[i]);
            if (sum == maxSum)
                cout << i << " ";
        }
    }
    cout << endl
         << "MAX = " << maxSum;
}
int main()
{
    HASHTABLE ht;
    CreateHashTable(ht);
    PrintHashTable(ht);
    PrintIndexMaxSum(ht);
    return 0;
}
