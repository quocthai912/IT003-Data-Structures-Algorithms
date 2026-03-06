/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &A)
{
    int temp = -1;
    while (temp != 0)
    {
        cin >> temp;
        if (temp != 0)
            A.push_back(temp);
    }
}
void linearSearch(vector<int> A)
{
    int target;
    cin >> target;
    int count = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == target)
        {
            count++;
        }
    }
    cout << count;
}

int main()
{
    vector<int> A;
    Input(A);
    linearSearch(A);
    return 0;
}
