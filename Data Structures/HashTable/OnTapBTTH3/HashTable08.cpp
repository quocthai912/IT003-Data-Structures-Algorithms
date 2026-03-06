// No Template.
// Xóa Khóa Key Trong Bảng Băm Có Giá Trị Bằng X.
// Xử Lí Đụng Độ (Nối Kết Trực Tiếp).
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
    ht.M = M;
    ht.N = 0;
}
void InsertHashTable(HASHTABLE &ht, int key)
{
    int index = HF(key, ht.M);
    AddTail(ht.table[index], CreateNODE(key));
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
        ht.N++;
        cin >> temp;
    }
}
void PrintHashTable(HASHTABLE ht)
{
    for (int i = 0; i < ht.M; i++)
    {
        cout << i << "| ";
        NODE *p = ht.table[i].pHead;
        if (p == nullptr)
        {
            cout << "NULL";
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
bool DeleteKey(HASHTABLE &ht, int key)
{
    int index = HF(key, ht.M);
    NODE *p = ht.table[index].pHead;
    if (p == nullptr)
        return false;
    if (p->key == key)
    {
        ht.table[index].pHead = ht.table[index].pHead->pNext;
        delete p;
        return true;
    }
    while (p->pNext)
    {
        if (p->pNext->key == key)
        {
            NODE *q = p->pNext;
            p->pNext = q->pNext;
            delete q;
            return true;
        }
        p = p->pNext;
    }
    return false;
}
int main()
{
    HASHTABLE ht;
    CreateHashTable(ht);
    if (ht.N == 0)
    {
        cout << "Empty";
        return 0;
    }
    int khoaCanXoa;
    cin >> khoaCanXoa;
    cout << "Hash Table Truoc Khi Xoa: " << endl;
    PrintHashTable(ht);
    bool xoaKey = DeleteKey(ht, khoaCanXoa);
    cout << "Hash Table Sau Khi Xoa: " << endl;
    PrintHashTable(ht);
    if (xoaKey)
    {
        cout << khoaCanXoa << ": Delete Succesful";
    }
    else
        cout << khoaCanXoa << ": Failed";
    return 0;
}
