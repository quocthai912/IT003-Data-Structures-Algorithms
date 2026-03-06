// Việc sử dụng thư viện Stack và Queue là rất quan trọng.
// Khi đi thi, chúng ta được yêu cầu sử dụng thư viện để giải quyết bài toán.
#include <iostream>
#include <stack>
#include <queue>
// Cách gọi 2 thư viện.
using namespace std;
int main()
{
    // Khởi tạo Stack.
    stack<int> st;
    // Khởi tạo Queue.
    queue<int> q;
    // Push phần tử vào Stack và Queue.
    st.push(1);
    q.push(2);
    // Xóa phần tử khỏi Stack và Queue.
    st.pop();
    q.pop();
    // Kiểm tra Stack và Queue có rỗng không.
    if (st.empty())
        cout << "Ngan xep dang rong" << endl;
    if (q.empty())
        cout << "Hang doi dang rong" << endl;
    // Push và trả về phần tử ở đầu Stack.
    st.push(1);
    st.push(2);
    cout << "Phan tu o dau Stack la: " << st.top() << endl;
    // Push và trả về các phần tử ở đầu và cuối hàng đợi.
    q.push(3);
    q.push(4);
    cout << "Phan tu o dau Queue la: " << q.front() << endl;
    cout << "Phan tu o cuoi Queue la: " << q.back() << endl;
    // Xong, đây là tất cả các thao tác cơ bản cần phải nắm vững để giải quyết các bài toán liên quan tới Stack và Queue.
    // Cấu trúc dữ liệu tiếp theo: Tree, Binary Tree, Binary Search Tree.
    return 0;
}