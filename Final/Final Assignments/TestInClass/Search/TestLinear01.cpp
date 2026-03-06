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
    int target;
    cin >> target;
    int first = -1;
    int last = -1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == target)
        {
            if (first == -1)
                first = i;
            last = i;
        }
    }
    if (first != -1)
    {
        cout << first << " " << last;
    }
    else
        cout << "No Find";
}

int main()
{
    vector<int> A;
    Input(A);
    linearSearch(A);
    return 0;
}
