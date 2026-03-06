/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
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
    int X;
    cin >> X;
    int value = -1;
    int khoangCach = -1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] < X)
        {
            khoangCach = X - A[i];
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
        if (A[i] < X)
        {
            if (X - A[i] < khoangCach)
            {
                khoangCach = X - A[i];
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