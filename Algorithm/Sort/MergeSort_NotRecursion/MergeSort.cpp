#include <bits/stdc++.h>
using namespace std;
#define MAX 100
// Khai báo hai mảng toàn cục dùng để chia và trộn
int B[MAX], C[MAX];
void merge(int A[], int nB, int nC, int k)
{
    // Khai báo các con trỏ tới các mảng và chỉ số phần tử sẽ được đưa vào
    int pA, pB, pC, iB, iC;
    pA = pB = pC = iB = iC = 0;
    // Số phần tử sẽ xử lí ở mảng B
    int kB = min(k, nB);
    // Số phần tử sẽ xử lí ở mảng C
    int kC = min(k, nC);
    // Tiến hành trộn cho tới khi nào 1 trong 2 không còn phần tử nào
    while (nB > 0 && nC > 0)
    {
        // Tiến hành so sánh và đưa phần tử
        if (B[pB + iB] <= C[pC + iC])
        {
            A[pA++] = B[pB + iB];
            iB++;
            // Nếu số phần tử bên mảng B đã hết
            if (iB == kB)
            {
                for (; iC < kC; iC++)
                {
                    A[pA++] = C[pC + iC];
                }
                // Sau khi đã xử lí xong
                // Tăng con trỏ tới vị trí xử lí tiếp theo
                pB += iB;
                pC += iC;
                // Reset chỉ số về 0 để phục vụ cho lần xử lí tiếp theo
                iB = iC = 0;
                // Trừ đi số phần tử đã xử lí
                nB -= kB;
                nC -= kC;
                // Tính toán số phần tử cần xử lí cho lượt kế tiếp
                kB = min(k, nB);
                kC = min(k, nC);
            }
        }
        else
        {
            A[pA++] = C[pC + iC];
            iC++;
            if (iC == kC)
            {
                for (; iB < kB; iB++)
                {
                    A[pA++] = B[pB + iB];
                }
                // Sau khi đã xử lí xong
                // Tăng con trỏ tới vị trí xử lí tiếp theo
                pB += iB;
                pC += iC;
                // Reset chỉ số về 0 để phục vụ cho lần xử lí tiếp theo
                iB = iC = 0;
                // Trừ đi số phần tử đã xử lí
                nB -= kB;
                nC -= kC;
                // Tính toán số phần tử cần xử lí cho lượt kế tiếp
                kB = min(k, nB);
                kC = min(k, nC);
            }
        }
    }
}
void mergeSort(int A[], int size)
{
    // 1 con trỏ tới mảng A, B, C và 1 biến i để sử dụng vòng lặp
    // Biến k đại diện có khối kích thước mỗi lần trộn, tăng theo lũy thừa 2
    int pA, pB, pC, i, k = 1;
    // Thực hiện chia và trộn cho tới khi khối k lớn hơn hoặc bằng kích thước mảng
    while (k < size)
    {
        pA = pB = pC = 0;
        while (pA < size)
        {
            // Bốc k phần tử của A vào B
            for (i = 0; pA < size && i < k; i++)
                B[pB++] = A[pA++];
            // Bốc k phần tử của A vào C
            for (i = 0; pA < size && i < k; i++)
                C[pC++] = A[pA++];
        }
        // Thực hiện trộn
        merge(A, pB, pC, k);
        // Tăng khối K cho lần trộn tiếp theo
        k *= 2;
    }
}
int main()
{
    int A[MAX];
    for (int i = 0; i < 5; i++)
        cin >> A[i];
    mergeSort(A, 5);
    for (int i = 0; i < 5; i++)
        cout << A[i] << " ";
    return 0;
}
