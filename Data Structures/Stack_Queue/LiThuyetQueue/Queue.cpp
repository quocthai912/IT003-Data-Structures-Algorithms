// Sau khi đã học xong Stack. Chúng ta sẽ đến với cấu trúc dữ liệu tiếp theo.
// Đây cũng là cấu trúc dữ liệu thứ 3 chúng ta được học trong suốt khóa học IT003.
// Đó chính là Hàng đợi (QUEUE), cơ chế của hàng đợi là FIFO.
// Chúng ta sẽ cài đặt Queue bằng Linked List và học cách sử dụng thư viện Queue được xây dựng sẵn.
// Việc học xây dựng từ mảng (Array) là không cần thiết.
#include <iostream>
using namespace std;
struct NODE
{
    int value;
    NODE *pNext;
};
NODE *initNode(int value)
{
    NODE *p = new NODE;
    p->value = value;
    p->pNext = nullptr;
    return p;
}
struct Queue
{
    NODE *front;
    NODE *back;
};
// Khởi tạo Queue rỗng.
void createEmptyQueue(Queue &q)
{
    q.front = q.back = nullptr;
}
// Kiểm tra Queue rỗng.
bool isEmpty(const Queue &q)
{
    return q.front == nullptr;
}
// Hàm enQueue, thêm phần tử vào cuối hàng đợi.
void enQueue(Queue &q, NODE *p)
{
    if (isEmpty(q))
    {
        q.front = q.back = p;
        return;
    }
    q.back->pNext = p;
    q.back = p;
}
// Hàm deQueue, lấy phần tử ra khỏi hàng đợi.
bool deQueue(Queue &q)
{
    if (isEmpty(q))
        return false;
    NODE *p = q.front;
    q.front = q.front->pNext;
    delete p;
    if (q.front == nullptr)
        q.front = q.back = nullptr;
    return true;
}
// Hàm top, trả về giá trị phần tử ở đầu hàng đợi.
int top(const Queue &q)
{
    return q.front->value;
}
// Hàm back, trả về giá trị phần tử ở cuối hàng đợi.
int back(const Queue &q)
{
    return q.back->value;
}
int main()
{
    Queue q;
    createEmptyQueue(q);
    int choice;
    int value;
    while (true)
    {
        cout << "\n========== MENU QUEUE ==========" << endl;
        cout << "1. Enqueue (Them vao cuoi)" << endl;
        cout << "2. Dequeue (Lay ra o dau)" << endl;
        cout << "3. Front/Top (Xem phan tu dau)" << endl;
        cout << "4. Back (Xem phan tu cuoi)" << endl;
        cout << "5. Kiem tra Queue rong (isEmpty)" << endl;
        cout << "0. Thoat" << endl;
        cout << "================================" << endl;
        cout << "Moi ban chon chuc nang: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Nhap gia tri can them vao (enqueue): ";
            cin >> value;
            enQueue(q, initNode(value));
            cout << "Da them " << value << " vao cuoi Queue." << endl;
            break;
        case 2:
            if (isEmpty(q))
            {
                cout << "Hang doi rong, khong the lay ra (dequeue)!" << endl;
            }
            else
            {
                int frontValue = top(q);
                deQueue(q);
                cout << "Da lay phan tu " << frontValue << " ra khoi dau Queue." << endl;
            }
            break;
        case 3:
            if (isEmpty(q))
            {
                cout << "Hang doi rong." << endl;
            }
            else
            {
                cout << "Phan tu o dau Queue (front) la: " << top(q) << endl;
            }
            break;
        case 4:
            if (isEmpty(q))
            {
                cout << "Hang doi rong." << endl;
            }
            else
            {
                cout << "Phan tu o cuoi Queue (back) la: " << back(q) << endl;
            }
            break;
        case 5:
            if (isEmpty(q))
            {
                cout << "Empty Queue." << endl;
            }
            else
            {
                cout << "Queue dang chua cac phan tu." << endl;
            }
            break;

        case 0:
            cout << "Dang don dep hang doi va thoat chuong trinh..." << endl;
            while (!isEmpty(q))
            {
                deQueue(q);
            }
            return 0;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
        cout << "\nNhan Enter de tiep tuc...";
        cin.ignore();
        cin.get();
    }
    return 0;
}