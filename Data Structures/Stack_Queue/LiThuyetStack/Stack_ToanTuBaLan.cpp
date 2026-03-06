#include <bits/stdc++.h>
using namespace std;
bool checkToanTu(char s)
{
    return s == '*' || s == '/' || s == '%' || s == '+' || s == '-';
}
int doUuTienToanTu(char s)
{
    if (s == '*' || s == '/' || s == '%')
        return 1;
    return 0;
}
string chuyenDoi(string s)
{
    stack<char> nganXep;
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;
        else if (isalnum(s[i]))
        {
            while (i < s.length() && isalnum(s[i]))
            {
                result += s[i];
                i++;
            }
            i--;
            result += ' ';
        }
        else if (s[i] == '(')
            nganXep.push(s[i]);
        else if (s[i] == ')')
        {
            while (!nganXep.empty() && nganXep.top() != '(')
            {
                result += nganXep.top();
                result += ' ';
                nganXep.pop();
            }
            nganXep.pop();
        }
        else if (checkToanTu(s[i]))
        {
            while (!nganXep.empty() && checkToanTu(nganXep.top()) && doUuTienToanTu(nganXep.top()) >= doUuTienToanTu(s[i]))
            {
                result += nganXep.top();
                result += ' ';
                nganXep.pop();
            }
            nganXep.push(s[i]);
        }
    }
    while (!nganXep.empty())
    {
        result += nganXep.top();
        result += ' ';
        nganXep.pop();
    }
    return result;
}
int main()
{
    string testCase;
    getline(cin, testCase);
    cout << "Bieu Thuc Ban Dau: " << testCase << endl;
    string result = chuyenDoi(testCase);
    cout << "Bieu Thuc Sau Khi Chuyen Doi: " << result;
    return 0;
}
