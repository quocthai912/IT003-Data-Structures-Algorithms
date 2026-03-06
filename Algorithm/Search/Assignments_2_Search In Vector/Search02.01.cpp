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
void binarySearch(vector<int> A)
{
    int target;
    cin >> target;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
    int count = 0;
    int left = 0;
    int right = A.size() - 1;
    while (left <= right)
    {
        count++;
        int mid = left + (right - left) / 2;
        if (A[mid] == target)
        {
            break;
        }
        else if (A[mid] < target)
        {
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << count;
}
int main()
{
    vector<int> A;
    Input(A);
    binarySearch(A);
    return 0;
}
