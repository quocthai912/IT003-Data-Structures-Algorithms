#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    long long x, y, z;
};
vector<Point> temp(1000005);
bool SoSanhPoint(const Point &p1, const Point &p2)
{
    if (p1.x == p2.x)
    {
        if (p1.y == p2.y)
            return p1.z < p2.z;
        return p1.y > p2.y;
    }
    return p1.x < p2.x;
}

void Merge(vector<Point> &p, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i < mid + 1 && j < right + 1)
    {
        if (SoSanhPoint(p[i], p[j]))
            temp[k++] = p[i++];
        else
            temp[k++] = p[j++];
    }
    while (i < mid + 1)
        temp[k++] = p[i++];
    while (j < right + 1)
        temp[k++] = p[j++];
    for (int i = left; i <= right; i++)
    {
        p[i] = temp[i];
    }
}

void MergeSort(vector<Point> &p, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    MergeSort(p, left, mid);
    MergeSort(p, mid + 1, right);
    Merge(p, left, mid, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<Point> p(N);
    for (int i = 0; i < N; i++)
    {
        cin >> p[i].x >> p[i].y >> p[i].z;
    }
    MergeSort(p, 0, p.size() - 1);
    for (int i = 0; i < N; i++)
    {
        cout << p[i].x << " " << p[i].y << " " << p[i].z << "\n";
    }
    return 0;
}