#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &A)
{
	for (int i = 0; i < A.size() - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < A.size(); j++)
			if (A[j] < A[minIndex])
				minIndex = j;
		if (A[i] > A[minIndex])
			swap(A[i], A[minIndex]);
	}
}
int main()
{
	int size;
	cin >> size;
	vector<int> A(size);
	for (int i = 0; i < size; i++)
		cin >> A[i];
	selectionSort(A);
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	return 0;
}
