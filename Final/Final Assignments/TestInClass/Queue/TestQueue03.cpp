#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;
void Input(queue<char> &q)
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        q.push(s[i]);
}

string ChuanHoa(queue<char> q)
{
    string result = "";
    while (!q.empty())
    {
        if (q.front() >= 'A' && q.front() <= 'Z')
            result += (q.front() + 32);
        else
            result += q.front();
        q.pop();
    }
    return result;
}

string Check(queue<char> q)
{
    string s = ChuanHoa(q);
    string t = s;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
        st.push(s[i]);
    for (int j = 0; j < t.length(); j++)
    {
        if (t[j] != st.top())
            return "False";
        st.pop();
    }
    return "True";
}

void Output(queue<char> q)
{
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
}

int main()
{
    queue<char> q;
    Input(q);
    cout << Check(q) << endl;
    Output(q);
    return 0;
}
