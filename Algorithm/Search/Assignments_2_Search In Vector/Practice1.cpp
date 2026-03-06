#include <bits/stdc++.h>
using namespace std;
int MAX = 100;
bool check(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum == 9;
}
void Input(int A[], int &N)
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
}
void Find(int A[], int N)
{
    bool found = false;
    for (int i = N - 1; i >= 0; i--)
    {
        if (check(A[i]))
        {
            found = true;
            cout << A[i] << " ";
        }
    }
    if (!found)
        cout << "NotFound";
}
int main()
{
    int A[MAX], N;
    Input(A, N);
    Find(A, N);
    return 0;
}
