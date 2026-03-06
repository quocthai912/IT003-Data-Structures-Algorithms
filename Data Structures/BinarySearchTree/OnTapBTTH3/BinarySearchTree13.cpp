// In Ra Tất Cả Các Mức Của Cây Và Các Node Tương Ứng Trên Mức Đó.
// In Ra Mức Có Tổng Khóa Cao Nhất Và Tổng Khóa Tương Ứng.
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
void Preorder(TREE T)
{
    if (T == nullptr)
        return;
    cout << T->key << " ";
    Preorder(T->pLeft);
    Preorder(T->pRight);
}
void PrintTree(TREE T)
{
    if (T == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    Preorder(T);
}
void MaxSumKeyLevel(TREE T)
{
    if (T == nullptr)
        return;
    queue<TNODE *> q;
    q.push(T);
    int maxLevel = -1;
    int Level = 0;
    int sum = 0;
    int maxSum = -1;
    while (!q.empty())
    {
        int size = q.size();
        cout << "[LEVEL " << Level << "]: ";
        for (int i = 0; i < size; i++)
        {
            TNODE *T = q.front();
            q.pop();
            cout << T->key << " ";
            sum += T->key;
            if (T->pLeft != nullptr)
                q.push(T->pLeft);
            if (T->pRight != nullptr)
                q.push(T->pRight);
        }
        cout << endl;
        if (sum > maxSum)
        {
            maxLevel = Level;
            maxSum = sum;
        }
        Level++;
        sum = 0;
    }
    cout << "[LEVEL] co tong khoa lon nhat la: " << maxLevel << endl;
    cout << "Tong khoa: " << maxSum;
}
int main()
{
    TREE T;
    CreateEmptyTree(T);
    CreateTree(T);
    cout << "Binary Search Tree: ";
    PrintTree(T);
    cout << endl;
    MaxSumKeyLevel(T);
    return 0;
}
