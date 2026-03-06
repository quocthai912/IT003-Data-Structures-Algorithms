// Áp dụng danh sách liên kết đơn vào quản lý sinh viên
#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
struct SinhVien
{
    string maSV, hoTen, khoa, xepLoai;
    double diemTB;
};
void inThongTinSinhVien(const SinhVien &sv)
{
    cout << "Ma sinh vien: " << sv.maSV << endl;
    cout << "Ho ten: " << sv.hoTen << endl;
    cout << "Khoa: " << sv.khoa << endl;
    cout << "Diem trung binh tich luy: " << sv.diemTB << endl;
    cout << "Xep loai: " << sv.xepLoai << endl;
}
void nhapThongTin(SinhVien &sv)
{
    cout << "Moi nhap ma sinh vien: ";
    getline(cin, sv.maSV);
    cout << "Moi nhap ho ten: ";
    getline(cin, sv.hoTen);
    cout << "Moi nhap khoa: ";
    getline(cin, sv.khoa);
    cout << "Moi nhap diem trung binh: ";
    do
    {
        cin >> sv.diemTB;
        if (sv.diemTB < 0 || sv.diemTB > 10)
            cout << "Diem am hoac lon hon 10, xin nhap lai: ";
    } while (sv.diemTB < 0 || sv.diemTB > 10);
    cin.ignore();
    if (sv.diemTB >= 9 && sv.diemTB <= 10)
        sv.xepLoai = "Xuat sac";
    else if (sv.diemTB >= 8 && sv.diemTB < 9)
        sv.xepLoai = "Gioi";
    else if (sv.diemTB >= 7 && sv.diemTB < 8)
        sv.xepLoai = "Kha";
    else if (sv.diemTB >= 5 && sv.diemTB < 7)
        sv.xepLoai = "Trung Binh";
    else if (sv.diemTB >= 3.5 && sv.diemTB < 5)
        sv.xepLoai = "Yeu";
    else
        sv.xepLoai = "Kem";
}
struct Node
{
    SinhVien data;
    Node *pNext;
};
Node *initNode(SinhVien value)
{
    Node *p = new Node;
    p->data = value;
    p->pNext = nullptr;
    return p;
}
struct List
{
    Node *pHead;
    Node *pTail;
};
void initList(List &l)
{
    l.pHead = nullptr;
    l.pTail = nullptr;
}
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
void addHead(List &l, Node *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void addTail(List &l, Node *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
bool popHead(List &l)
{
    if (l.pHead == nullptr)
        return false;
    Node *p = l.pHead->pNext;
    delete l.pHead;
    l.pHead = p;
    if (l.pHead == nullptr)
        l.pTail = nullptr;
    return true;
}
bool popTail(List &l)
{
    if (l.pHead == nullptr)
        return false;
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
    p->pNext = nullptr;
    l.pTail = p;
    return true;
}
int lengthLinkedList(const List &l)
{
    if (l.pHead == nullptr)
        return 0;
    int count = 0;
    Node *p = l.pHead;
    while (p != nullptr)
    {
        count++;
        p = p->pNext;
    }
    return count;
}
Node *returnNodeThuN(const List &l, int position)
{
    int length = lengthLinkedList(l);
    if (position <= 0 || position > length)
        return nullptr;
    if (l.pHead == nullptr)
        return nullptr;
    position--;
    int count = 0;
    Node *p = l.pHead;
    while (p != nullptr)
    {
        if (count == position)
            return p;
        p = p->pNext;
        count++;
    }
    return nullptr;
}
bool addNodeInPos(List &l, Node *p, int pos)
{
    int length = lengthLinkedList(l);
    if (pos <= 0 || pos > length + 1)
        return false;
    if (pos == length + 1)
    {
        addTail(l, p);
        return true;
    }
    if (pos == 1)
    {
        addHead(l, p);
        return true;
    }
    Node *nodeKeNodeCanThem = returnNodeThuN(l, pos - 1);
    p->pNext = nodeKeNodeCanThem->pNext;
    nodeKeNodeCanThem->pNext = p;
    return true;
}
bool popNodeInPos(List &l, int pos)
{
    int length = lengthLinkedList(l);
    if (pos <= 0 || pos > length)
        return false;
    if (pos == 1)
    {
        popHead(l);
        return true;
    }
    if (pos == length)
    {
        popTail(l);
        return true;
    }
    Node *nodeKeNodeCanXoa = returnNodeThuN(l, pos - 1);
    Node *deleteNode = nodeKeNodeCanXoa->pNext;
    nodeKeNodeCanXoa->pNext = deleteNode->pNext;
    delete deleteNode;
    return true;
}
bool reverseLinkedList(List &l)
{
    if (l.pHead == nullptr)
        return false;
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
void initListDataSinhVien(List &l)
{
    SinhVien sv1 = {"24521598", "To Quoc Thai", "Khoa hoc may tinh", "Gioi", 8.93};
    SinhVien sv2 = {"24521599", "Nguyen Duy Tan", "Khoa hoc may tinh", "Gioi", 8.21};
    SinhVien sv3 = {"24521455", "Do Trong Phuc", "Khoa hoc may tinh", "Xuat Sac", 9.46};
    addHead(l, initNode(sv3));
    addHead(l, initNode(sv2));
    addHead(l, initNode(sv1));
}
void inDanhSach(const List &l)
{
    if (l.pHead == nullptr)
        cout << "Danh sach rong" << endl;
    else
    {
        Node *p = l.pHead;
        while (p != nullptr)
        {
            inThongTinSinhVien(p->data);
            cout << endl;
            p = p->pNext;
        }
    }
}
double maxDiemTB(const List &l)
{
    if (l.pHead == nullptr)
        return 0.0;
    double maxTB = l.pHead->data.diemTB;
    Node *p = l.pHead->pNext;
    while (p != nullptr)
    {
        if (p->data.diemTB > maxTB)
            maxTB = p->data.diemTB;
        p = p->pNext;
    }
    return maxTB;
}
double minDiemTB(const List &l)
{
    if (l.pHead == nullptr)
        return 0.0;
    double minTB = l.pHead->data.diemTB;
    Node *p = l.pHead->pNext;
    while (p != nullptr)
    {
        if (p->data.diemTB < minTB)
            minTB = p->data.diemTB;
        p = p->pNext;
    }
    return minTB;
}
Node *timKiemTheoMaSinhVien(const List &l, const string &maCanTim, bool &found)
{
    found = false;
    if (l.pHead == nullptr)
        return nullptr;
    Node *p = l.pHead;
    while (p != nullptr)
    {
        if (p->data.maSV == maCanTim)
        {
            found = true;
            return p;
        }
        p = p->pNext;
    }
    return nullptr;
}
void danhSachSinhVienMaxDiemTB(const List &l)
{
    if (l.pHead == nullptr)
        cout << "Danh sach rong" << endl;
    else
    {
        double maxDiem = maxDiemTB(l);
        Node *p = l.pHead;
        while (p != nullptr)
        {
            if (p->data.diemTB == maxDiem)
            {
                inThongTinSinhVien(p->data);
                cout << endl;
            }
            p = p->pNext;
        }
    }
}
void danhSachSinhVienMinDiemTB(const List &l)
{
    if (l.pHead == nullptr)
        cout << "Danh sach rong" << endl;
    else
    {
        double minDiem = minDiemTB(l);
        Node *p = l.pHead;
        while (p != nullptr)
        {
            if (p->data.diemTB == minDiem)
            {
                inThongTinSinhVien(p->data);
                cout << endl;
            }
            p = p->pNext;
        }
    }
}
int main()
{
    List studentList;
    initList(studentList);
    bool initialized = false;
    int choice;
    cout << "============= QUAN LY SINH VIEN BANG DANH SACH LIEN KET =============\n";
    do
    {
        cout << "\n===== MENU CHINH =====\n";
        cout << "1. Khoi tao danh sach sinh vien\n";
        cout << "2. Them sinh vien vao dau danh sach\n";
        cout << "3. Them sinh vien vao cuoi danh sach\n";
        cout << "4. Them sinh vien vao vi tri bat ky\n";
        cout << "5. Xoa sinh vien dau danh sach\n";
        cout << "6. Xoa sinh vien cuoi danh sach\n";
        cout << "7. Xoa sinh vien tai vi tri bat ky\n";
        cout << "8. Hien thi toan bo danh sach sinh vien\n";
        cout << "9. Tim kiem sinh vien theo ma SV\n";
        cout << "10. Hien thi sinh vien co diem TB cao nhat\n";
        cout << "11. Hien thi sinh vien co diem TB thap nhat\n";
        cout << "12. Dao nguoc danh sach sinh vien\n";
        cout << "13. Khoi tao du lieu mau (3 sinh vien)\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "========================================\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            if (initialized)
            {
                cout << "Danh sach da duoc khoi tao truoc do. Ban co muon xoa va tao moi? (y/n): ";
                char confirm;
                cin >> confirm;
                cin.ignore();
                if (confirm != 'y' && confirm != 'Y')
                {
                    break;
                }
                deleteList(studentList);
            }

            int n;
            cout << "Nhap so luong sinh vien can them: ";
            cin >> n;
            cin.ignore();

            for (int i = 0; i < n; i++)
            {
                SinhVien sv;
                cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
                nhapThongTin(sv);
                addTail(studentList, initNode(sv));
            }
            initialized = true;
            cout << "Da khoi tao danh sach voi " << n << " sinh vien.\n";
            break;
        }

        case 2:
        {
            SinhVien sv;
            cout << "Nhap thong tin sinh vien can them vao dau danh sach:\n";
            nhapThongTin(sv);
            addHead(studentList, initNode(sv));
            cout << "Da them sinh vien vao dau danh sach.\n";
            initialized = true;
            break;
        }

        case 3:
        {
            SinhVien sv;
            cout << "Nhap thong tin sinh vien can them vao cuoi danh sach:\n";
            nhapThongTin(sv);
            addTail(studentList, initNode(sv));
            cout << "Da them sinh vien vao cuoi danh sach.\n";
            initialized = true;
            break;
        }

        case 4:
        {
            if (!initialized)
            {
                cout << "Danh sach chua duoc khoi tao. Vui long chon option 1 truoc.\n";
                break;
            }
            int pos;
            cout << "Nhap vi tri can them (1-" << lengthLinkedList(studentList) + 1 << "): ";
            cin >> pos;
            cin.ignore();
            SinhVien sv;
            cout << "Nhap thong tin sinh vien can them:\n";
            nhapThongTin(sv);
            if (addNodeInPos(studentList, initNode(sv), pos))
            {
                cout << "Da them sinh vien vao vi tri " << pos << ".\n";
            }
            else
            {
                cout << "Vi tri khong hop le!\n";
            }
            break;
        }
        case 5:
        {
            if (!initialized)
            {
                cout << "Danh sach chua duoc khoi tao. Vui long chon option 1 truoc.\n";
                break;
            }
            if (popHead(studentList))
            {
                cout << "Da xoa sinh vien dau danh sach.\n";
            }
            else
            {
                cout << "Danh sach rong, khong the xoa!\n";
            }
            break;
        }

        case 6:
        {
            if (!initialized)
            {
                cout << "Danh sach chua duoc khoi tao. Vui long chon option 1 truoc.\n";
                break;
            }
            if (popTail(studentList))
            {
                cout << "Da xoa sinh vien cuoi danh sach.\n";
            }
            else
            {
                cout << "Danh sach rong, khong the xoa!\n";
            }
            break;
        }

        case 7:
        {
            if (!initialized)
            {
                cout << "Danh sach chua duoc khoi tao. Vui long chon option 1 truoc.\n";
                break;
            }
            int pos;
            cout << "Nhap vi tri can xoa (1-" << lengthLinkedList(studentList) << "): ";
            cin >> pos;
            cin.ignore();
            if (popNodeInPos(studentList, pos))
            {
                cout << "Da xoa sinh vien tai vi tri " << pos << ".\n";
            }
            else
            {
                cout << "Vi tri khong hop le hoac danh sach rong!\n";
            }
            break;
        }

        case 8:
        {
            if (!initialized)
            {
                cout << "Danh sach chua duoc khoi tao. Vui long chon option 1 truoc.\n";
                break;
            }
            cout << "\n===== DANH SACH SINH VIEN =====\n";
            inDanhSach(studentList);
            break;
        }
        case 9:
        {
            if (!initialized)
            {
                cout << "Danh sach chua duoc khoi tao. Vui long chon option 1 truoc.\n";
                break;
            }
            string maSV;
            cout << "Nhap ma sinh vien can tim: ";
            getline(cin, maSV);
            bool found;
            Node *result = timKiemTheoMaSinhVien(studentList, maSV, found);
            if (found)
            {
                cout << "\nTim thay sinh vien:\n";
                inThongTinSinhVien(result->data);
            }
            else
            {
                cout << "Khong tim thay sinh vien co ma " << maSV << "!\n";
            }
            break;
        }

        case 10:
        {
            if (!initialized)
            {
                cout << "Danh sach chua duoc khoi tao. Vui long chon option 1 truoc.\n";
                break;
            }

            cout << "\n===== SINH VIEN CO DIEM TB CAO NHAT =====\n";
            danhSachSinhVienMaxDiemTB(studentList);
            break;
        }

        case 11:
        {
            if (!initialized)
            {
                cout << "Danh sach chua duoc khoi tao. Vui long chon option 1 truoc.\n";
                break;
            }

            cout << "\n===== SINH VIEN CO DIEM TB THAP NHAT =====\n";
            danhSachSinhVienMinDiemTB(studentList);
            break;
        }

        case 12:
        {
            if (!initialized)
            {
                cout << "Danh sach chua duoc khoi tao. Vui long chon option 1 truoc.\n";
                break;
            }

            if (reverseLinkedList(studentList))
            {
                cout << "Da dao nguoc danh sach sinh vien.\n";
                cout << "Danh sach sau khi dao nguoc:\n";
                inDanhSach(studentList);
            }
            else
            {
                cout << "Khong the dao nguoc danh sach rong!\n";
            }
            break;
        }

        case 13:
        {
            if (initialized)
            {
                cout << "Danh sach da duoc khoi tao truoc do. Ban co muon xoa va tao moi? (y/n): ";
                char confirm;
                cin >> confirm;
                cin.ignore();
                if (confirm != 'y' && confirm != 'Y')
                {
                    break;
                }
                deleteList(studentList);
            }

            initListDataSinhVien(studentList);
            initialized = true;
            cout << "Da khoi tao danh sach mau voi 3 sinh vien.\n";
            break;
        }

        case 0:
        {
            cout << "Thoat chuong trinh...\n";
            break;
        }

        default:
        {
            cout << "Lua chon khong hop le. Vui long nhap lai!\n";
            break;
        }
        }
    } while (choice != 0);

    if (initialized)
    {
        deleteList(studentList);
    }

    return 0;
}