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
    if (x.MSHS > 0)
        getline(cin >> ws, x.HoTen);
    else
    {
        x.HoTen = "";
    }

    cin >> x.Namsinh;
    if (x.MSHS > 0)
        cin >> x.Gioitinh;
    else
        x.Gioitinh = ' ';

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

int Delete(Hashtable &, int);

int main()
{
    Hashtable ht;
    int m, n;

    cin >> m >> n;
    ht.n = n;
    ht.M = m;
    for (int i = 0; i < m; i++)
    {
        InputElement(ht.table[i]);
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        cout << m << ' ' << Delete(ht, m) << endl;
    }

    cout << ht.n << endl;
    for (int i = 0; i < ht.M; i++)
    {
        cout << ht.table[i].MSHS << endl;
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

int Delete(Hashtable &ht, int MSHS)
{
    int nprob = 0;
    int index = HF(MSHS, ht.M);
    while (ht.table[index].MSHS != EMPTY && nprob < ht.M)
    {
        if (ht.table[index].MSHS == MSHS)
        {
            ht.table[index].MSHS = DELETED;
            ht.n--;
            return nprob + 1;
        }
        nprob++;
        index = HF2(MSHS, ht.M, nprob);
    }
    return -nprob;
}
