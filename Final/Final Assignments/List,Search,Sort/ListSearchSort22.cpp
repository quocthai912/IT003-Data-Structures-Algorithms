/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/
#include <iostream>

using namespace std;

struct Hocsinh
{
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};
void Input(Hocsinh &x)
{
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
void Output(Hocsinh hs)
{
    cout << '[' << hs.Maso << "\t" << hs.Hoten << "\t" << hs.Gioitinh << "\t" << hs.Namsinh << "\t" << hs.TBK << "]\n";
}

struct Node
{
    Hocsinh data;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

Node *CreateNode(Hocsinh x)
{
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l)
{
    l.head = l.tail = NULL;
}

void AddTail(List &l, Hocsinh x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void DeleteIndex(List &l, int i);

int main()
{
    int n, m, index;
    Hocsinh hs;
    List l;
    CreateList(l);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Input(hs);
        AddTail(l, hs);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> index;
        DeleteIndex(l, index);
    }

    Node *p = l.head;
    while (p != NULL)
    {
        Output(p->data);
        p = l.head->next;
        delete l.head;
        l.head = p;
    }

    return 0;
}

void DeleteIndex(List &l, int i)
{
    int index = 0;
    Node dummyNode;
    dummyNode.next = nullptr;
    dummyNode.next = l.head;
    Node *curr = &dummyNode;
    while (curr)
    {
        if (index == i)
        {
            Node *p = curr->next;
            curr->next = curr->next->next;
            delete p;
        }
        index++;
        curr = curr->next;
    }
    l.head = dummyNode.next;
}
