// Best case = O(N), Avr case and Worst Case = O(N^2)
#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &A)
{
	for (int i = 1; i < A.size(); i++)
	{
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}
int main()
{
	int size;
	cin >> size;
	vector<int> A(size);
	for (int i = 0; i < size; i++)
		cin >> A[i];
	insertionSort(A);
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	return 0;
}
