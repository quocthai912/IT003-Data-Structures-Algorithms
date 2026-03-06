// Xóa Tất Cả Các Node Có Giá Trị Khóa Là Một Số Nguyên Tố
#include <iostream>
#include <vector>
using namespace std;
vector<int> primeNumbers;
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

bool isPrime(int key)
{
    if (key < 2)
        return false;
    for (int i = 2; i * i <= key; i++)
    {
        if (key % i == 0)
            return false;
    }
    return true;
}

void CreateTree(TREE &T)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        if (isPrime(temp))
            primeNumbers.push_back(temp);
        Insert(T, temp);
        cin >> temp;
    }
}

void SwapNode(TREE &T, TREE &Node)
{
    if (T->pLeft != nullptr)
        SwapNode(T->pLeft, Node);
    else
    {
        Node->key = T->key;
        Node = T;
        T = T->pRight;
    }
}
bool DeleteNode(TREE &T, int x)
{
    if (T == nullptr)
        return false;
    if (T->key < x)
        return DeleteNode(T->pRight, x);
    if (T->key > x)
        return DeleteNode(T->pLeft, x);
    if (T->key == x)
    {
        TNODE *node = T;
        if (T->pLeft != nullptr && T->pRight != nullptr)
        {
            SwapNode(T->pRight, node);
        }
        else if (T->pLeft == nullptr)
            T = T->pRight;
        else
            T = T->pLeft;
        delete node;
        return true;
    }
    return false;
}
void DeletePrimeNode(TREE &T)
{
    for (int i = 0; i < primeNumbers.size(); i++)
    {
        DeleteNode(T, primeNumbers[i]);
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
int main()
{
    TREE T;
    CreateEmptyTree(T);
    CreateTree(T);
    cout << "Binary Search Tree Truoc Khi Xoa Tat Ca Khoa So Nguyen To: " << endl;
    PrintTree(T);
    DeletePrimeNode(T);
    cout << endl
         << "Binary Search Tree Sau Khi Xoa Tat Ca Khoa So Nguyen To: " << endl;
    PrintTree(T);
    return 0;
}
