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

void AddHead(List &l, Hocsinh x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, Hocsinh x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node *RemoveHead(List &l)
{
    if (l.head == NULL)
        return NULL;
    Node *p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l)
{
    Node *p = l.head;
    while (p != NULL)
    {
        OutputElement(p->data);
        p = p->next;
    }
}

void Sort(List &);

int main()
{
    List l;
    int n;
    Hocsinh hs;

    CreateList(l);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        InputElement(hs);
        AddTail(l, hs);
    }

    Sort(l);
    PrintList(l);
    return 0;
}

// X < Y
bool SoSanhNgayThangNam(Hocsinh X, Hocsinh Y)
{
    if (X.Nam == Y.Nam)
    {
        if (X.Thang == Y.Thang)
        {
            return X.Ngay > Y.Ngay;
        }
        return X.Thang > Y.Thang;
    }
    return X.Nam > Y.Nam;
}

bool SoSanhHocSinh(Hocsinh X, Hocsinh Y)
{
    if (X.Ten == Y.Ten)
    {
        if (X.Hodem == Y.Hodem)
        {
            return SoSanhNgayThangNam(X, Y);
        }
        return X.Hodem < Y.Hodem;
    }
    return X.Ten < Y.Ten;
}
// Quick Sort để tối ưu
void Sort(List &l)
{
    if (l.head == nullptr || l.head->next == nullptr)
        return;
    Node *pivot = CreateNode(l.head->data);
    Node *p = l.head->next;
    List Before;
    List After;
    CreateList(Before);
    CreateList(After);
    while (p)
    {
        if (SoSanhHocSinh(p->data, pivot->data))
            AddTail(Before, p->data);
        else
            AddTail(After, p->data);
        p = p->next;
    }
    Sort(Before);
    Sort(After);
    if (Before.head == nullptr)
    {
        l.head = pivot;
    }
    else
    {
        l.head = Before.head;
        Before.tail->next = pivot;
    }
    if (After.head == nullptr)
    {
        l.tail = pivot;
    }
    else
    {
        pivot->next = After.head;
        l.tail = After.tail;
    }
}
