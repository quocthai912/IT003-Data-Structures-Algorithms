#include <bits/stdc++.h>
using namespace std;
struct NODE
{
    int key;
};
#define M 100
#define NULLKEY -1
#define DELETEKEY -2
typedef NODE HASHTABLE[M];
int N;
// 1. Hàm băm
int HF(int key)
{
    return (key % M);
}
// 2. Khởi tạo bảng băm rỗng
void InitHashTable(HASHTABLE &BangBam)
{
    for (int i = 0; i < M; i++)
    {
        BangBam[i].key = NULLKEY;
    }
    N = 0;
}
// 3. Kiểm tra bảng băm rỗng
bool IsEmpty(const HASHTABLE &BangBam)
{
    return (N == 0);
}
// 4. Kiểm tra bảng băm đầy
bool IsFull(const HASHTABLE &BangBam)
{
    return (N == M - 1);
}
// 5. Hàm tìm kiếm
int Search(const HASHTABLE &BangBam, int key)
{
    int i = 0;
    int index = HF(key); // Lần i = 0
    while (BangBam[index].key != NULLKEY && i < M)
    {
        if (BangBam[index].key == key)
            return index;
        i++;
        index = (HF(key) + i) % M;
    }
    return -1;
}
// 6. Hàm xóa khóa trong Bảng Băm
void Delete(HASHTABLE &BangBam, int key)
{
    int index = Search(BangBam, key);
    if (index == -1)
    {
        cout << "Xoa that bai, khong tim thay khoa trong bang bam" << endl;
        return;
    }
    BangBam[index].key = DELETEKEY;
    N--;
}
// 7. Hàm thêm khóa trong bảng băm
void Insert(HASHTABLE &BangBam, int key)
{
    if (IsFull(BangBam))
    {
        cout << "Bang bam da day" << endl;
        return;
    }
    if (Search(BangBam, key) != -1)
    {
        cout << "Gia tri khoa da co trong bang bam" << endl;
        return;
    }
    int index = HF(key);
    int i = 0;
    while (BangBam[index].key != NULLKEY && BangBam[index].key != DELETEKEY && i < M)
    {
        i++;
        index = (HF(key) + i) % M;
    }
    if (i < M)
    {
        BangBam[index].key = key;
        N++;
    }
    else
        cout << "Them that bai" << endl;
}