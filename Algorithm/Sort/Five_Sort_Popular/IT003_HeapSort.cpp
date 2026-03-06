// Cấu trúc dữ liệu Heap: chính là 1 cây nhị phân hoàn chỉnh
// Cây nhị phân là 1 cây với mỗi nút cha chỉ có tối đa 2 nút con
// Cây nhị phân hoàn chỉnh là 1 cây được điền đầy đủ từ trái sang -> phải và không được để hở nút ở giữa (vẽ hình để trực quan hóa)
// Nút đầu tiên được gọi là Root (gốc), các nút ngoài cùng được gọi là Leaf (nút Lá), các nút còn lại được xem là nút trung gian (hay chỗ bắt đầu của 1 nhánh cây)
// Tư Duy 1: Tư duy 1 mảng như 1 cái cây nhị phân hoàn chỉnh
// Cấu trúc dữ liệu Max Heap: Phần tử nút cha luôn lớn hơn hoặc bằng 2 nút con
// => Tức phần tử ở gốc (root) sẽ là phần tử lớn nhất
// Cấu trúc dữ liệu Min Heap: Phần tử nút cha luôn nhỏ hơn hoặc bằng 2 nút con
// => Tức phần tử ở gốc (root) sẽ là phần tử nhỏ nhất
#include <bits/stdc++.h>
using namespace std;
void heapify(int a[], int n, int i)
{
    // Giả sử node tại vị trí i là node lớn nhất
    int largest = i;
    // Nút con bên trái;
    int left = 2 * i + 1;
    // Nút con bên phải;
    int right = 2 * i + 2;
    // Kiểm tra nếu nút con bên trái có tồn tại và giá trị tại nút đó lớn hơn giá trị tại nút ban đầu chúng ta giả sử
    if (left < n && a[left] > a[largest])
    {
        // Cập nhập chỉ số largest
        largest = left;
    }
    // Kiểm tra nếu nút con bên phải có tồn tại và giá trị tại nút đó lớn hơn giá trị tại nút ban đầu chúng ta giả sử
    if (right < n && a[right] > a[largest])
    {
        // Cập nhập chỉ số largest
        largest = right;
    }
    // Nếu chỉ số lớn nhất không giống như chúng ta đã giả sử
    if (largest != i)
    {
        // Swap để đảm bảo max Heap
        swap(a[i], a[largest]);
        // Tiếp tục gọi heapify tới nút con
        heapify(a, n, largest);
        // Thuật toán sẽ dừng nếu nút không còn nút con hoặc largest không thay đổi (Vị trí ta xét đã là nút lớn nhất và thỏa max Heap)
    }
}
// Hàm xây dựng maxHeap
void buildHeap(int a[], int n)
{
    // Ta xây dựng từ các nút không phải nút lá
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
}
// Tư duy 2: Lúc này mảng đã thỏa Max Heap, ta sẽ dùng tính chất của Data Structures này để sắp xếp
// => Heap Sort
void heapSort(int a[], int n)
{
    buildHeap(a, n);
    for (int i = n - 1; i > 0; i--)
    {
        // Lúc này root là thằng lớn nhất, ta sẽ swap nó về đúng vị trí cần đứng
        swap(a[i], a[0]);
        // lúc này ta sẽ Heapify lại cái cây nhưng không xét nút cuối nữa
        // Ta sẽ Heapify từ cái node đầu tiên, tức tái xây dựng maxHeap
        heapify(a, i, 0);
    }
}
int main()
{
    int a[] = {6, 3, 1, 7, 9};
    heapSort(a, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}