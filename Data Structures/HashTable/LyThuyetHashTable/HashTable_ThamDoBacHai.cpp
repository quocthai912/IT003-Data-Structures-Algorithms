#include <bits/stdc++.h>
using namespace std;
struct NODE
{
    int key;
};
#define M 101
#define NULLKEY -1
#define DELETEKEY -2
typedef NODE HASHTABLE[M];
int N;
// 1. Hàm băm
int HF(int key)
{
    return (key % M);
}
// 2. Kiểm tra bảng băm rỗng
bool isEmpty(const HASHTABLE &BangBam)
{
    return (N == 0);
}
// 3. Kiểm tra bảng băm đầy
bool isFull(const HASHTABLE &BangBam)
{
    return (N == M - 1);
}
// 4. Khởi tạo bảng băm rỗng
void InitHashTable(HASHTABLE &BangBam)
{
    for (int i = 0; i < M; i++)
    {
        BangBam[i].key = NULLKEY;
    }
    N = 0;
}
// 5. Hàm tìm kiếm trong bảng băm thăm dò bậc 2
int Search(const HASHTABLE &BangBam, int key)
{
    int index = HF(key);
    int i = 0;
    while (BangBam[index].key != NULLKEY && i < M)
    {
        if (BangBam[index].key == key)
            return index;
        i++;
        // Băm lại vị trí mới - thăm dò bậc 2
        index = (HF(key) + i * i) % M;
    }
    return -1;
}
// 6. Hàm xóa trong bảng băm
void Delete(HASHTABLE &BangBam, int key)
{
    int index = Search(BangBam, key);
    if (index == -1)
    {
        cout << "Xoa that bai do khoa khong tim thay trong Bang Bam" << endl;
        return;
    }
    BangBam[index].key = DELETEKEY;
    N--;
}
// 7. Hàm thêm trong bảng băm
void Insert(HASHTABLE &BangBam, int key)
{
    if (isFull(BangBam))
    {
        cout << "Them that bai do bang bam day" << endl;
        return;
    }
    if (Search(BangBam, key) != -1)
    {
        cout << "Them that bai do tim thay khoa trong bang bam" << endl;
        return;
    }
    int i = 0;
    int index = HF(key);
    while (BangBam[index].key != NULLKEY && BangBam[index].key != DELETEKEY && i < M)
    {
        i++;
        index = (HF(key) + i * i) % M;
    }
    if (i < M) // Tìm thấy vị trí hợp lệ
    {
        BangBam[index].key = key;
        N++;
    }
    else
    {
        cout << "Them that bai do khong tim duoc vi tri them" << endl;
    }
}