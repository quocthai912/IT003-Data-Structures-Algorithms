// Bai qua quen thuoc
#include <bits/stdc++.h>
using namespace std;
void Fun(string st, stack<string> &s)
{
    for (int i = 0; i < st.length(); i++)
    {
        if (st[i] == '(')
        {
            string pushStack = "";
            pushStack += st[i];
            s.push(pushStack);
        }
        else if (st[i] == ')')
        {
            if (s.empty())
            {
                s.push("false");
                return;
            }
            else
            {
                s.pop();
            }
        }
    }
}
int main()
{
    stack<string> s;
    string st;
    getline(cin, st);
    Fun(st, s);
    if (s.empty())
        cout << "true";
    else
        cout << "false";
    return 0;
}
