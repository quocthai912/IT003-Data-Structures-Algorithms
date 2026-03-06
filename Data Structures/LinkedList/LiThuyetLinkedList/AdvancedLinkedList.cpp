// Một số bài tập về Linked List
#include <iostream>
using namespace std;
// Bước 1: Khởi tạo cấu trúc nút
struct Node
{
    int data;
    Node *pNext;
};
// Bước 2: Khởi tạo một nút từ giá trị cho sẵn
Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pNext = nullptr;
    return p;
}
// Bước 3: Khởi tạo cấu trúc dữ liệu danh sách liên kết đơn (Singly Linked List)
struct List
{
    Node *pHead;
    Node *pTail;
};
// Bước 4: Khởi tạo danh sách liên kết đơn (Singly Linked List)
void initList(List &l)
{
    l.pHead = nullptr;
    l.pTail = nullptr;
}
// Hàm giải phóng danh sách liên kết đơn (Singly Linked List)
void deleteList(List &l)
{
    Node *p = l.pHead;
    while (p != nullptr)
    {
        Node *temp = p;
        p = p->pNext;
        delete temp;
    }
    l.pHead = nullptr;
    l.pTail = nullptr;
}
// Hàm in danh sách liên kết đơn (Singly Linked List)
void printList(const List &l)
{
    if (l.pHead == nullptr)
        cout << "Danh sach lien ket rong" << endl;
    else
    {
        Node *p = l.pHead;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->pNext;
        }
        cout << endl;
    }
}
// Hàm thêm nút đầu
void addHead(List &l, Node *p)
{
    // Danh sách rỗng
    if (l.pHead == nullptr)
    {
        l.pHead = p;
        l.pTail = p;
    }
    // Danh sách không rỗng
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
// Hàm thêm nút cuối
void addTail(List &l, Node *p)
{
    // Danh sách rỗng
    if (l.pHead == nullptr)
    {
        l.pHead = p;
        l.pTail = p;
    }
    // Danh sách không rỗng
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
// Hàm xóa nút đầu
bool popHead(List &l)
{
    // Danh sách rỗng
    if (l.pHead == nullptr)
        return false;
    Node *p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;
    // Sau khi xóa xong, danh sách rỗng (Trường hợp 1 nút)
    if (l.pHead == nullptr)
        l.pTail = nullptr;
    return true;
}
// Hàm xóa nút cuối
bool popTail(List &l)
{
    // Danh sách rỗng
    if (l.pHead == nullptr)
        return false;
    // Danh sách chỉ có 1 nút
    if (l.pHead == l.pTail)
    {
        l.pHead = nullptr;
        l.pTail = nullptr;
        return true;
    }
    Node *p = l.pHead;
    while (p->pNext != l.pTail)
    {
        p = p->pNext;
    }
    delete l.pTail;
    p->pNext = nullptr; // Tránh trỏ vào vùng nhớ rác
    l.pTail = p;        // Gán lại nút cuối
    return true;
}
// Hàm tính chiều dài của danh sách liên kết đơn (Singly Linked List)
int countList(const List &l)
{
    // Danh sách rỗng
    if (l.pHead == nullptr)
        return 0;
    // Danh sách chỉ có 1 nút
    if (l.pHead == l.pTail)
        return 1;
    // Trường hợp còn lại
    Node *p = l.pHead;
    int count = 0;
    while (p != nullptr)
    {
        count++;
        p = p->pNext;
    }
    return count;
}
// Hàm trả về node thứ N
Node *returnNodeThuN(const List &l, int pos)
{
    // Danh sách rỗng
    if (l.pHead == nullptr)
        return nullptr;
    int length = countList(l);
    // Sai vị trí nút
    if (pos == 0 || pos > length)
        return nullptr;
    // Trả về nút đầu tiên
    if (pos == 1)
        return l.pHead;
    // Trả về nút cuối cùng
    if (pos == length)
        return l.pTail;
    // Các trường hợp còn lại
    pos--;
    int count = 0;
    Node *p = l.pHead;
    while (p != nullptr)
    {
        if (count == pos)
            return p;
        count++;
        p = p->pNext;
    }
    return nullptr;
}
// Hàm xóa nút thứ N
bool popNodeThuN(List &l, int pos)
{
    // Danh sách rỗng
    if (l.pHead == nullptr)
        return false;
    int length = countList(l);
    // Trường hợp sai vị trí nút
    if (pos == 0 || pos > length)
        return false;
    // Trường hợp xóa nút đầu
    if (pos == 1)
    {
        popHead(l);
        return true;
    }
    // Trường hợp xóa nút cuối
    if (pos == length)
    {
        popTail(l);
        return true;
    }
    // Các trường hợp còn lại
    Node *prev = returnNodeThuN(l, pos - 1);
    Node *deleteNode = prev->pNext;
    prev->pNext = deleteNode->pNext;
    delete deleteNode;
    return true;
}
// Hàm thêm nút thứ N
bool addNodeThuN(List &l, int pos, int val)
{
    // Danh sách rỗng
    if (l.pHead == nullptr)
        return false;
    int length = countList(l);
    // Sai vị trí
    if (pos == 0 || pos > length + 1)
        return false;
    // Thêm nút thứ nhất
    if (pos == 1)
    {
        addHead(l, initNode(val));
        return true;
    }
    // Thêm nút cuối cùng
    if (pos == length)
    {
        addTail(l, initNode(val));
        return true;
    }
    // Các trường hợp còn lại
    Node *prev = returnNodeThuN(l, pos - 1);
    Node *addNode = initNode(val);
    addNode->pNext = prev->pNext;
    prev->pNext = addNode;
    return true;
}
// Hàm đảo ngược danh sách liên kết
bool reverseList(List &l)
{
    // Danh sách rỗng
    if (l.pHead == nullptr)
        return false;
    // Danh sách chỉ có 1 nút
    if (l.pHead == l.pTail)
        return true;
    Node *prev = nullptr;
    Node *next = nullptr;
    Node *current = l.pHead;
    while (current != nullptr)
    {
        next = current->pNext;
        current->pNext = prev;
        prev = current;
        current = next;
    }
    l.pTail = l.pHead;
    l.pHead = prev;
    return true;
}
// Hàm tìm node ở giữa danh sách
Node *middleNode(const List &l)
{
    // Danh sách rỗng
    if (l.pHead == nullptr)
        return nullptr;
    // Danh sách chỉ có 1 nút
    if (l.pHead == l.pTail)
        return l.pHead;
    // Các trường hợp còn lại
    int length = countList(l);
    // Tổng số nút là lẻ
    if (length % 2 != 0)
    {
        return returnNodeThuN(l, (length / 2) + 1);
    }
    // Tổng số nút là chẵn
    else
    {
        // Lấy biên phải
        // return returnNodeThuN(l, (length / 2) + 1);
        // Lấy biên trái
        return returnNodeThuN(l, length / 2);
    }
}
int main()
{
    List linkedList;
    initList(linkedList);
    int n;
    cout << "Nhap so nut cua danh sach lien ket: ";
    cin >> n;
    int *p = new int[n];
    cout << "Nhap gia tri cua cac nut: ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        addTail(linkedList, initNode(p[i]));
    }
    cout << "Danh sach lien ket ban dau: ";
    printList(linkedList);
    Node *nutGiua = middleNode(linkedList);
    cout << "Nut o giua co gia tri la: " << nutGiua->data << endl;
    if (reverseList(linkedList))
    {
        cout << "Danh sach sau khi dao nguoc: " << endl;
        printList(linkedList);
    }
    else
    {
        cout << "Khong the dao nguoc do danh sach rong" << endl;
    }
    int pos;
    cout << "Moi nhap nut can xoa (1-" << n << "): ";
    cin >> pos;
    if (popNodeThuN(linkedList, pos))
    {
        cout << "Da xoa thanh cong, danh sach sau khi xoa: " << endl;
        printList(linkedList);
    }
    else
    {
        cout << "Xoa that bai do danh sach rong hoac sai vi tri" << endl;
    }
    cout << "Moi nhap nut can them (1-" << n << "): ";
    cin >> pos;
    int val;
    cout << "Moi nhap gia tri nut can them: ";
    cin >> val;
    if (addNodeThuN(linkedList, pos, val))
    {
        cout << "Da them thanh cong, danh sach sau khi them: " << endl;
        printList(linkedList);
    }
    else
    {
        cout << "Them that bai do danh sach rong hoac sai vi tri" << endl;
    }
    cout << "Cam on ban da trai nghiem chuong trinh kiem thu danh sach lien ket don";
    deleteList(linkedList);
    delete[] p;
    return 0;
}
