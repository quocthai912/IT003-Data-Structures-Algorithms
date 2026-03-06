// Sau khi đã xử lí thuần thục với cấu trúc dữ liệu đầu tiên: Linked List.
// Tiếp đến sẽ là Stack (Ngăn Xếp).
// Stack thực hiện theo cơ chế vào sau ra trước (LIFO) tức khi bạn in Stack, nó sẽ như 1 ngăn xếp được xếp nằm ngang.
// Các phần tử được thêm vào Stack sẽ được thêm vào đầu (AddHead).
// Nên khi duyệt Stack, bạn sẽ cảm giác giống như in ngược so với các phần tử được thêm vào.
// Stack là 1 cấu trúc rất quan trọng được sử dụng trong hệ điều hành, và các thuật toán quan trọng trong môn phân tích và thiết kế thuật toán (quay lui, truy vết, vét cạn).
// Stack có thể được cài đặt bằng hai cách (Linked List và Mảng 1 Chiều).
// Trong bài này, chúng ta sẽ cài đặt Stack bằng Linked List trước vì được ứng dụng nhiều hơn.
// 01. Khởi tạo cấu trúc NODE.
#include <bits/stdc++.h>
using namespace std;
struct NODE
{
    int value;
    NODE *pNext;
};
NODE *initNODE(int value)
{
    NODE *p = new NODE;
    p->value = value;
    p->pNext = nullptr;
    return p;
}
// 02. Khởi tạo cấu trúc STACK.
// STACK cũng được quản lý bằng hai con trỏ đầu và cuối giống Linked List.
struct STACK
{
    NODE *pHead;
    NODE *pTail;
};
void CreateEmptyStack(STACK &st)
{
    st.pHead = nullptr;
    st.pTail = nullptr;
}
// 03. Hàm hủy Stack.
void DeleteStack(STACK &st)
{
    NODE *p = st.pHead;
    while (p)
    {
        NODE *delNode = p;
        p = p->pNext;
        delete delNode;
    }
    st.pHead = st.pTail = nullptr;
}
// 04. Kiểm tra Stack có rỗng không.
bool isEmpty(const STACK &st)
{
    if (st.pHead == nullptr)
        return true;
    return false;
}
// 05. Push phần tử vào Stack.
void Push(STACK &st, NODE *addNode)
{
    if (isEmpty(st))
    {
        st.pHead = st.pTail = addNode;
    }
    else
    {
        addNode->pNext = st.pHead;
        st.pHead = addNode;
    }
}
// 06. Pop phần tử ra khỏi Stack và lấy giá trị của phần tử đó.
bool Pop(STACK &st, int &value)
{
    if (isEmpty(st))
        return false;
    value = st.pHead->value;
    NODE *delNode = st.pHead;
    st.pHead = st.pHead->pNext;
    if (st.pHead == nullptr)
    {
        st.pTail = nullptr;
    }
    delete delNode;
    return true;
}
// 07. Top trả về phần tử nằm ở đỉnh Stack.
bool Top(const STACK &st, int &value)
{
    if (isEmpty(st))
        return false;
    value = st.pHead->value;
    return true;
}
// 08. Duyệt và in Stack.
void PrintStack(const STACK &st)
{
    if (isEmpty(st))
    {
        cout << "Stack rong.";
    }
    else
    {
        NODE *p = st.pHead;
        while (p)
        {
            cout << p->value << " ";
            p = p->pNext;
        }
    }
}
// Các ứng dụng của Stack.
// 09. Đảo mảng.
void ReverseArray(vector<int> &Array)
{
    STACK st;
    CreateEmptyStack(st);
    for (int i = 0; i < Array.size(); i++)
    {
        Push(st, initNODE(Array[i]));
    }
    for (int i = 0; i < Array.size(); i++)
    {
        Pop(st, Array[i]);
    }
}
// 10. Chuyển đổi hệ thập phân sang hệ nhị phân.
string DecimalToBinary(int decimal)
{
    STACK st;
    CreateEmptyStack(st);
    while (decimal / 2 != 0)
    {
        Push(st, initNODE(decimal % 2));
        decimal /= 2;
    }
    Push(st, initNODE(decimal % 2));
    string result = "";
    while (!isEmpty(st))
    {
        int value;
        Pop(st, value);
        result += to_string(value);
    }
    return result;
}
int main()
{
    STACK st;
    CreateEmptyStack(st);
    int choice, value;

    while (true)
    {
        cout << "\n========== MENU STACK ==========" << endl;
        cout << "1. Push (Them phan tu vao Stack)" << endl;
        cout << "2. Pop (Lay phan tu ra khoi Stack)" << endl;
        cout << "3. Top (Xem phan tu o dinh Stack)" << endl;
        cout << "4. Print (In ra toan bo Stack)" << endl;
        cout << "5. Kiem tra Stack rong (isEmpty)" << endl;
        cout << "6. Ung dung STACK (Dao Mang)" << endl;
        cout << "7. Ung dung STACK (Chuyen Doi He Co So)" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "================================" << endl;
        cout << "Moi ban chon chuc nang: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Nhap cac gia tri can Push (ket thuc khi nhap -1): ";
            cin >> value;
            while (value != -1)
            {
                Push(st, initNODE(value));
                cout << "Da Push " << value << " vao Stack." << endl;
                cin >> value;
            }
            break;

        case 2:
            if (Pop(st, value))
            {
                cout << "Gia tri vua Pop duoc: " << value << endl;
            }
            else
            {
                cout << "Stack rong, khong the Pop!" << endl;
            }
            break;

        case 3:
            if (Top(st, value))
            {
                cout << "Gia tri o dinh Stack (Top): " << value << endl;
            }
            else
            {
                cout << "Stack rong, khong co Top!" << endl;
            }
            break;

        case 4:
            cout << "Noi dung Stack hien tai (Tu Top -> Bottom): ";
            PrintStack(st);
            cout << endl;
            break;

        case 5:
            if (isEmpty(st))
            {
                cout << "Stack dang RONG." << endl;
            }
            else
            {
                cout << "Stack KHONG rong." << endl;
            }
            break;
        case 6:
        {
            vector<int> array;
            cout << "Nhap cac phan tu cua mang, ket thuc khi nhap -1: ";
            int value;
            cin >> value;
            while (value != -1)
            {
                array.push_back(value);
                cin >> value;
            }
            cout << "Mang ban dau: ";
            for (int i = 0; i < array.size(); i++)
                cout << array[i] << " ";
            cout << endl;
            ReverseArray(array);
            cout << "Mang sau khi dao nguoc bang STACK: ";
            for (int i = 0; i < array.size(); i++)
                cout << array[i] << " ";
            cout << endl;
            break;
        }
        case 7:
        {
            cout << "Xin moi nhap so thap phan muon chuyen: ";
            int decimal;
            cin >> decimal;
            string ketQua = DecimalToBinary(decimal);
            cout << "Ket qua sau khi chuyen sang so nhi phan la: " << ketQua << endl;
            break;
        }
        case 0:
            cout << "Dang huy Stack va thoat chuong trinh..." << endl;
            DeleteStack(st);
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
