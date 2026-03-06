/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
template
class
typedef
vector
pair
set
map
exit
[
]
###End banned keyword*/
#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
bool LinearSearch(stack<int> s, int X)
{
    while (!s.empty())
    {
        if (s.top() == X)
            return true;
        s.pop();
    }
    return false;
}
void Input(stack<int> &s)
{
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        if (!LinearSearch(s, temp) && isPrime(temp))
            s.push(temp);
        cin >> temp;
    }
}
void Output(stack<int> s)
{
    if (s.empty())
    {
        cout << "No SNT";
        return;
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    stack<int> s;
    Input(s);
    Output(s);
    return 0;
}
