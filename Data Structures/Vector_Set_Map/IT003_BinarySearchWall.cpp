#include <bits/stdc++.h>
using namespace std;
bool searchTamGoCanDap(vector<long long> a, vector<long long> b, long long chieuCaoToiThieu)
{
    // Con trỏ tới mảng b
    long long p = 0;
    for (long long i = 0; i < a.size(); i++)
    {
        if (a[i] >= chieuCaoToiThieu)
            continue;
        long long need = chieuCaoToiThieu - a[i];
        // Tìm gỗ
        while (p < b.size() && b[p] < need)
            p++;
        // Hết gỗ
        if (p == b.size())
            return false;
        // Tìm được, lấy gỗ ra
        p++;
    }
    return true;
}
int main()
{
    long long n, m;
    vector<long long> a, b;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        long long ai;
        cin >> ai;
        a.push_back(ai);
    }
    cin >> m;
    for (long long i = 0; i < m; i++)
    {
        long long bi;
        cin >> bi;
        b.push_back(bi);
    }
    // Khởi tạo kết quả cuối = 0, có thể không thể đắp
    long long res = 0;
    long long left = 1;
    long long right = *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end());
    // Chiều cao tối đa có thể lắp
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (searchTamGoCanDap(a, b, mid))
        {
            // Biến kết quả để lưu nhầm trường hợp left + 1 không chính xác
            res = mid;
            // Tăng left để xem còn có thể nâng cao hơn không
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    // Lắp gỗ vào hàng rào
    vector<pair<long long, long long>> hashMap;
    long long count = 0;
    long long p = 0;
    for (long long i = 0; i < a.size(); i++)
    {
        if (a[i] >= res)
            continue;
        long long need = res - a[i];
        while (p < b.size() && b[p] < need)
            p++;
        if (p == b.size())
            break;
        hashMap.push_back({i, p});
        count++;
        p++;
    }
    cout << res << " " << count << endl;
    for (const auto &it : hashMap)
    {
        cout << it.first + 1 << " " << it.second + 1 << endl;
    }
    return 0;
}