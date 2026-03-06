#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	// Tính trung bình cộng các số từ 1->N, độ phức tạp O(N)
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	double avr = double(sum) / n;
	cout << avr << endl;
	// Xuất các số chẵn từ 1->N, độ phức tạp O(N)
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			cout << i << " ";
		}
	}
	return 0;
}
