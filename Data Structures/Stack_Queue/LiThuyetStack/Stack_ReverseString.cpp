#include <bits/stdc++.h>
using namespace std;
void reverseString(string &s)
{
    string temp = "";
    for (int i = s.length() - 1; i >= 0; i--)
        temp += s[i];
    stack<string> nganXep;
    stringstream ss(s);
    string word;
    while (ss >> word)
        nganXep.push(word);
    string chuoiNganXep = "";
    while (!nganXep.empty())
    {
        chuoiNganXep += nganXep.top();
        nganXep.pop();
    }
    int dem = 0;
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp[i] == ' ')
            continue;
        else
            temp[i] = chuoiNganXep[dem++];
    }
    s = temp;
}
int main()
{
    string s;
    getline(cin, s);
    cout << "Chuoi ban dau: " << s << endl;
    reverseString(s);
    cout << "Chuoi sau khi dao nguoc: " << s;
    return 0;
}
