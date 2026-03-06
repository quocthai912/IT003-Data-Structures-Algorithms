#include <bits/stdc++.h>
using namespace std;
struct doanThang
{
    int left, right;
};
bool cmp(doanThang A, doanThang B)
{
    return A.right < B.right;
}
int main()
{
    int size;
    cin >> size;
    vector<doanThang> mangDoanThang(size);
    for (int i = 0; i < size; i++)
        cin >> mangDoanThang[i].left >> mangDoanThang[i].right;
    sort(mangDoanThang.begin(), mangDoanThang.end(), cmp);
    int last = mangDoanThang[0].right;
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        if (mangDoanThang[i].left > last)
        {
            last = mangDoanThang[i].right;
            count++;
        }
    }
    cout << count;
    return 0;
}
