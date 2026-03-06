/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

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

void CreateEmptyHashTable(HASHTABLE &H)
{
    for (int i = 0; i < M; i++)
    {
        H[i] = nullptr;
    }
}
void InsertHashTable(HASHTABLE &H, int key, int numbucket)
{
    int index = HF(numbucket, key);
    AddTail(H[index], key);
}
void CreateHashTable(HASHTABLE &H, int &numbucket)
{
    CreateEmptyHashTable(H);
    cin >> numbucket;
    int x;
    cin >> x;
    while (x != -1)
    {
        InsertHashTable(H, x, numbucket);
        cin >> x;
    }
}
void Traverse(const HASHTABLE &H, int numbucket)
{
    for (int i = 0; i < numbucket; i++)
    {
        NODE *p = H[i];
        cout << i;
        if (p != nullptr)
            cout << " --> ";
        while (p)
        {
            cout << p->key;
            if (p->pNext != nullptr)
                cout << " --> ";
            p = p->pNext;
        }
        cout << endl;
    }
}
int main()
{
    HASHTABLE H;
    int numbucket;

    CreateHashTable(H, numbucket);
    Traverse(H, numbucket);

    return 0;
}
