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

void Output(vector<Hocsinh> ls)
{
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

void Sort(vector<Hocsinh> &ls);

int main()
{
    vector<Hocsinh> ls;
    Input(ls);
    Sort(ls);
    Output(ls);
    return 0;
}

double TinhDiemTrungBinh(Hocsinh &hs)
{
    return (hs.Toan + hs.Ly + hs.Hoa + hs.Van + hs.Sinh + hs.Anh) / 6.0;
}

bool SoSanhTuoi(Hocsinh &hs1, Hocsinh &hs2)
{
    if (hs1.Nam == hs2.Nam)
    {
        if (hs1.Thang == hs2.Thang)
            return hs1.Ngay > hs2.Ngay;
        else
            return hs1.Thang > hs2.Thang;
    }
    return hs1.Nam > hs2.Nam;
}

bool SoSanhHocSinh(Hocsinh &hs1, Hocsinh &hs2)
{
    if (TinhDiemTrungBinh(hs1) == TinhDiemTrungBinh(hs2))
    {
        return SoSanhTuoi(hs2, hs1);
    }
    return TinhDiemTrungBinh(hs1) < TinhDiemTrungBinh(hs2);
}

void InsertionSort(vector<Hocsinh> &ls)
{
    for (int i = 1; i < ls.size(); i++)
    {
        int j = i - 1;
        Hocsinh key = ls[i];
        while (j >= 0 && SoSanhHocSinh(ls[j], key))
        {
            ls[j + 1] = ls[j];
            j--;
        }
        ls[j + 1] = key;
    }
}

void Sort(vector<Hocsinh> &ls)
{
    InsertionSort(ls);
}
