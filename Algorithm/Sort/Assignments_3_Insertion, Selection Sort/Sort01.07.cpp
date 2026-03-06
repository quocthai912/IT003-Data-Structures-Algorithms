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
void selectionSort(vector<int> &A)
{
    for (int i = 0; i < A.size() - 1; i++)
    {
        int maxIndex = i;
        cout << "i=" << i << ": ";
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[j] > A[maxIndex])
            {
                maxIndex = j;
            }
        }
        if (A[i] < A[maxIndex])
        {
            swap(A[i], A[maxIndex]);
        }
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
    selectionSort(A);
    return 0;
}
