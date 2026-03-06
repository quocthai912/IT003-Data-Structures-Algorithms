/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>

using namespace std;

void QuickSort(int[], int, int);

int main()
{
    int *ls = NULL;
    int n;
    cin >> n;
    ls = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ls[i];
    }
    QuickSort(ls, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << ls[i] << ' ';
    }
    delete[] ls;
    return 0;
}

void QuickSort(int ls[], int b, int e)
{
    if (b >= e)
        return;
    int pivot = ls[b + (e - b) / 2];
    int i = b;
    int j = e;
    while (i <= j)
    {
        while (ls[i] < pivot)
            i++;
        while (ls[j] > pivot)
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
