#include <bits/stdc++.h>
using namespace std;
int demSoO(vector<int> array)
{
    int count = 0;
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] == 0)
            count++;
    }
    return count;
}
vector<int> chuyenChuoiSangMang(string chuoi)
{
    vector<int> ketQua;
    for (int i = 0; i < chuoi.length(); i++)
    {
        int number = chuoi[i] - '0';
        ketQua.push_back(number);
    }
    return ketQua;
}
int main()
{
    string number;
    cin >> number;
    vector<int> chuyenDoi = chuyenChuoiSangMang(number);
    sort(chuyenDoi.begin(), chuyenDoi.end());
    int count = demSoO(chuyenDoi);
    string ketQua = "";
    ketQua += to_string(chuyenDoi[count]);
    for (int i = 0; i < count; i++)
    {
        ketQua += "0";
    }
    for (int i = count + 1; i < chuyenDoi.size(); i++)
    {
        ketQua += to_string(chuyenDoi[i]);
    }
    cout << ketQua;
    return 0;
}