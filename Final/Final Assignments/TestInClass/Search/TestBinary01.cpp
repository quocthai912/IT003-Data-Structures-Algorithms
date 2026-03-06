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
        A.push_back(temp);
        cin >> temp;
    }
}

void binarySearch(vector<int> A)
{
    sort(A.begin(), A.end(), greater<int>());
    int target;
    cin >> target;
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    int left = 0;
    int right = A.size() - 1;
    int count = 0;
    while (left <= right)
    {
        count++;
        int mid = left + (right - left) / 2;
        cout << "Left=" << left << " " << "Right=" << right << " " << "Mid=" << mid << endl;
        if (A[mid] == target)
            break;
        else if (A[mid] < target)
            right = mid - 1;
        else
            left = mid + 1;
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
