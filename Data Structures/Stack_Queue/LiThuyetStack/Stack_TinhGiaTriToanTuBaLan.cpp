#include <bits/stdc++.h>
using namespace std;
int tinhGiaTri(string s)
{
    stack<int> nganXep;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;
        else if (isdigit(s[i]))
        {
            string chuoiSo = "";
            while (i < s.length() && isdigit(s[i]))
            {
                chuoiSo += s[i];
                i++;
            }
            int so = stol(chuoiSo);
            nganXep.push(so);
        }
        else
        {
            int giaTri1 = nganXep.top();
            nganXep.pop();
            int giaTri2 = nganXep.top();
            nganXep.pop();
            if (s[i] == '+')
                nganXep.push(giaTri2 + giaTri1);
            else if (s[i] == '-')
                nganXep.push(giaTri2 - giaTri1);
            else if (s[i] == '*')
                nganXep.push(giaTri2 * giaTri1);
            else if (s[i] == '/')
                nganXep.push(giaTri2 / giaTri1);
            else if (s[i] == '%')
                nganXep.push(giaTri2 % giaTri1);
        }
    }
    return nganXep.top();
}
int main()
{
    // Rang buoc: Bieu thuc phai chua dau ' ' va luon dung.
    string bieuThucBaLan;
    getline(cin, bieuThucBaLan);
    cout << "Bieu Thuc Ba Lan: " << bieuThucBaLan << endl;
    int giaTriBieuThuc = tinhGiaTri(bieuThucBaLan);
    cout << "Gia Tri Bieu Thuc: " << giaTriBieuThuc;
    return 0;
}