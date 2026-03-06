#include <iostream>
using namespace std;
__int128 soCayHaDuocSauDNgay(long long days, long long a, long long k, long long b, long long m)
{
	if (days == 0)
		return 0;
	long long soNgayDoiMotLamViec = days - (days / k);
	long long soNgayDoiHaiLamViec = days - (days / m);
	__int128 val = (__int128)soNgayDoiMotLamViec * a + (__int128)soNgayDoiHaiLamViec * b;
	return val;
}
int main()
{
	long long a, k, b, m, n;
	cin >> a >> k >> b >> m >> n;
	long long left = 1;
	long long right = n;
	while (left <= right)
	{
		long long mid = left + (right - left) / 2;
		if (soCayHaDuocSauDNgay(mid, a, k, b, m) >= n)
		{
			right = mid - 1;
		}
		else if (soCayHaDuocSauDNgay(mid, a, k, b, m) < n)
		{
			left = mid + 1;
		}
	}
	cout << left;
	return 0;
}
