#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    double x, y, z;
};

bool SoSanhDiem(Point &A, Point &B)
{
    // A < B ?
    if (A.x == B.x)
    {
        if (A.y == B.y)
            return A.z < B.z;
        else
            return A.y < B.y;
    }
    return A.x < B.x;
}

int BinarySearch(vector<Point> ds, Point target)
{
    int soBuoc = 0;
    int left = 0;
    int right = ds.size() - 1;
    while (left <= right)
    {
        soBuoc++;
        int mid = left + (right - left) / 2;
        if (ds[mid].x == target.x && ds[mid].y == target.y && ds[mid].z == target.z)
        {
            return soBuoc;
        }
        else if (SoSanhDiem(ds[mid], target))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

int main()
{
    vector<Point> ds;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        Point data;
        cin >> data.x >> data.y >> data.z;
        ds.push_back(data);
    }
    int M;
    cin >> M;
    vector<Point> dsDiemCanTim;
    for (int i = 0; i < M; i++)
    {
        Point data;
        cin >> data.x >> data.y >> data.z;
        dsDiemCanTim.push_back(data);
    }
    for (int i = 0; i < M; i++)
    {
        int soBuoc = BinarySearch(ds, dsDiemCanTim[i]);
        if (soBuoc == 0)
        {
            cout << "KHONG";
        }
        else
            cout << soBuoc;
        cout << endl;
    }
    return 0;
}