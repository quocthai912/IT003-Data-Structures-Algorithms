/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &A)
{
    int temp;
    cin >> temp;
    while (temp != 0)
    {
        if (temp != 0)
        {
            A.push_back(temp);
            cin >> temp;
        }
    }
}
void insertionSort(vector<int> &A)
{
    for (int i = 1; i < A.size(); i++)
    {
        int e = A[i];
        cout << "i=" << i << ":" << " e=" << e << ": ";
        int j = i - 1;
        while (j >= 0 && A[j] < e)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = e;
        for (int k = 0; k < A.size(); k++)
        {
            cout << A[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> A;
    Input(A);
    insertionSort(A);
    return 0;
}
