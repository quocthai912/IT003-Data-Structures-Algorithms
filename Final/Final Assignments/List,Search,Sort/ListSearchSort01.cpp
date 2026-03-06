// Tính tổng dãy A theo danh sách các chỉ số nằm trong dãy B
// Không sử dụng mảng, vector
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
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

int keyIndex(DSLK l, int index)
{
    int count = 0;
    Node *p = l.pHead;
    while (p)
    {
        if (count == index)
            return p->key;
        count++;
        p = p->pNext;
    }
    // Không có Index này trong DSLK A
    return -1;
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
    int k;
    cin >> k;
    DSLK P;
    CreateEmptyDSLK(P);
    for (int i = 0; i < k; i++)
    {
        int key;
        cin >> key;
        AddTail(P, CreateNode(key));
    }
    int sum = 0;
    Node *p = P.pHead;
    while (p)
    {
        // Cộng vào tổng giá trị tại vị trí P[i]
        sum += keyIndex(A, p->key);
        p = p->pNext;
    }
    cout << sum;
    return 0;
}