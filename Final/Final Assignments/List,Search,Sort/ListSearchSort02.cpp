// Tương tự như bài hồi nãy
// Chỉ sử dụng DSLK
#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *pNext;
};

Node *CreateNode(int key)
{
    Node *p = new Node;
    p->key = key;
    p->pNext = nullptr;
    return p;
}

struct DSLK
{
    Node *pHead;
    Node *pTail;
};

void CreateEmptyDSLK(DSLK &l)
{
    l.pHead = l.pTail = nullptr;
}

void AddTail(DSLK &l, Node *p)
{
    if (l.pHead == nullptr)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
// Sử dụng Quick Sort tăng tốc độ rất nhiều
// 0.15s cho Selection Sort
// 0.02s cho Quick Sort
void QuickSortDSLK(DSLK &A)
{
    // Nếu chỉ còn 1 phần tử hoặc NULL, ta tính là đã sắp xếp
    if (A.pHead == nullptr || A.pHead->pNext == nullptr)
        return;
    // Pivot là Node đầu tiên
    Node *Pivot = CreateNode(A.pHead->key);
    Node *p = A.pHead->pNext;
    DSLK Before;
    DSLK After;
    CreateEmptyDSLK(Before);
    CreateEmptyDSLK(After);
    while (p)
    {
        if (p->key > Pivot->key)
        {
            // Sắp xếp giảm dần
            AddTail(Before, CreateNode(p->key));
        }
        else
        {
            AddTail(After, CreateNode(p->key));
        }
        p = p->pNext;
    }
    QuickSortDSLK(Before);
    QuickSortDSLK(After);
    // Tiến hành nối
    // Nối Before
    if (Before.pHead == nullptr)
    {
        A.pHead = Pivot;
    }
    else
    {
        A.pHead = Before.pHead;
        Before.pTail->pNext = Pivot;
    }
    // Nối After
    if (After.pHead == nullptr)
    {
        A.pTail = Pivot;
    }
    else
    {
        Pivot->pNext = After.pHead;
        A.pTail = After.pTail;
    }
}

int main()
{
    int n;
    cin >> n;
    DSLK A;
    CreateEmptyDSLK(A);
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        AddTail(A, CreateNode(key));
    }
    // Sắp xếp DSLK
    QuickSortDSLK(A);
    // Nếu vị trí chẵn, cộng vào tổng
    int sum = 0;
    int index = 0;
    Node *p = A.pHead;
    while (p)
    {
        if (index % 2 == 0)
            sum += p->key;
        index++;
        p = p->pNext;
    }
    cout << sum;
    return 0;
}
