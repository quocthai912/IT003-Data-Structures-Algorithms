/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &A)
{
    int key;
    cin >> key;
    while (key != -1)
    {
        A.push_back(key);
        cin >> key;
    }
}

void SAPXEP(vector<int> &A)
{
    for (int i = 0; i < A.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[j] < A[minIndex])
                minIndex = j;
        }
        if (A[i] > A[minIndex])
            swap(A[i], A[minIndex]);
        cout << "i=" << i << ": min=" << minIndex << endl;
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
    SAPXEP(A);
    return 0;
}