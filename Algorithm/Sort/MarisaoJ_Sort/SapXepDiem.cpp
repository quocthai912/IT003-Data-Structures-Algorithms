#include <bits/stdc++.h>
using namespace std;
struct diemBaChieu
{
    int x, y, z;
};
bool cmp(diemBaChieu a, diemBaChieu b)
{
    if (a.x < b.x)
        return true;
    else if (a.x == b.x)
    {
        if (a.y < b.y)
            return true;
        else if (a.y == b.y)
        {
            if (a.z < b.z)
                return true;
        }
    }
    return false;
}
int main()
{
    int size;
    cin >> size;
    vector<diemBaChieu> vt(size);
    for (int i = 0; i < size; i++)
    {
        cin >> vt[i].x >> vt[i].y >> vt[i].z;
    }
    sort(vt.begin(), vt.end(), cmp);
    for (int i = 0; i < size; i++)
    {
        cout << vt[i].x << " " << vt[i].y << " " << vt[i].z << endl;
    }
    return 0;
}
