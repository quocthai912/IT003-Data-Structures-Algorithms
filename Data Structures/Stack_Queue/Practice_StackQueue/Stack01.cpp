// Bai nay rat de o cho khong co khoang trang du thua
#include <bits/stdc++.h>
using namespace std;
void Fun(string &st, stack<string> s)
{
    string reverseString = "";
    stringstream ss(st);
    string word;
    while (ss >> word)
        s.push(word);
    while (!s.empty())
    {
        reverseString += s.top() + " ";
        s.pop();
    }
    st = reverseString;
}
int main()
{
    stack<string> s;
    string st;
    getline(cin, st);
    Fun(st, s);
    cout << st;
    return 0;
}