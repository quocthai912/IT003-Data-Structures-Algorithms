// 1 Bài toán kinh điển
// Cho 1 dãy điểm => sắp xếp tăng dần theo từng trục (Để tìm median)
// Hãy tìm 1 điểm A sao cho tổng khoảng cách từ A tới các điểm còn lại là cực tiểu
#include <bits/stdc++.h>
using namespace std;
struct DiemHaiChieu
{
    long long x, y;
};
long long khoangCachManhattan(DiemHaiChieu A, DiemHaiChieu B)
{
    return llabs(A.x - B.x) + llabs(A.y - B.y);
}
int main()
{
    long long size;
    cin >> size;
    vector<DiemHaiChieu> mangDiemHaiChieu(size);
    for (long i = 0; i < size; i++)
        cin >> mangDiemHaiChieu[i].x >> mangDiemHaiChieu[i].y;
    // Do khoảng cách Manhattan được tính bằng tổng của từng trục
    // Cho nên ta phải tìm median và tính khoảng cách cực tiểu của từng trục
    vector<long long> TrucX(size);
    vector<long long> TrucY(size);
    for (long i = 0; i < size; i++)
    {
        TrucX[i] = mangDiemHaiChieu[i].x;
        TrucY[i] = mangDiemHaiChieu[i].y;
    }
    sort(TrucX.begin(), TrucX.end());
    sort(TrucY.begin(), TrucY.end());
    DiemHaiChieu A = {TrucX[(size - 1) / 2], TrucY[(size - 1) / 2]};
    long long sum = 0;
    for (long i = 0; i < size; i++)
    {
        sum += khoangCachManhattan(A, mangDiemHaiChieu[i]);
    }
    cout << sum;
    return 0;
}