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
        int maxIndex = i;
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[j] > A[maxIndex])
                maxIndex = j;
        }
        cout << "i=" << i << ": swap (" << A[i] << "-" << A[maxIndex] << ")" << endl;
        swap(A[i], A[maxIndex]);
    }
}

int main()
{
    vector<int> A;
    Input(A);
    SAPXEP(A);
    return 0;
}
