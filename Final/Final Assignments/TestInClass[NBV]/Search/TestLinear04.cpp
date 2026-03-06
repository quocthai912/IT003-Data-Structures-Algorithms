/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;
#include <unordered_map>

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
    int k;
    cin >> k;
    unordered_map<int, int> hashMap;
    for (int i = 0; i < A.size(); i++)
    {
        hashMap[A[i]]++;
    }
    bool found = false;
    for (int i = 0; i < A.size(); i++)
    {
        if (hashMap[A[i]] == k)
        {
            cout << A[i] << " ";
            hashMap[A[i]] = 0;
            found = true;
        }
    }
    if (!found)
        cout << "No Find";
}

int main()
{
    vector<int> A;
    Input(A);
    linearSearch(A);
    return 0;
}