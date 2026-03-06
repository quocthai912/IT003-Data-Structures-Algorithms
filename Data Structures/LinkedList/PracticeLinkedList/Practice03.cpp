#include <iostream>
using namespace std;
struct QuocGia
{
    string tenQuocGia;
    long long danSo, dienTich;
};
struct NODE
{
    QuocGia value;
    NODE *pNext;
};
NODE *initNODE(QuocGia q)
{
    NODE *p = new NODE;
    // Có thể hoán đổi bằng Struct luôn.
    p->value.tenQuocGia = q.tenQuocGia;
    p->value.danSo = q.danSo;
    p->value.dienTich = q.dienTich;
    p->pNext = nullptr;
    return p;
}
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
void CreateEmptyList(LIST &l)
{
    l.pHead = l.pTail = nullptr;
}
void addHead(LIST &l, NODE *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
        return;
    }
    p->pNext = l.pHead;
    l.pHead = p;
}
void nhapDanhSachCacQuocGia(LIST &l)
{
    int soLuong;
    cout << "Nhap so luong cac quoc gia: ";
    cin >> soLuong;
    cin.ignore();
    for (int i = 0; i < soLuong; i++)
    {
        QuocGia q;
        cout << "Nhap ten quoc gia: ";
        getline(cin, q.tenQuocGia);
        cout << "Nhap dan so: ";
        cin >> q.danSo;
        cout << "Nhap dien tich: ";
        cin >> q.dienTich;
        cin.ignore();
        addHead(l, initNODE(q));
    }
}
void danhSachCacQuocGia(const LIST &l)
{
    NODE *p = l.pHead;
    while (p)
    {
        cout << "Ten quoc gia: " << p->value.tenQuocGia << endl;
        cout << "Dan so: " << p->value.danSo << endl;
        cout << "Dien tich: " << p->value.dienTich << endl;
        p = p->pNext;
    }
}
void sapXepTheoTen(LIST &l)
{
    // Đề bài yêu cầu sắp xếp bằng Selection Sort
    // Selection Sort
    /*for (int i = 0; i < n - 1; i++){
          int minIndex = i;
          for (int j = 1; j < n; j++){
          if (A[j] < A[minIndex])
          minIndex = j;
          }
          swap (A[i], A[minIndex]);
    } */
    NODE *i = l.pHead;
    while (i)
    {
        NODE *minTen = i;
        NODE *j = i->pNext;
        while (j)
        {
            if (j->value.tenQuocGia < minTen->value.tenQuocGia)
            {
                minTen = j;
            }
            j = j->pNext;
        }
        QuocGia temp;
        temp.tenQuocGia = i->value.tenQuocGia;
        temp.danSo = i->value.danSo;
        temp.dienTich = i->value.dienTich;
        i->value.tenQuocGia = minTen->value.tenQuocGia;
        i->value.danSo = minTen->value.danSo;
        i->value.dienTich = minTen->value.dienTich;
        minTen->value.tenQuocGia = temp.tenQuocGia;
        minTen->value.danSo = temp.danSo;
        minTen->value.dienTich = temp.dienTich;
        // Có thể hoán đổi bằng Struct, nhưng nên làm như này để hiểu bản chất.
        // Đi thi thì đổi theo Struct.
        i = i->pNext;
    }
}
int main()
{
    LIST l;
    CreateEmptyList(l);
    nhapDanhSachCacQuocGia(l);
    cout << "\n----------------------------------------";
    cout << "\nDANH SACH TRUOC KHI SAP XEP:\n";
    cout << "----------------------------------------\n";
    danhSachCacQuocGia(l);
    sapXepTheoTen(l);
    cout << "\n----------------------------------------";
    cout << "\nDANH SACH SAU KHI SAP XEP:\n";
    cout << "----------------------------------------\n";
    danhSachCacQuocGia(l);
    return 0;
}
