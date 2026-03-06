// Liệt kê các Node có chiều cao lớn hơn H
#include <iostream>
#include <unordered_map>
using namespace std;
struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;
unordered_map<TNODE *, int> HashTable;
TNODE *CreateTNODE(int key)
{
    TNODE *T = new TNODE;
    T->key = key;
    T->pLeft = nullptr;
    T->pRight = nullptr;
    return T;
}
bool InsertTree(TREE &T, int key)
{
    if (T)
    {
        if (T->key == key)
            return false;
        else if (T->key < key)
            return InsertTree(T->pRight, key);
        else
            return InsertTree(T->pLeft, key);
    }
    T = CreateTNODE(key);
    return true;
}
void CreateTree(TREE &T)
{
    T = nullptr;
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        InsertTree(T, temp);
        cin >> temp;
    }
}
int Height(TREE T)
{
    if (T == nullptr)
        return -1;
    int left = Height(T->pLeft);
    int right = Height(T->pRight);
    int height = max(left, right) + 1;
    // Lưu vào Hash Table
    HashTable[T] = height;
    return height;
}
void PrintNode(TREE T, int H, bool &find)
{
    if (T == nullptr)
        return;
    PrintNode(T->pLeft, H, find);
    if (HashTable[T] > H)
    {
        cout << T->key << " ";
        find = true;
    }
    PrintNode(T->pRight, H, find);
}
void PrintTree(TREE T, int H)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    bool find = false;
    // Phải gọi Height trước để tính chiều cao cho toàn bộ Node
    Height(T);
    PrintNode(T, H, find);
    if (!find)
    {
        cout << "NotFound";
    }
}
int main()
{
    int H;
    cin >> H;
    TREE T;
    CreateTree(T);
    PrintTree(T, H);
    return 0;
}
