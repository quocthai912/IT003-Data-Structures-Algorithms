/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define MAX 300

#include <sstream>
#include <stack>
void StringReverse(string &s)
{
    string temp = "";
    for (int i = s.length() - 1; i >= 0; i--)
        temp += s[i];
    stringstream ss(s);
    string word;
    stack<string> st;
    while (ss >> word)
        st.push(word);
    string chuoiStack = "";
    while (!st.empty())
    {
        chuoiStack += st.top();
        st.pop();
    }
    int dem = 0;
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp[i] == ' ')
            continue;
        else
            temp[i] = chuoiStack[dem++];
    }
    s = temp;
}

int main()
{
    string s;

    getline(std::cin, s); // Nhap chuoi s

    if (s.empty() == true)
        cout << "Chuoi rong." << endl;
    else
    {
        StringReverse(s);
        cout << s << endl;
    }

    return 0;
}
