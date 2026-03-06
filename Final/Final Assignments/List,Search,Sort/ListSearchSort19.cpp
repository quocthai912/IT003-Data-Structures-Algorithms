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
// Stable Sort
bool SoSanhHocSinh(Hocsinh &x, Hocsinh &y)
{
    return x.Ten <= y.Ten;
}

void Merge(vector<Hocsinh> &ls, int left, int mid, int right)
{
    int sizeLeft = (mid - left) + 1;
    int sizeRight = right - mid;
    vector<Hocsinh> arrayLeft(sizeLeft);
    vector<Hocsinh> arrayRight(sizeRight);
    for (int i = 0; i < sizeLeft; i++)
    {
        arrayLeft[i] = ls[left + i];
    }
    for (int i = 0; i < sizeRight; i++)
    {
        arrayRight[i] = ls[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < sizeLeft && j < sizeRight)
    {
        if (SoSanhHocSinh(arrayLeft[i], arrayRight[j]))
            ls[k++] = arrayLeft[i++];
        else
            ls[k++] = arrayRight[j++];
    }
    while (i < sizeLeft)
        ls[k++] = arrayLeft[i++];
    while (j < sizeRight)
        ls[k++] = arrayRight[j++];
}

void MergeSort(vector<Hocsinh> &ls, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    MergeSort(ls, left, mid);
    MergeSort(ls, mid + 1, right);
    Merge(ls, left, mid, right);
}

void Sort(vector<Hocsinh> &ls)
{
    MergeSort(ls, 0, ls.size() - 1);
}
