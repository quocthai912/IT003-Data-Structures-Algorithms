/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;
void decimal_to_binary(int &n)
{
    stack<int> st;
    while (n / 2 != 0)
    {
        st.push(n % 2);
        n /= 2;
    }
    st.push(n % 2);
    string result = "";
    while (!st.empty())
    {
        result += to_string(st.top());
        st.pop();
    }
    cout << result;
}

int main()
{
    int n;
    cin >> n;
    decimal_to_binary(n);
    return 0;
}
