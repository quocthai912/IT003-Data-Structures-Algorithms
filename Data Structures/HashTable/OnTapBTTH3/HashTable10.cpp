// No Template.
// Tìm Khóa Có Giá Trị Nhỏ Nhất Trong Mỗi Địa Chỉ Và In Kết Quả.
// Xử Lí Đụng Độ (Nối Kết Trực Tiếp).
// Độ Phức Tạp Thời Gian: O(M + K) với M Là Kích Thước Của Bảng Băm Và K Là Số Phần Tử Trong Bảng Băm.
// Độ Phức Tạp Bộ Nhớ: O(M + K) với M là Kích Thước Tạo Cho Bảng Băm Và K Bộ Nhớ Cho K NODE.
#include <iostream>
using namespace std;
struct NODE
{
    int value;
    NODE *pNext;
};
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
NODE *CreateNODE(int value)
{
    NODE *p = new NODE;
    p->value = value;
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
int FindMin(LIST l)
{
    int min = l.pHead->value;
    NODE *p = l.pHead;
    while (p)
    {
        if (p->value < min)
            min = p->value;
        p = p->pNext;
    }
    return min;
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
    ht.N++;
}
void CreateHashTable(HASHTABLE &ht)
{
    int M;
    cin >> M;
    CreateEmptyHashTable(ht, M);
    int key;
    cin >> key;
    while (key != -1)
    {
        InsertHashTable(ht, key);
        cin >> key;
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
            cout << "EMPTY";
        }
        else
        {
            while (p)
            {
                cout << p->value << " ";
                if (p->pNext != nullptr)
                    cout << "--> ";
                p = p->pNext;
            }
        }
        cout << endl;
    }
}
void PrintMin(HASHTABLE ht)
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
            int minKey = FindMin(ht.table[i]);
            cout << minKey << " ";
        }
        cout << endl;
    }
}
int main()
{
    HASHTABLE ht;
    CreateHashTable(ht);
    cout << "HASH TABLE: " << endl;
    PrintHashTable(ht);
    cout << "MIN CUA TUNG DIA CHI TRONG HASH TABLE: " << endl;
    PrintMin(ht);
    return 0;
}