#include <bits/stdc++.h>
using namespace std;
bool checkSoDoiXung(int number)
{
    if (number < 10)
        return false;
    int check = number;
    int reverseNumber = 0;
    while (check > 0)
    {
        reverseNumber = reverseNumber * 10 + check % 10;
        check /= 10;
    }
    return reverseNumber == number;
}
void Input(vector<int> &A)
{
    int temp = -2;
    while (temp != -1)
    {
        cin >> temp;
        if (temp != -1)
            A.push_back(temp);
    }
}
void Find(vector<int> A)
{
    bool found = false;
    for (int i = 0; i < A.size(); i++)
    {
        if (checkSoDoiXung(A[i]))
        {
            cout << A[i] << " ";
            found = true;
        }
    }
    if (!found)
        cout << "NotFound";
}
int main()
{
    vector<int> A;
    Input(A);
    Find(A);
    return 0;
}
