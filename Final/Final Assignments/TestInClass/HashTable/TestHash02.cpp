/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
template
class
typedef
vector
pair
set
map
exit
###End banned keyword*/

#include <iostream>
using namespace std;
#define LOAD 0.7

struct Node
{
    int key;
    Node *next;
};
struct List
{
    Node *head;
    Node *tail;
};

struct Hashtable
{
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List *table;
};

Node *CreateNode(int x)
{
    Node *p = new Node;
    p->key = x;
    p->next = NULL;
    return p;
}

void AddTail(List &l, int x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void CreateEmptyList(List &l)
{
    l.head = NULL;
    l.tail = NULL;
}

void CreateEmptyHashtable(Hashtable &ht, int &m)
{
    cin >> m;
    ht.table = new List[m];
    for (int i = 0; i < m; i++)
        CreateEmptyList(ht.table[i]);
    ht.M = m;
    ht.n = 0;
}

int HF(int key, int M)
{
    return key % M;
}

void InsertHashTable(Hashtable &ht, int key)
{
    int index = HF(key, ht.M);
    AddTail(ht.table[index], key);
    ht.n++;
}

void InputHashtable(Hashtable &ht)
{
    int key;
    cin >> key;
    while (key != -1)
    {
        InsertHashTable(ht, key);
        cin >> key;
    }
}

void OutputHashtable(Hashtable ht)
{
    bool found = false;
    for (int i = 0; i < ht.M; i++)
    {
        cout << i << " --> ";
        Node *p = ht.table[i].head;
        if (p == nullptr)
        {
            cout << "NULL";
            found = true;
        }
        else
        {
            while (p)
            {
                cout << p->key;
                if (p->next != nullptr)
                {
                    cout << " --> ";
                }
                p = p->next;
            }
        }
        cout << endl;
    }
    if (!found)
    {
        cout << "NotFound";
        return;
    }
    cout << "Bucket has not key" << endl;
    for (int i = 0; i < ht.M; i++)
    {
        Node *p = ht.table[i].head;
        if (p == nullptr)
        {
            cout << i << " --> NULL" << endl;
        }
    }
}

int main()
{
    Hashtable H;
    int M, x;
    CreateEmptyHashtable(H, M);
    InputHashtable(H);
    OutputHashtable(H);
    return 0;
}
