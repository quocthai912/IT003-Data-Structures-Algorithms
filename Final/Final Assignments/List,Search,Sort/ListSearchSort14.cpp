/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>

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

void Output(vector<Hocsinh> ls, int n)
{
    cout << n << endl;
    for (int i = 0; i < ls.size(); i++)
    {
        OutputElement(ls[i]);
    }
}

void Input(vector<Hocsinh> &ls)
{
    int n;
    cin >> n;
    Hocsinh hs;
    for (int i = 0; i < n; i++)
    {
        InputElement(hs);
        ls.push_back(hs);
    }
}

int SelectionSort(vector<Hocsinh> &ls);

int main()
{
    vector<Hocsinh> ls;
    Input(ls);
    int n = SelectionSort(ls);
    Output(ls, n);
    return 0;
}

bool SoSanhHocSinh(Hocsinh x, Hocsinh y)
{
    if (x.Ten == y.Ten)
    {
        return x.Hodem < y.Hodem;
    }
    return x.Ten < y.Ten;
}

int SelectionSort(vector<Hocsinh> &ls)
{
    int countSwap = 0;
    for (int i = 0; i < ls.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < ls.size(); j++)
        {
            if (SoSanhHocSinh(ls[j], ls[minIndex]))
                minIndex = j;
        }
        if (i != minIndex)
        {
            swap(ls[i], ls[minIndex]);
            countSwap++;
        }
    }
    return countSwap;
}
