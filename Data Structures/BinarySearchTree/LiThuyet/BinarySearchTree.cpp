#include <iostream>
using namespace std;
struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
// Định nghĩa 1 TNODE, ta xem như 1 cây (TREE).
typedef TNODE *TREE;
// 1. Tìm kiếm NODE có giá trị X (Không sử dụng đệ quy).
// Độ phức tạp: O(h) với h là chiều cao của cây.
TNODE *searchNode(TREE root, int X)
{
    TNODE *p = root;
    while (p)
    {
        // Tìm thấy X
        if (p->key == X)
            return p;
        // Nếu X > key, tìm bên phải
        else if (p->key < X)
            p = p->pRight;
        // Nếu X < key, tìm bên trái
        else
            p = p->pLeft;
    }
    return nullptr;
}
// 2. Tìm kiếm NODE có giá trị X (Sử dụng đệ quy).
TNODE *searchNodeRecursion(TREE root, int X)
{
    TNODE *p = root;
    if (p)
    {
        if (p->key == X)
            return p;
        else if (p->key < X)
            return searchNodeRecursion(p->pRight, X);
        else
            return searchNodeRecursion(p->pLeft, X);
    }
    return nullptr;
}
// 3. Khởi tạo cây rỗng.
void CreateEmptyTree(TREE &root)
{
    root = nullptr;
}
// 4. Khởi tạo 1 Node
TNODE *CreateTNODE(int x)
{
    TNODE *p = new TNODE;
    p->key = x;
    p->pLeft = p->pRight = nullptr;
    return p;
}
// 5. Thêm Node vào cây nhị phân tìm kiếm, sử dụng đệ quy.
// Độ phức tạp: O(h) với h là chiều cao của cây.
bool insert(TREE &T, int x)
{
    if (T)
    {
        if (T->key == x)
            return false;
        else if (T->key < x)
            return insert(T->pRight, x);
        else
            return insert(T->pLeft, x);
    }
    T = CreateTNODE(x);
    return true;
}
// 6. Thêm Node vào cây nhị phân tìm kiếm, không sử dụng đệ quy.
bool insertNoRecursion(TREE &Root, int x)
{
    if (Root == nullptr)
    {
        Root = CreateTNODE(x);
        return true;
    }
    TREE T = Root;
    while (T)
    {
        if (T->key == x)
            return false;
        else if (T->key < x)
        {
            if (T->pRight == nullptr)
            {
                T->pRight = CreateTNODE(x);
                return true;
            }
            else
                T = T->pRight;
        }
        else
        {
            if (T->pLeft == nullptr)
            {
                T->pLeft = CreateTNODE(x);
                return true;
            }
            else
                T = T->pLeft;
        }
    }
    return true;
}
// 7. Duyệt cây nhị phân tìm kiếm.
// Độ phức tạp: O(N).
// INORDER (Left-Node-Right).
void Inorder(TREE Root)
{
    if (Root != nullptr)
    {
        Inorder(Root->pLeft);
        cout << Root->key << " ";
        Inorder(Root->pRight);
    }
}
// PREORDER (Node-Left-Right).
void Preorder(TREE Root)
{
    if (Root != nullptr)
    {
        cout << Root->key << " ";
        Preorder(Root->pLeft);
        Preorder(Root->pRight);
    }
}
// POSTORDER (Left-Right-Node).
void Postorder(TREE Root)
{
    if (Root != nullptr)
    {
        Postorder(Root->pLeft);
        Postorder(Root->pRight);
        cout << Root->key << " ";
    }
}
// 8. Tìm giá trị nhỏ nhất trên cây (MIN).
TNODE *findMin(TREE T)
{
    if (T == nullptr)
        return nullptr;
    else if (T->pLeft == nullptr)
        return T;
    return findMin(T->pLeft);
}
// 9. Tìm giá trị lớn nhất trên cây (MAX).
// Cả hai phép duyệt trên đều có độ phức tạp là O(h) do phải duyệt sâu tới Node lá.
TNODE *findMax(TREE T)
{
    if (T == nullptr)
        return nullptr;
    else if (T->pRight == nullptr)
        return T;
    return findMax(T->pRight);
}
// 10. Hàm xóa Node khỏi cây nhị phân tìm kiếm.
void deleteNode(TREE &T, int x)
{
    if (T)
    {
        if (T->key < x)
            deleteNode(T->pRight, x);
        else if (T->key > x)
            deleteNode(T->pLeft, x);
        else
        {
            TNODE *p = T;
            if (T->pLeft == nullptr)
                T = T->pRight;
            else if (T->pRight == nullptr)
                T = T->pLeft;
            else
            {
                thayTheMinRight(p, T->pRight);
            }
            delete p;
        }
    }
}
// 11. Hàm thay thế Node xóa bằng Min Right.
void thayTheMinRight(TREE &p, TREE &T)
{
    if (T->pLeft != nullptr)
        thayTheMinRight(p, T->pLeft);
    else
    {
        p->key = T->key;
        p = T;
        T = T->pRight;
    }
}
// 12. Hàm thay thế Node xóa bằng Max Left
void thayTheMaxLeft(TREE &p, TREE &T)
{
    if (T->pRight != nullptr)
        thayTheMaxLeft(p, T->pRight);
    else
    {
        p->key = T->key;
        p = T;
        T = T->pLeft;
    }
}
// 13. Hàm tính chiều cao của cây.
int height(TNODE *T)
{
    if (T == nullptr)
        return -1;
    int a = height(T->pLeft);
    int b = height(T->pRight);
    return (a > b ? a : b) + 1;
}
// 14. Hàm đếm Node của cây.
int demNode(TNODE *T)
{
    if (T == nullptr)
        return 0;
    int a = demNode(T->pLeft);
    int b = demNode(T->pRight);
    return (a + b + 1);
}
// 15. Thêm N node vào cây.
void CreateTree(TREE &T)
{
    int soLuongNode;
    cin >> soLuongNode;
    int x;
    for (int i = 0; i < soLuongNode; i++)
    {
        cin >> x;
        insert(T, x);
    }
}
void PrintMenu()
{
    cout << "\n---------MENU BINARY SEARCH TREE--------\n";
    cout << "1.  Them N node vao cay\n";
    cout << "2.  Them 1 node (De quy)\n";
    cout << "3.  Xoa 1 node (Dung Min Right)\n";
    cout << "4.  Tim kiem (De quy)\n";
    cout << "5.  Duyet Inorder (LNR)\n";
    cout << "6.  Duyet Preorder (NLR)\n";
    cout << "7. Duyet Postorder (LRN)\n";
    cout << "8. Tim gia tri Min\n";
    cout << "9. Tim gia tri Max\n";
    cout << "10. Tinh chieu cao cay\n";
    cout << "11. Dem so luong node\n";
    cout << "0.  Thoat chuong trinh\n";
    cout << "------------------------------------------\n";
    cout << "Chon chuc nang: ";
}

int main()
{
    TREE T;
    CreateEmptyTree(T);
    int choice, x;
    TNODE *p = nullptr;
    while (true)
    {
        PrintMenu();
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Da giai phong cay. Tam biet!\n";
            return 0;
        case 1:
            CreateTree(T);
            cout << "Da them xong.\n";
            break;
        case 2:
            cout << "Nhap gia tri x can them: ";
            cin >> x;
            if (insert(T, x))
                cout << "Them thanh cong.\n";
            else
                cout << "Gia tri da ton tai.\n";
            break;
        case 3:
            cout << "Nhap gia tri x can xoa: ";
            cin >> x;
            deleteNode(T, x);
            cout << "Da xoa (neu ton tai).\n";
            break;
        case 4:
            cout << "Nhap gia tri x can tim: ";
            cin >> x;
            p = searchNodeRecursion(T, x);
            if (p)
                cout << "Tim thay node co gia tri " << p->key << "\n";
            else
                cout << "Khong tim thay " << x << "\n";
            break;
        case 5:
            cout << "Duyet Inorder (LNR): ";
            Inorder(T);
            cout << "\n";
            break;
        case 6:
            cout << "Duyet Preorder (NLR): ";
            Preorder(T);
            cout << "\n";
            break;
        case 7:
            cout << "Duyet Postorder (LRN): ";
            Postorder(T);
            cout << "\n";
            break;
        case 8:
            p = findMin(T);
            if (p)
                cout << "Gia tri Min: " << p->key << "\n";
            else
                cout << "Cay rong.\n";
            break;
        case 9:
            p = findMax(T);
            if (p)
                cout << "Gia tri Max: " << p->key << "\n";
            else
                cout << "Cay rong.\n";
            break;
        case 10:
            cout << "Chieu cao cua cay: " << height(T) << "\n";
            break;
        case 11:
            cout << "So luong node: " << demNode(T) << "\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
            break;
        }
    }
    return 0;
}