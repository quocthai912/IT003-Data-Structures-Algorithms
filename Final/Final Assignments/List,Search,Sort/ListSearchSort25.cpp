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

void Output(List ds)
{
    Node *p = ds.head;
    if (p == NULL)
    {
        cout << "EMPTY";
    }
    while (p != NULL)
    {
        OutputElement(p->data);
        p = p->next;
    }
}

Node *CreateNode(const Hocsinh &x)
{
    Node *p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

void AddTail(List &l, const Hocsinh &x)
{
    Node *p = CreateNode(x);
    if (l.head == nullptr)
        l.head = l.tail = p;
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

double diemTrungBinh(const Hocsinh &x)
{
    return (x.Toan + x.Van + x.Ly + x.Hoa + x.Anh + x.Sinh) / 6.0;
}

int main()
{
    int n;
    cin >> n;
    List hs;
    hs.head = hs.tail = nullptr;
    for (int i = 0; i < n; i++)
    {
        Hocsinh x;
        InputElement(x);
        if (diemTrungBinh(x) >= 9.0)
            AddTail(hs, x);
    }
    Output(hs);
    return 0;
}
