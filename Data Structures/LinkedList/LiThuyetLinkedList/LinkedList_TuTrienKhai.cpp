// Danh sách liên kết là 1 cấu trúc dữ liệu động cho phép quản lí linh hoạt các giá trị
// Khắc phục nhược điểm của khai báo biến thông thường và mãng tĩnh Array
// Chỉ nên dùng khi cần xóa/chèn các phần tử linh hoạt O(1), cần quản lý dữ liệu lớn mà không biết trước
// Chỉ nên dùng khi cần thay đổi thứ tự nhanh chóng, đảo, tách, nối,...
// Là nền móng để triển khai các Data Structures khác như Stack (Ngăn xếp), Queue (Hàng đợi),...
#include <iostream>
using namespace std;
// Bước 1: Tạo Kiểu Dữ Liệu Nút (Node)
struct Node
{
    int data;    // Mỗi nút lưu trữ một dữ liệu
    Node *pNext; // Trỏ tới địa chỉ của nút tiếp theo
};
// Bước 2: Khởi tạo 1 nút (Node)
Node *initNode(int value)
{
    Node *p = new Node; // Ta không thể biết trước có bao nhiêu nút nên ta phải cấp phát động
    // Việc cấp phát động sẽ giúp linh hoạt và có thể thêm nút khi cần thiết
    p->data = value;
    p->pNext = nullptr; // Ta phải đặt con trỏ tiếp theo là nullptr, vì nếu chỉ có 1 nút, nó cũng sẽ không trỏ tới vùng nhớ rác
    return p;           // Trả về nút được khởi tạo
}
// Bước 3: Tạo kiểu dữ liệu Danh sách liên kết đơn (Linked List) gồm nhiều nút liên kết với nhau
// Một danh sách hoạt động dựa trên thao tác hai nút (đầu và cuối)
struct List
{
    Node *pHead; // Nút đầu danh sách
    Node *pTail; // Nút cuối danh sách
};
// Bước 4: Khởi tạo danh sách liên kết (Linked List)
void initList(List &l)
{
    l.pHead = nullptr;
    l.pTail = nullptr;
}
// (1) Thêm nút đầu
void addHead(List &l, Node *p)
{
    // Trường hợp 1: Danh sách rỗng
    if (l.pHead == nullptr)
    {
        l.pHead = p; // Nút được thêm vào sẽ là nút đầu và là nút cuối luôn
        l.pTail = p;
    }
    // Trường hợp 2: Danh sách không rỗng
    else
    {
        p->pNext = l.pHead; // Thêm nút vào đầu, lúc này p được thêm vào sẽ trỏ tới địa chỉ của nút đầu trước đó
        l.pHead = p;        // Nút đầu được thay thế bằng p
    }
}
// (2) Thêm nút cuối
void addTail(List &l, Node *p)
{
    // Danh sách rỗng
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
// (3) Hàm in danh sách liên kết
void InList(const List &l)
{
    if (l.pHead == nullptr)
        cout << "Danh sach lien ket rong" << endl;
    else
    {
        Node *p = l.pHead;
        while (p != nullptr)
        {
            cout << p->data;
            if (p != l.pTail)
                cout << "->";
            p = p->pNext; // Trỏ tới vị trí con trỏ tiếp theo để in nút kế tiếp
        }
        cout << endl;
    }
}
// (4) Hàm in các địa chỉ của các nút
void InListAddress(const List &l)
{
    if (l.pHead == nullptr)
        cout << "Danh sach lien ket rong" << endl;
    else
    {
        Node *p = l.pHead;
        while (p != nullptr)
        {
            cout << p << " ";
            p = p->pNext;
        }
        cout << endl;
    }
}
// (5) Hàm tìm giá trị trong danh sách liên kết
bool searchValue(const List &l, int value)
{
    Node *p = l.pHead;
    while (p != nullptr)
    {
        if (p->data == value)
            return true;
        p = p->pNext;
    }
    return false;
}
// (6) Mở rộng: Hàm tìm giá trị trả về địa chỉ của Nút (Node)
Node *searchValueAddress(const List &l, int value)
{
    Node *p = l.pHead;
    while (p != nullptr)
    {
        if (p->data == value)
            return p;
        p = p->pNext;
    }
    return nullptr;
}
// (7) Hàm tìm giá trị Node kế cuối
bool searchValueSecondLastNode(const List &l, int &value)
{
    Node *p = l.pHead;
    while (p != nullptr)
    {
        if (p->pNext == l.pTail)
        {
            value = p->data;
            return true;
        }
        p = p->pNext;
    }
    return false;
}
// (8) Mở rộng: Hàm tìm giá trị Node kế cuối, trả về địa chỉ
Node *searchValueSecondLastNodeAddress(const List &l)
{
    Node *p = l.pHead;
    while (p != nullptr)
    {
        if (p->pNext == l.pTail)
        {
            return p;
        }
        p = p->pNext;
    }
    return nullptr;
}
// (9) Hàm đếm các nút chứa giá trị chẵn
int CountEvenNumber(const List &l)
{
    int count = 0;
    Node *p = l.pHead;
    while (p != nullptr)
    {
        if (p->data % 2 == 0)
            count++;
        p = p->pNext;
    }
    return count;
}
// (10) Hàm tìm giá trị lớn nhất trong một danh sách
int maxInLinkedList(const List &l)
{
    int max = l.pHead->data;
    Node *p = l.pHead->pNext; // Vì đã gáng max bằng giá trị của pHead rồi, không so sánh lại gây lãng phí
    while (p != nullptr)
    {
        if (p->data > max)
            max = p->data;
        p = p->pNext;
    }
    return max;
}
// (11) Hàm tìm giá trị nhỏ nhất trong một danh sách
int minInLinkedList(const List &l)
{
    int min = l.pHead->data;
    Node *p = l.pHead->pNext; // Vì đã gáng min bằng giá trị của pHead rồi, không so sánh lại gây lãng phí
    while (p != nullptr)
    {
        if (p->data < min)
            min = p->data;
        p = p->pNext;
    }
    return min;
}
// (12) Hàm kiểm tra danh sách rỗng
bool kiemTraDanhSachRong(const List &l)
{
    if (l.pHead == nullptr) // Nút đầu chỉ = nullptr khi danh sách rỗng
        return true;
    return false;
}
// (13) Hàm tính chiều dài của danh sách liên kết
int returnLength(const List &l)
{
    int count = 0;
    Node *p = l.pHead;
    while (p != nullptr)
    {
        count++;
        p = p->pNext;
    }
    return count;
}
// (14) Hàm trả về Node thứ n trong danh sách
Node *returnNodeThuN(const List &l, int position)
{
    int length = returnLength(l);
    if (position <= 0 || position > length) // Quá độ dài, trả về con trỏ null
        return nullptr;
    else
    {
        position--; // Để duyệt đúng thứ tự từ 0
        int count = 0;
        Node *p = l.pHead;
        while (p != nullptr)
        {
            if (count == position) // Khi biến đếm bằng vị trí, trả về con trỏ trỏ tới nút tại vị trí đó
                return p;
            p = p->pNext;
            count++;
        }
        return nullptr;
    }
}
// (15) Hàm cập nhập giá trị Node tại vị trí xác định bằng giá trị khác
void updateNodeValue(List &l, int position, int value)
{
    Node *p = returnNodeThuN(l, position);
    if (p != nullptr) // Nếu con trỏ khác null, ta cập nhập giá trị
        p->data = value;
}
// (16) Hàm copy danh sách
List copyLinkedList(const List &l)
{
    List copy;
    initList(copy);
    Node *p = l.pHead;
    while (p != nullptr)
    {
        // Khởi tạo một nút mới với dữ liệu của nút cũ, sử dụng khác con trỏ
        Node *newNode = new Node{p->data, nullptr}; // Struct không có constructor tự khởi tạo như class nên phải dùng {}
        // Cách 2 Node* newNode = initNode(p->data);
        addTail(copy, newNode);
        p = p->pNext;
    }
    return copy;
}
// (17) Hàm xóa nút đầu
bool popHead(List &l)
{
    if (l.pHead == nullptr) // Nếu danh sách rỗng, không thể xóa
        return false;
    Node *temp = l.pHead;
    l.pHead = l.pHead->pNext;
    delete temp;
    if (l.pHead == nullptr) // Nếu sao khi xóa, danh sách rỗng
        l.pTail = nullptr;
    return true;
}
// (18) Hàm xóa nút cuối
bool popTail(List &l)
{
    if (l.pHead == nullptr) // Danh sách rỗng
        return false;
    if (l.pHead == l.pTail) // Danh sách chỉ có 1 nút
    {
        delete l.pTail;
        l.pHead = nullptr; // Danh sách trở lại rỗng, phải có null để tránh trỏ vào vùng nhớ rác
        l.pTail = nullptr;
        return true;
    }
    Node *p = l.pHead;
    while (p->pNext != l.pTail)
    {
        p = p->pNext; // p trỏ tới node kế cuối
    }
    delete l.pTail;
    p->pNext = nullptr; // Gán lại để không trỏ vào vùng nhớ rác. gây lỗi
    l.pTail = p;        // Cập nhập lại node cuối bằng node kế cuối
    return true;
}
// (19) Hàm xóa nút tại vị trí bất kì
bool popIndex(List &l, int position)
{
    int length = returnLength(l);
    if (position <= 0 || position > length) // Trường hợp vị trí sai
        return false;
    if (l.pHead == nullptr) // Trường hợp danh sách rỗng
        return false;
    if (position == length) // Trường hợp vị trí xóa là node cuối
    {
        return popTail(l);
    }
    if (position == 1) // Trường hợp xóa là nút đầu
        return popHead(l);
    Node *prev = returnNodeThuN(l, position - 1); // Node kế node cần xóa
    Node *deleteNode = prev->pNext;               // Node cần xóa
    prev->pNext = deleteNode->pNext;
    delete deleteNode;
    return true;
}
// (20) Hàm thêm nút tại vị trí bất kì (Nâng cao)
bool pushIndex(List &l, int position, int value)
{
    int length = returnLength(l);
    if (position <= 0 || position > length + 1) // Trường hợp vị trí sai
        return false;
    if (position == 1) // Thêm đầu
    {
        Node *p = initNode(value);
        addHead(l, p);
        return true;
    }
    if (position == length + 1) // Thêm cuối
    {
        Node *p = initNode(value);
        addTail(l, p);
        return true;
    }
    Node *prev = returnNodeThuN(l, position - 1); // Node kế node cần thêm
    Node *newNode = initNode(value);
    newNode->pNext = prev->pNext; // Node kế tiếp của node mới sẽ là node cũ mà node kế node mới trỏ tới
    prev->pNext = newNode;        // Node kế node cần thêm
    return true;
}
// (21) Hàm đảo ngược danh sách liên kết đơn
bool reverseLinkedList(List &l)
{
    if (l.pHead == nullptr) // Danh sách rỗng
        return false;
    if (l.pHead == l.pTail) // Danh sách chỉ có 1 nút
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
    /*Sau khi đảo pHead vẫn sẽ trỏ tới địa chỉ pHead cũ, lúc này pNext đã trỏ về null sau khi đổi
    nên sẽ bị đứt đoạn toàn bộ danh sách từ Node đầu tới các node còn lại nếu vẫn cố in ra*/
    l.pTail = l.pHead; // Phải cập nhập node cuối mới là node đầu cũ vì đảo ngược
    l.pHead = prev;    // Cập nhập lại node đầu mới trỏ về địa chỉ của node cuối cùng
    return true;
}
// (22) Hàm giải phóng bộ nhớ
void deleteList(List &l)
{
    Node *p = l.pHead;
    while (p != nullptr)
    {
        Node *temp = p; // Lúc này temp và p dùng chung 1 địa chỉ bộ nhớ
        // Nhưng khi thay đổi địa chỉ của p, địa chỉ của temp không thay đổi
        // Chỉ đơn giản là bạn gán địa chỉ bộ nhớ của p cho temp
        p = p->pNext;
        delete temp; // Xóa nút tại địa chỉ bộ nhớ của temp;
    }
    l.pHead = nullptr;
    l.pTail = nullptr;
}
int main()
{
    List linkedList, copy;
    initList(linkedList);
    initList(copy);      // Chức năng copy danh sách liên kết
    bool create = false; // Biến xác định danh sách liên kết đơn đã được khởi tạo thành công
    cout << "=====================DANH SACH LIEN KET DON====================\n";
    cout << "0. Ket thuc chuong trinh" << endl;
    cout << "1. Khoi tao danh sach " << endl;
    cout << "2. Them nut dau" << endl;
    cout << "3. Them nut cuoi" << endl;
    cout << "4. Them node vi tri bat ki" << endl;
    cout << "5. In danh sach" << endl;
    cout << "6. In danh sach dia chi cac nut" << endl;
    cout << "7. Tim kiem gia tri" << endl;
    cout << "8. Tim kiem gia tri node ke cuoi" << endl;
    cout << "9. Dem cac nut chua gia tri chan" << endl;
    cout << "10. Gia tri lon nhat" << endl;
    cout << "11. Gia tri nho nhat" << endl;
    cout << "12. Kiem tra danh sach co rong hay khong" << endl;
    cout << "13. Cap nhap gia tri cho nut" << endl;
    cout << "14. Copy danh sach lien ket don" << endl;
    cout << "15. Kiem tra danh sach lien ket copy co thay doi khong" << endl;
    cout << "16. Xoa nut dau" << endl;
    cout << "17. Xoa nut cuoi" << endl;
    cout << "18. Xoa nut tai vi tri bat ki" << endl;
    cout << "19. Dao nguoc danh sach lien ket" << endl;
    int select;
    do
    {
        cout << "Ban chon: ";
        cin >> select;
        cout << "===============================================================" << endl;
        switch (select)
        {
        case 0:
        {
            cout << "Ket thuc chuong trinh................\n";
            break;
        }
        case 1:
        {
            int soLuongNut;
            cout << "Nhap so luong nut > 0: ";
            do
            {
                cin >> soLuongNut;
                if (soLuongNut <= 0)
                    cout << "Khong hop le, xin nhap lai: ";
            } while (soLuongNut <= 0);
            int *p = new int[soLuongNut];
            for (int i = 0; i < soLuongNut; i++)
            {
                cin >> p[i];
                addTail(linkedList, initNode(p[i]));
            }
            cout << "Danh sach lien ket don da duoc khoi tao" << endl;
            create = true;
            delete[] p;
            break;
        }
        case 2:
        {
            int value;
            cout << "Xin moi nhap gia tri nut dau: ";
            cin >> value;
            Node *p = initNode(value);
            addHead(linkedList, p);
            cout << "Nut dau da duoc them thanh cong, danh sach sau khi them: " << endl;
            InList(linkedList);
            create = true;
            break;
        }
        case 3:
        {
            int value;
            cout << "Xin moi nhap gia tri nut cuoi: ";
            cin >> value;
            Node *p = initNode(value);
            addTail(linkedList, p);
            cout << "Nut cuoi da duoc them thanh cong, danh sach sau khi them: " << endl;
            InList(linkedList);
            create = true;
            break;
        }
        case 4:
        {
            int position, value;
            cout << "Nhap vi tri node can them > 0: ";
            cin >> position;
            cout << "Nhap gia tri node can them: ";
            cin >> value;
            if (pushIndex(linkedList, position, value))
            {
                cout << "Nut o vi tri " << position << " da duoc them thanh cong, danh sach: " << endl;
                InList(linkedList);
                create = true;
            }
            else
            {
                cout << "Khong the them do vi tri node khong hop le" << endl;
            }
            break;
        }
        case 5:
        {
            if (create)
            {
                cout << "Danh sach lien ket don: " << endl;
                InList(linkedList);
            }
            else
            {
                cout << "Danh sach lien ket don chua duoc khoi tao, vui long khoi tao" << endl;
            }
            break;
        }
        case 6:
        {
            if (create)
            {
                cout << "Danh sach dia chi cac nut trong danh sach lien ket don: " << endl;
                InListAddress(linkedList);
            }
            else
            {
                cout << "Danh sach lien ket don chua duoc khoi tao, vui long khoi tao" << endl;
            }
            break;
        }
        case 7:
        {
            if (create)
            {
                int value;
                cout << "Xin moi nhap gia tri can tim: ";
                cin >> value;
                if (searchValue(linkedList, value))
                {
                    cout << "Da tim thay gia tri " << value << " trong danh sach lien ket" << endl;
                }
                else
                {
                    cout << "Khong tim thay gia tri" << endl;
                }
            }
            else
            {
                cout << "Khong the tim thay do danh sach lien ket chua duoc khoi tao" << endl;
            }
            break;
        }
        case 8:
        {
            if (create)
            {
                int x;
                if (searchValueSecondLastNode(linkedList, x))
                {
                    cout << "Da tim thay gia tri cua nut ke cuoi, gia tri = " << x << endl;
                }
                else
                {
                    cout << "Khong tim thay gia tri node ke cuoi" << endl;
                }
            }
            else
            {
                cout << "Khong the tim thay do danh sach lien ket chua duoc khoi tao" << endl;
            }
            break;
        }
        case 9:
        {
            if (create)
            {
                int count = CountEvenNumber(linkedList);
                cout << "So luong cac nut co gia tri chan la: " << count << endl;
            }
            else
            {
                cout << "Khong the dem do danh sach lien ket chua duoc khoi tao" << endl;
            }
            break;
        }
        case 10:
        {
            if (create)
            {
                int Max = maxInLinkedList(linkedList);
                cout << "Gia tri max cua danh sach lien ket don la: " << Max << endl;
            }
            else
            {
                cout << "Khong the tim thay gia tri max do danh sach lien ket chua duoc khoi tao" << endl;
            }
            break;
        }
        case 11:
        {
            if (create)
            {
                int Min = minInLinkedList(linkedList);
                cout << "Gia tri min cua danh sach lien ket don la: " << Min << endl;
            }
            else
            {
                cout << "Khong the tim thay gia tri min do danh sach lien ket chua duoc khoi tao" << endl;
            }
            break;
        }
        case 12:
        {
            if (kiemTraDanhSachRong(linkedList))
                cout << "Danh sach lien ket don dang rong" << endl;
            else
                cout << "Danh sach da co cac nut" << endl;
            break;
        }
        case 13:
        {
            if (create)
            {
                int value, position;
                cout << "Nhap so thu tu nut can cap nhap gia tri: ";
                cin >> position;
                cout << "Nhap gia tri: ";
                cin >> value;
                updateNodeValue(linkedList, position, value);
                cout << "Da cap nhap thanh cong, danh sach sau khi cap nhap: " << endl;
                InList(linkedList);
            }
            else
            {
                cout << "Khong the cap nhap do danh sach lien ket chua duoc khoi tao" << endl;
            }
            break;
        }
        case 14:
        {
            if (create)
            {
                copy = copyLinkedList(linkedList);
                cout << "Danh sach thu nhat: " << endl;
                InList(linkedList);
                cout << "Danh sach copy: " << endl;
                InList(copy);
            }
            else
            {
                cout << "Danh sach goc chua duoc khoi tao, khong the tien hanh copy" << endl;
            }
            break;
        }
        case 15:
        {
            // Chỉ nên sử dụng chức năng này sao khi đã thay đổi danh sách gốc
            if (create)
            {
                cout << "Danh sach lien ket copy: " << endl;
                InList(copy);
            }
            else
            {
                cout << "Danh sach goc chua duoc khoi tao nen khong co danh sach copy" << endl;
            }
            break;
        }
        case 16:
        {
            if (create)
            {
                if (popHead(linkedList))
                {
                    cout << "Da xoa thanh cong nut dau, danh sach sau khi xoa: " << endl;
                    InList(linkedList);
                }
                else
                {
                    cout << "Khong the xoa do co loi, xin hay kiem tra lai";
                }
            }
            else
                cout << "Khong the xoa do danh sach chua duoc khoi tao" << endl;
            break;
        }
        case 17:
        {
            if (create)
            {
                if (popTail(linkedList))
                {
                    cout << "Da xoa thanh cong nut cuoi, danh sach sau khi xoa: " << endl;
                    InList(linkedList);
                }
                else
                {
                    cout << "Khong the xoa do co loi, xin hay kiem tra lai";
                }
            }
            else
                cout << "Khong the xoa do danh sach chua duoc khoi tao" << endl;
            break;
        }
        case 18:
        {
            if (create)
            {
                int position;
                cout << "Chon nut can xoa (Bat dau tu nut thu nhat - 1): ";
                cin >> position;
                if (popIndex(linkedList, position))
                {
                    cout << "Da xoa thanh cong nut thu " << position << ", danh sach sau khi xoa: " << endl;
                    InList(linkedList);
                }
                else
                {
                    cout << "Khong the xoa do co loi, xin hay kiem tra lai";
                }
            }
            else
                cout << "Khong the xoa do danh sach chua duoc khoi tao" << endl;
            break;
        }
        case 19:
        {
            if (create)
            {
                if (reverseLinkedList(linkedList))
                {
                    cout << "Dao nguoc thanh cong, danh sach sau khi dao nguoc: " << endl;
                    InList(linkedList);
                }
                else
                {
                    cout << "Dao nguoc that bai do co loi, xin hay kiem tra lai" << endl;
                }
            }
            else
            {
                cout << "Khong the dao nguoc do danh sach rong, xin hay khoi tao danh sach" << endl;
            }
            break;
        }
        default:
        {
            cout << "Khong hop le, xin nhap lai!!!\n";
            break;
        }
        }

    } while (select != 0);
    deleteList(copy);
    deleteList(linkedList);
    return 0;
}