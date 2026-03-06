// Sau khi đã cài đặt Stack trên Linked List, bây giờ chúng ta sẽ cài đặt trên Mảng, thậm chí còn dễ dàng hơn đôi chút.
// Quản lý Stack trên mảng dễ hơn rất nhiều vì không cần làm việc với con trỏ, tuy nhiên độ linh động cũng bị giảm đi rất nhiều.
// Lí do là vì nếu triển khai Stack trên mảng, nó sẽ là 1 cấu trúc dữ liệu tĩnh, khả năng tự động mở rộng vùng nhớ sẽ biến mất.
#include <bits/stdc++.h>
using namespace std;
// Giả sử chúng ta có 1 ngăn xếp quản lý tối đa 100 phần tử.
#define MAX 100
// 01. Khởi tạo cấu trúc Stack.
struct STACK
{
    int a[100];
    int size;
};
// 02. Khởi tạo Stack rỗng.
void CreateEmptyStack(STACK &st)
{
    st.size = -1;
}
// 03. Kiểm tra Stack rỗng.
bool isEmpty(const STACK &st)
{
    if (st.size == -1)
        return true;
    return false;
}
// 04. Kiểm tra Stack đầy.
bool isFull(const STACK &st)
{
    if (st.size >= MAX - 1)
        return true;
    return false;
}
// 05. Push phần tử vào Stack.
bool Push(STACK &st, int value)
{
    if (!isFull(st))
    {
        st.a[++st.size] = value;
        return true;
    }
    return false;
}
// 06. Pop phần tử ra khỏi Stack.
bool Pop(STACK &st, int &value)
{
    if (!isEmpty(st))
    {
        value = st.a[st.size--];
        return true;
    }
    return false;
}
// 07. Lấy phần tử ở đỉnh Stack.
bool Top(const STACK &st, int &value)
{
    if (!isEmpty(st))
    {
        value = st.a[st.size];
        return true;
    }
    return false;
}
// 08. Duyệt và in Stack.
void PrintStack(const STACK &st)
{
    for (int i = st.size; i >= 0; i--)
    {
        cout << st.a[i] << " ";
    }
}
// 09. Đảo ngược mảng bằng Stack (ARRAY).
bool ReverseArray(vector<int> &array)
{
    if (array.size() > MAX)
        return false;
    STACK st;
    CreateEmptyStack(st);
    for (int i = 0; i < array.size(); i++)
    {
        Push(st, array[i]);
    }
    for (int i = 0; i < array.size(); i++)
    {
        Pop(st, array[i]);
    }
    return true;
}
// 10. Đổi 1 số thập phân sang số nhị phân bằng Stack (ARRAY).
string DecimalToBinary(int decimal)
{
    STACK st;
    CreateEmptyStack(st);
    while (decimal / 2 != 0)
    {
        Push(st, decimal % 2);
        decimal /= 2;
    }
    Push(st, decimal % 2);
    string result = "";
    while (!isEmpty(st))
    {
        int value;
        Pop(st, value);
        result += to_string(value);
    }
    return result;
}
// Tổng kết:
// Hoàn thành các thuật toán sắp xếp và tìm kiếm.
// Hoàn thành cấu trúc dữ liệu Linked List và Stack.
// Cấu trúc dữ liệu tiếp theo: Queue (Hàng đợi).
