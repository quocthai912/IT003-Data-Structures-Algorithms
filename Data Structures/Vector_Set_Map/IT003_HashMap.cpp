// Tìm phần tử xuất hiện nhiều nhất trong mảng, nếu các phần tử bằng 1 hết thì in ra NotFound
// Độ phức tạp O(N)
// Bộ Nhớ O(N): HashMap
#include <bits/stdc++.h>
using namespace std;
void Input(vector<int> &a)
{
	int temp;
	while (true)
	{
		cin >> temp;
		if (temp == -1)
			break;
		a.push_back(temp);
	}
}
void Output(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void Find(vector<int> a)
{
	unordered_map<int, int> hashMap;
	for (int i = 0; i < a.size(); i++)
	{
		hashMap[a[i]]++;
	}
	int maxCount = 2;
	for (const auto &it : hashMap)
	{
		if (it.second >= maxCount)
			maxCount = it.second;
	}
	bool found = false;
	for (const auto &it : hashMap)
	{
		if (it.second == maxCount)
		{
			cout << it.first << " ";
			found = true;
		}
	}
	if (!found)
		cout << "NotFound";
}
int main()
{
	vector<int> A;
	Input(A);
	Find(A);
	return 0;
}
