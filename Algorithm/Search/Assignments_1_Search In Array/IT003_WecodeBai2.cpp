/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
for
goto
###End banned keyword*/

#include <iostream>

using namespace std;

bool binary_search(int a[], int left, int right, int target)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == target)
			return true;
		else if (a[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return false;
}

int main()
{
	int x;
	cin >> x;
	int n;
	cin >> n;

	int *a = new int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << std::boolalpha << binary_search(a, 0, n - 1, x);
	;

	return 0;
}
