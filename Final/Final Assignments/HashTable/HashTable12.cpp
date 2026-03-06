/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>

#define MAX 10000
#define EMPTY 0
#define NIL 0
#define DELETED -1

using namespace std;

struct Hocsinh
{
    int MSHS;
    string HoTen;
    int Namsinh;
    char Gioitinh;
    double Toan, Ly, Hoa, Anh;
};

struct Hashtable
{
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh table[MAX];
};

void InputElement(Hocsinh &x)
{
    cin >> x.MSHS;
    getline(cin >> ws, x.HoTen);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.Toan;
    cin >> x.Ly;
    cin >> x.Hoa;
    cin >> x.Anh;
}

void OutputElement(Hocsinh x)
{
    cout << x.MSHS << endl
         << x.HoTen << endl
         << x.Namsinh << endl
         << x.Gioitinh << endl
         << x.Toan << endl
         << x.Ly << endl
         << x.Hoa << endl
         << x.Anh << endl;
}

void CreateHashtable(Hashtable &, int, Hocsinh[], int);

int main()
{
    Hashtable ht;
    Hocsinh ds[MAX];
    int m, n;

    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        InputElement(ds[i]);
    }

    CreateHashtable(ht, m, ds, n);

    cout << ht.M << ' ' << ht.n << endl;
    for (int i = 0; i < ht.M; i++)
    {
        OutputElement(ht.table[i]);
    }

    return 0;
}

int HF(int MSHS, int M)
{
    return MSHS % M;
}

int HF2(int MSHS, int M, int i)
{
    return (HF(MSHS, M) + i * i) % M;
}

void CreateEmptyHashTable(Hashtable &ht, int M)
{
    for (int i = 0; i < M; i++)
    {
        ht.table[i].Anh = 0.0;
        ht.table[i].Gioitinh = ' ';
        ht.table[i].Hoa = 0.0;
        ht.table[i].HoTen = " ";
        ht.table[i].Ly = 0.0;
        ht.table[i].MSHS = EMPTY;
        ht.table[i].Namsinh = 0;
        ht.table[i].Toan = 0.0;
    }
    ht.M = M;
    ht.n = 0;
}

void InsertHashTable(Hashtable &ht, Hocsinh x)
{
    int index = HF(x.MSHS, ht.M);
    int i = 0;
    while (ht.table[index].MSHS != EMPTY && i < ht.M)
    {
        i++;
        index = HF2(x.MSHS, ht.M, i);
    }
    if (i >= ht.M)
        return;
    ht.table[index] = x;
    ht.n++;
}

void CreateHashtable(Hashtable &ht, int M, Hocsinh ds[], int N)
{
    CreateEmptyHashTable(ht, M);
    for (int i = 0; i < N; i++)
    {
        InsertHashTable(ht, ds[i]);
    }
}
