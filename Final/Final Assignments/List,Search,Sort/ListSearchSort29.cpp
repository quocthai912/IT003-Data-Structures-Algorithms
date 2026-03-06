/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>

#define MAX 10000

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

int BSearch(Hocsinh[], int, Hocsinh);

int main()
{
    Hocsinh ds[MAX], hs;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        InputElement(hs);
        ds[i] = hs;
    }
    InputElement(hs);
    cout << BSearch(ds, n, hs) << endl;
    return 0;
}

bool SoSanhNgayThangNam(const Hocsinh &x, const Hocsinh &y)
{
    if (x.Nam == y.Nam)
    {
        if (x.Thang == y.Thang)
        {
            return x.Ngay > y.Ngay;
        }
        else
            return x.Thang > y.Thang;
    }
    return x.Nam > y.Nam;
}

bool SoSanhHocSinh(const Hocsinh &x, const Hocsinh &y)
{
    if (x.Ten == y.Ten)
    {
        if (x.Hodem == y.Hodem)
            return SoSanhNgayThangNam(x, y);
        else
            return x.Hodem < y.Hodem;
    }
    return x.Ten < y.Ten;
}

bool SoSanhBang(const Hocsinh &x, const Hocsinh &y)
{
    return x.Ten == y.Ten && x.Hodem == y.Hodem && x.Nam == y.Nam && x.Thang == y.Thang && x.Ngay == y.Ngay;
}

int BSearch(Hocsinh hs[], int n, Hocsinh target)
{
    int soLanDuyet = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        soLanDuyet++;
        if (SoSanhBang(hs[mid], target))
            return soLanDuyet;
        else if (SoSanhHocSinh(hs[mid], target))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}