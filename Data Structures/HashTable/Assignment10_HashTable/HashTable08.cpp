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

void InitHashTable(HASHTABLE &H, int numbucket)
{
    for (int i = 0; i < numbucket; i++)
        H[i] = NULL;
}

void TraverseBucket(HASHTABLE H, int i)
{
    NODEPTR p = H[i];
    while (p != NULL)
    {
        cout << " --> " << p->key;
        p = p->pNext;
    }
}
void Traverse(HASHTABLE H, int numbucket)
{
    for (int i = 0; i < numbucket; i++)
    {
        cout << i;
        TraverseBucket(H, i);
        cout << endl;
    }
}
void Insert(HASHTABLE &H, int numbucket, int key)
{
    int index = HF(numbucket, key);
    AddTail(H[index], key);
}
void CreateHashTable(HASHTABLE &H, int &numbucket)
{
    cin >> numbucket;
    InitHashTable(H, numbucket);
    int x;
    cin >> x;
    while (x != -1)
    {
        Insert(H, numbucket, x);
        cin >> x;
    }
}
bool Remove(HASHTABLE &H, int numbucket, int x)
{
    int index = HF(numbucket, x);
    NODE *p = H[index];
    if (p == nullptr)
        return 0;
    if (p->key == x)
    {
        H[index] = H[index]->pNext;
        delete p;
        return 1;
    }
    while (p->pNext)
    {
        if (p->pNext->key == x)
        {
            NODE *q = p->pNext;
            p->pNext = q->pNext;
            delete q;
            return 1;
        }
        p = p->pNext;
    }
    return 0;
}
int main()
{
    HASHTABLE H;
    int numbucket;
    int x;

    CreateHashTable(H, numbucket);

    Traverse(H, numbucket);

    cin >> x;
    if (Remove(H, numbucket, x))
    {
        cout << endl
             << x << ": Delete Successful." << endl
             << endl;
        Traverse(H, numbucket);
    }
    else
        cout << endl
             << x << ": Delete Failed." << endl
             << endl;

    return 0;
}
