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

void binarySearch(vector<int> A)
{
    int target;
    cin >> target;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    int left = 0;
    int right = A.size() - 1;
    bool timThay = false;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        cout << "[" << left << "-" << right << "]" << " ";
        if (A[mid] == target)
        {
            timThay = true;
            break;
        }
        else if (A[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << endl;
    if (timThay)
        cout << "Found";
    else
        cout << "NotFound";
}

int main()
{
    vector<int> A;
    Input(A);
    binarySearch(A);
    return 0;
}
