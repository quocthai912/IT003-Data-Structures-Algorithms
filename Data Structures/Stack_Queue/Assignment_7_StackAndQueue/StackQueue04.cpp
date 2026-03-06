/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 100

struct NODE
{
    char info;
    NODE *pNext;
};
#include <stack>
int doUuTienKiTu(char s)
{
    if (s == '^')
        return 2;
    else if (s == '*' || s == '/')
        return 1;
    return 0;
}
bool checkKiTu(char s)
{
    return s == '+' || s == '-' || s == '/' || s == '*' || s == '^';
}
void Input_infix(char infix[], int &ni)
{
    ni = 0;
    string infixString;
    getline(cin, infixString);
    for (int i = 0; i < infixString.length(); i++)
    {
        if (infixString[i] != '#')
            infix[ni++] = infixString[i];
    }
}
void infix_to_postfix(char infix[], int ni, char postfix[], int &np)
{
    np = 0;
    stack<char> st;
    for (int i = 0; i < ni; i++)
    {
        if (infix[i] == '(')
            st.push(infix[i]);
        else if (isdigit(infix[i]))
            postfix[np++] = infix[i];
        else if (infix[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix[np++] = st.top();
                st.pop();
            }
            st.pop();
        }
        else if (checkKiTu(infix[i]))
        {
            while (!st.empty() && checkKiTu(st.top()) && doUuTienKiTu(st.top()) >= doUuTienKiTu(infix[i]))
            {
                postfix[np++] = st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    while (!st.empty())
    {
        postfix[np++] = st.top();
        st.pop();
    }
}
void Output(char postfix[], int np)
{
    for (int i = 0; i < np; i++)
    {
        cout << postfix[i] << " ";
    }
}
int main()
{
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
