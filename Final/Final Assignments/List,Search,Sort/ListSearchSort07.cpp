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
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x)
{
    getline(cin >> ws, x.Hodem);
    getline(cin >> ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs)
{
    cout << hs.Hodem
         << ' ' << hs.Ten
         << '\t' << hs.Gioitinh
         << '\t' << hs.Ngay
         << '/' << hs.Thang
         << '/' << hs.Nam
         << '\t' << hs.Toan
         << '\t' << hs.Van
         << '\t' << hs.Ly
         << '\t' << hs.Hoa
         << '\t' << hs.Anh
         << '\t' << hs.Sinh << endl;
    ;
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

void CreateList(List &l)
{
    l.head = l.tail = NULL;
}

Node *CreateNode(Hocsinh x)
{
    Node *p = new Node;
    if (p == NULL)
        exit(0);
    p->data = x;
    p->next = NULL;
    return p;
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

Node *FindLast(List, Hocsinh);

int main()
{
    List ds;
    int n;
    Hocsinh hs;

    CreateList(ds);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        InputElement(hs);
        AddTail(ds, hs);
    }
    InputElement(hs);
    Node *res = FindLast(ds, hs);
    if (res == NULL)
        cout << "NOT FOUND";
    else
        OutputElement(res->data);
    return 0;
}

Node *FindLast(List l, Hocsinh target)
{
    Node *p = l.head;
    Node *findHocSinh = nullptr;
    while (p)
    {
        if (p->data.Ten == target.Ten && p->data.Hodem == target.Hodem)
        {
            findHocSinh = p;
        }
        p = p->next;
    }
    return findHocSinh;
}
