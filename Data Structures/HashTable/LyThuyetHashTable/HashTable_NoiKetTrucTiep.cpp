// 1 Trong 2 Cấu Trúc Dữ Liệu Cuối Cùng: Hash Table
#include <bits/stdc++.h>
using namespace std;
// Kích thước bảng băm
#define M 9
struct NODE
{
    int key;
    NODE *pNext;
};
typedef NODE *PHNODE;
// Khởi tạo mảng Hash Table với mỗi phần tử là một Nút
// Mục đích là nếu xảy ra đụng độ, các nút sẽ được nối đuôi nhau như một Linked List
typedef PHNODE HASHTABLE[M];
PHNODE CreatePHNODE(int k)
{
    PHNODE p = new NODE;
    p->key = k;
    p->pNext = nullptr;
    return p;
}
// 1. Hàm băm dạng %
int HF(int key)
{
    return (key % M);
}
// 2. Khởi tạo bảng băm
// Tất cả các ô trong bảng băm ban đầu đều là NULL
void InitHashTable(HASHTABLE &BangBam)
{
    for (int i = 0; i < M; i++)
        BangBam[i] = nullptr;
}
// 3. Kiểm tra Bảng băm rỗng
// 1 ô bất kì trong bảng băm
bool checkHashTable(const HASHTABLE &BangBam, int i)
{
    return (BangBam[i] == nullptr);
}
// Kiểm tra toàn bộ bảng băm
bool isEmptyHashTable(const HASHTABLE &BangBam)
{
    for (int i = 0; i < M; i++)
    {
        if (BangBam[i] != nullptr)
            return false;
    }
    return true;
}
// 4. Hàm thêm 1 Node vào vị trí trống trong bảng băm
void InsertListThemVaoCuoi(PHNODE &head, int k)
{
    if (head == nullptr)
    {
        head = CreatePHNODE(k);
        return;
    }
    PHNODE p = head;
    while (p->pNext != nullptr)
    {
        p = p->pNext;
    }
    p->pNext = CreatePHNODE(k);
}
void InsertListThemVaoDau(PHNODE &head, int k)
{
    PHNODE p = CreatePHNODE(k);
    p->pNext = head;
    head = p;
}
// 5. Thêm khóa k vào bảng băm
void InsertHashTable(HASHTABLE &BangBam, int k)
{
    int i = HF(k);
    // Nếu đúng lí thuyết, các Node đến sau phải thêm vào sau List nếu xảy ra đụng độ tại vị trí i
    InsertListThemVaoCuoi(BangBam[i], k);
}
// 6. Xóa phần tử ra khỏi bảng băm
void DeleteHashTable(HASHTABLE &BangBam, int k)
{
    int i = HF(k);
    // Trỏ tới vị trí khóa sau khi băm
    PHNODE Head = BangBam[i];
    // Không tìm thấy khóa do vị trí Null
    if (Head == nullptr)
    {
        cout << "Khong tim thay phan tu de xoa" << endl;
        return;
    }
    // Khóa nằm ở đầu danh sách
    if (Head->key == k)
    {
        BangBam[i] = BangBam[i]->pNext;
        delete Head;
        cout << "Xoa thanh cong phan tu khoa " << k << endl;
        return;
    }
    // Khóa nằm ở khúc sau (Xảy ra đụng độ)
    PHNODE p = Head;
    while (p->pNext != nullptr)
    {
        if (p->pNext->key == k)
        {
            PHNODE q = p->pNext;
            p->pNext = q->pNext;
            delete q;
            cout << "Xoa thanh cong phan tu khoa " << k << endl;
            return;
        }
        p = p->pNext;
    }
}
// 7. Tìm kiếm khóa K trong bảng băm
PHNODE SearchHashTable(const HASHTABLE &BangBam, int k)
{
    // Băm vị trí trước rồi tính
    int i = HF(k);
    PHNODE Head = BangBam[i];
    while (Head)
    {
        if (Head->key == k)
            return Head;
        Head = Head->pNext;
    }
    return nullptr;
}
// 8. Duyệt một HashTable[i]
// Giống như bạn duyệt 1 danh sách liên kết
void TraverseHashTableI(const PHNODE &Head)
{
    PHNODE p = Head;
    while (p)
    {
        cout << p->key;
        if (p->pNext != nullptr)
            cout << "->";
        p = p->pNext;
    }
}
// 9. Duyệt toàn bộ bảng băm
void TraverseHashTable(const HASHTABLE &BangBam)
{
    if (isEmptyHashTable(BangBam))
    {
        cout << "Bang Bam Rong";
        return;
    }
    for (int i = 0; i < M; i++)
    {
        if (BangBam[i] != nullptr)
        {
            cout << "Bang Bam vi tri " << i << ": ";
            TraverseHashTableI(BangBam[i]);
            cout << endl;
        }
    }
}
void Menu()
{
    HASHTABLE ht;
    InitHashTable(ht); // Bắt buộc khởi tạo trước

    int choice;
    int k;

    while (true)
    {
        cout << "\n================ MENU ================" << endl;
        cout << "1. Them phan tu (Insert)" << endl;
        cout << "2. Xoa phan tu (Delete)" << endl;
        cout << "3. Tim kiem (Search)" << endl;
        cout << "4. Xuat bang bam (Traverse)" << endl;
        cout << "5. Kiem tra rong (Is Empty)" << endl;
        cout << "6. Lam moi bang (Clear)" << endl;
        cout << "0. Thoat (Exit)" << endl;
        cout << "======================================" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Nhap so can them: ";
            cin >> k;
            InsertHashTable(ht, k);
            break;
        case 2:
            cout << "Nhap so can xoa: ";
            cin >> k;
            DeleteHashTable(ht, k);
            break;
        case 3:
            cout << "Nhap so can tim: ";
            cin >> k;
            if (SearchHashTable(ht, k) != nullptr)
                cout << "-> TIM THAY " << k << " trong bang bam!" << endl;
            else
                cout << "-> KHONG TIM THAY " << k << endl;
            break;
        case 4:
            TraverseHashTable(ht);
            break;
        case 5:
            if (isEmptyHashTable(ht))
                cout << "-> Bang bam dang RONG." << endl;
            else
                cout << "-> Bang bam dang CO DU LIEU." << endl;
            break;
        case 6:
            InitHashTable(ht); // Gán lại tất cả về nullptr (Lưu ý: chưa giải phóng bộ nhớ cũ, chỉ reset trỏ)
            cout << "-> Da lam moi bang bam!" << endl;
            break;
        case 0:
            cout << "Ket thuc chuong trinh. Tam biet!" << endl;
            return;
        default:
            cout << "Lua chon khong hop le! Vui long chon lai." << endl;
        }
    }
}

int main()
{
    Menu();
    return 0;
}
