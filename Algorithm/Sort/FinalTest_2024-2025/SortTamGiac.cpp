#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
struct TamGiac
{
    int a, b, c;
};
bool tamGiacHopLe(TamGiac tg)
{
    return (tg.a + tg.b > tg.c) && (tg.c + tg.b > tg.a) && (tg.a + tg.c > tg.b);
}
double dienTichTamGiac(TamGiac tg)
{
    double p = (tg.a + tg.b + tg.c) / 2.0;
    return sqrt(p * (p - tg.a) * (p - tg.b) * (p - tg.c));
}
void QuickSort(vector<TamGiac> &danhSach, int left, int right)
{
    if (left >= right)
        return;
    TamGiac pivot = danhSach[(left + right) / 2];
    int i = left;
    int j = right;
    while (i < j)
    {
        while (dienTichTamGiac(danhSach[i]) > dienTichTamGiac(pivot))
        {
            i++;
        }
        while (dienTichTamGiac(danhSach[j]) < dienTichTamGiac(pivot))
        {
            j--;
        }
        if (i <= j)
        {
            TamGiac temp = danhSach[i];
            danhSach[i] = danhSach[j];
            danhSach[j] = temp;
            i++;
            j--;
        }
    }
    QuickSort(danhSach, left, j);
    QuickSort(danhSach, i, right);
}
int main()
{
    int size;
    cin >> size;
    vector<TamGiac> danhSach(size);
    for (int i = 0; i < size; i++)
    {
        cin >> danhSach[i].a >> danhSach[i].b >> danhSach[i].c;
    }
    vector<TamGiac> hopLe;
    for (int i = 0; i < size; i++)
    {
        if (tamGiacHopLe(danhSach[i]))
        {
            hopLe.push_back(danhSach[i]);
        }
    }
    if (!hopLe.empty())
    {
        QuickSort(hopLe, 0, hopLe.size() - 1);
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (tamGiacHopLe(danhSach[i]))
            {
                danhSach[i] = hopLe[count++];
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << danhSach[i].a << " " << danhSach[i].b << " " << danhSach[i].c << endl;
    }
    return 0;
}