/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
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
void OutputCompact(Hocsinh hs)
{
    cout << hs.Hoten << "\n";
}

void OutputFull(Hocsinh hs)
{
    cout << '[' << hs.Maso << "\t" << hs.Hoten << "\t" << hs.Gioitinh << "\t" << hs.Namsinh << "\t" << hs.TBK << "]\n";
}

void QuickSort(Hocsinh[], int, int);

int main()
{
    Hocsinh *ls = NULL;
    int n;
    cin >> n;
    ls = new Hocsinh[n];
    for (int i = 0; i < n; i++)
    {
        Input(ls[i]);
    }
    QuickSort(ls, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        OutputCompact(ls[i]);
    }
    delete[] ls;
    return 0;
}

void QuickSort(Hocsinh ls[], int b, int e)
{
    if (b >= e)
        return;
    int i = b;
    int j = e;
    string pivot = ls[b + (e - b) / 2].Hoten;
    while (i <= j)
    {
        while (ls[i].Hoten < pivot)
            i++;
        while (ls[j].Hoten > pivot)
            j--;
        if (i <= j)
        {
            swap(ls[i], ls[j]);
            i++;
            j--;
        }
    }
    QuickSort(ls, b, j);
    QuickSort(ls, i, e);
}
