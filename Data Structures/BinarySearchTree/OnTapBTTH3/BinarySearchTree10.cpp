// Liệt Kê Các Node Có Chiều Cao = Độ Sâu Theo Thứ Tự Duyệt Inorder.
// Có Thể Tối Ưu Bằng Cách Sử Dụng Map Để Lưu Trữ Chiều Cao Của Từng Node Và Truy Xuất O(1) Hay Vì Phải Tính Lại Nhiều Lần.
// Độ Phức Tạp Hiện Tại O(N^2)
// Sử Dụng Map O(N) => Nếu Số Node > 10000
#include <iostream>
#include <queue>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

TNODE *CreateTNODE(int key)
{
    TNODE *T = new TNODE;
    T->key = key;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
}
bool Insert(TREE &T, int key)
{
    if (T)
    {
        if (T->key == key)
            return false;
        else if (T->key < key)
            return Insert(T->pRight, key);
        else
            return Insert(T->pLeft, key);
    }
    T = CreateTNODE(key);
    return true;
}
void CreateEmptyTree(TREE &T)
{
    T = nullptr;
}
void CreateTree(TREE &T)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        Insert(T, temp);
        cin >> temp;
    }
}
int Height(TREE T)
{
    if (T == nullptr)
        return -1;
    int left = Height(T->pLeft);
    int right = Height(T->pRight);
    return (left > right ? left : right) + 1;
}
void ChieuCaoBangDoSau(TREE T, int level, bool &find)
{
    if (T == nullptr)
        return;
    ChieuCaoBangDoSau(T->pLeft, level + 1, find);
    int heightNode = Height(T);
    if (heightNode == level)
    {
        cout << T->key << " ";
        find = true;
    }
    ChieuCaoBangDoSau(T->pRight, level + 1, find);
}
void PrintTree(TREE T)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    bool find = false;
    ChieuCaoBangDoSau(T, 0, find);
    if (!find)
    {
        cout << "NotFound";
    }
}
int main()
{
    TREE T;
    CreateEmptyTree(T);
    CreateTree(T);
    PrintTree(T);
    return 0;
}
