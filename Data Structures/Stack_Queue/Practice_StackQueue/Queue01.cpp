#include <bits/stdc++.h>
using namespace std;
void Input(queue<int> &q)
{
    string bieuThuc;
    getline(cin, bieuThuc);
    queue<char> toanTu;
    q.push(0);
    for (int i = 0; i < bieuThuc.length(); i++)
    {
        if (bieuThuc[i] == ' ')
            continue;
        else if (bieuThuc[i] == '+' || bieuThuc[i] == '-')
            toanTu.push(bieuThuc[i]);
        else if (isdigit(bieuThuc[i]))
        {
            if (toanTu.empty())
            {
                q.push(bieuThuc[i] - '0');
            }
            else
            {
                int giaTri1 = q.front();
                int giaTri2 = bieuThuc[i] - '0';
                if (toanTu.front() == '+')
                {
                    q.pop();
                    q.push(giaTri1 + giaTri2);
                    toanTu.pop();
                }
                else
                {
                    q.pop();
                    q.push(giaTri1 - giaTri2);
                    toanTu.pop();
                }
            }
        }
    }
}
void Output(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
}
int main()
{
    queue<int> q;
    Input(q);
    Output(q);
    return 0;
}
