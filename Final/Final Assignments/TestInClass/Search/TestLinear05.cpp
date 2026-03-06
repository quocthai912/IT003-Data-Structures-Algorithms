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
    while (key != 0)
    {
        A.push_back(key);
        cin >> key;
    }
}

void linearSearch(vector<int> A)
{
    int target;
    cin >> target;
    int khoangCach = -1;
    int value = -1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > target)
        {
            khoangCach = A[i] - target;
            value = A[i];
            break;
        }
    }
    if (value == -1)
    {
        cout << "No Find";
        return;
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > target)
        {
            if (A[i] - target < khoangCach)
            {
                khoangCach = A[i] - target;
                value = A[i];
            }
        }
    }
    cout << value;
}

int main()
{
    vector<int> A;
    Input(A);
    linearSearch(A);
    return 0;
}
