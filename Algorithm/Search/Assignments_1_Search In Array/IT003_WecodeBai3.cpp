
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N)
{
	for (int i = 0; i < N; i++)
		std::cin >> A[i];
}

bool binary_search(int a[], int left, int right, int target)
{
	if (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == target)
		{
			return true;
		}
		else if (a[mid] < target)
			return binary_search(a, mid + 1, right, target);
		else
			return binary_search(a, left, mid - 1, target);
	}
	return false;
}

int main()
{
	int x, n, a[MAXN];

	cin >> x;
	cin >> n;
	NhapMang(a, n);

	cout << boolalpha << binary_search(a, 0, n - 1, x);

	return 0;
}
