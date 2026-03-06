// Tìm Key Có Giá Trị Lớn Nhất Trong Bảng Băm.
// Tìm Key Có Giá Trị Nhỏ Nhất Trong Bảng Băm.
// Có Template
#include <iostream>
using namespace std;
#define M 100

struct NODE
{
    int key;
    NODE *pNext;
};
// Khai báo kiểu con trỏ chỉ node
typedef NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];

NODE *CreateNode(int x)
{
    NODE *p;
    p = new NODE;
    p->key = x;
    p->pNext = NULL;
    return p;
}
void AddTail(NODE *&head, int x)
{
    NODE *p = CreateNode(x);
    if (head == NULL)
        head = p;
    else
    {
        NODE *i = head;
        while (i->pNext != NULL)
        {
            i = i->pNext;
        }
        i->pNext = p;
    }
}

int HF(int numbucket, int key) { return key % numbucket; }

void CreateEmptyHashTable(HASHTABLE &H, int &numbucket)
{
    cin >> numbucket;
    for (int i = 0; i < numbucket; i++)
    {
        H[i] = nullptr;
    }
}
void Insert(HASHTABLE &H, int key, int numbucket)
{
    int index = HF(numbucket, key);
    AddTail(H[index], key);
}
void CreateHashTable(HASHTABLE &H, int &numbucket)
{
    CreateEmptyHashTable(H, numbucket);
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        Insert(H, temp, numbucket);
        cin >> temp;
    }
}
void FindMinMax(HASHTABLE H, int &minKey, int &maxKey, int numbucket)
{
    // Tim so dau tien gan cho Min, Max
    for (int i = 0; i < numbucket; i++)
    {
        NODE *p = H[i];
        if (p != nullptr)
        {
            minKey = maxKey = p->key;
            break;
        }
    }
    // Tim Max
    for (int i = 0; i < numbucket; i++)
    {
        NODE *p = H[i];
        if (p != nullptr)
        {
            while (p)
            {
                if (p->key > maxKey)
                    maxKey = p->key;
                p = p->pNext;
            }
        }
    }
    // Tim Min
    for (int i = 0; i < numbucket; i++)
    {
        NODE *p = H[i];
        if (p != nullptr)
        {
            while (p)
            {
                if (p->key < minKey)
                    minKey = p->key;
                p = p->pNext;
            }
        }
    }
}
void Traverse(HASHTABLE H, int numbucket)
{
    int maxKey;
    int minKey;
    FindMinMax(H, minKey, maxKey, numbucket);
    for (int i = 0; i < numbucket; i++)
    {
        cout << i;
        NODE *p = H[i];
        if (p != nullptr)
        {
            cout << " --> ";
            while (p)
            {
                cout << p->key << " ";
                if (p->pNext != nullptr)
                    cout << "--> ";
                p = p->pNext;
            }
        }
        cout << endl;
    }
    cout << "MAX: " << maxKey << endl;
    cout << "MIN: " << minKey << endl;
}
int main()
{
    HASHTABLE H;
    int numbucket;

    CreateHashTable(H, numbucket);
    Traverse(H, numbucket);

    return 0;
}
