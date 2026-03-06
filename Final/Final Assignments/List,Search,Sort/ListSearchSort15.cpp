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
void Output(Hocsinh hs)
{
    cout << '[' << hs.Maso << "\t" << hs.Hoten << "\t" << hs.Gioitinh << "\t" << hs.Namsinh << "\t" << hs.TBK << "]\n";
}

int SelectionSort(Hocsinh[], int);

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
    cout << SelectionSort(ls, n) << endl;
    for (int i = 0; i < n; i++)
    {
        Output(ls[i]);
    }
    delete[] ls;
    return 0;
}

int SelectionSort(Hocsinh ls[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ls[j].Hoten < ls[minIndex].Hoten)
                minIndex = j;
        }
        if (i != minIndex)
        {
            swap(ls[i], ls[minIndex]);
            count += 2;
        }
    }
    return count;
}