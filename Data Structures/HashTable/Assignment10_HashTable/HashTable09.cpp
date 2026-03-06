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
void CreateEmptyHashTable(HASHTABLE &H, int numbucket)
{
    for (int i = 0; i < numbucket; i++)
        H[i] = nullptr;
}
void InsertHashTable(HASHTABLE &H, int numbucket, int key)
{
    int index = HF(numbucket, key);
    AddTail(H[index], key);
}
void CreateHashTable(HASHTABLE &H, int &numbucket)
{
    cin >> numbucket;
    CreateEmptyHashTable(H, numbucket);
    int x;
    cin >> x;
    while (x != -1)
    {
        InsertHashTable(H, numbucket, x);
        cin >> x;
    }
}
void Traverse(HASHTABLE H, int numbucket)
{
    for (int i = 0; i < numbucket; i++)
    {
        cout << i;
        if (H[i] != nullptr)
            cout << " --> ";
        NODE *p = H[i];
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
int Search(HASHTABLE H, int numbucket, int x)
{
    int index = HF(numbucket, x);
    NODE *p = H[index];
    if (p == nullptr)
        return -1;
    while (p)
    {
        if (p->key == x)
            return index;
        p = p->pNext;
    }
    return -1;
}
int main()
{
    HASHTABLE H;
    int numbucket;
    int x;

    CreateHashTable(H, numbucket);
    Traverse(H, numbucket);

    cin >> x;
    int i = Search(H, numbucket, x);
    cout << endl;
    if (i == -1)
        cout << x << " not found.";
    else
        cout << x << " found in bucket " << i << ".";
    return 0;
}
