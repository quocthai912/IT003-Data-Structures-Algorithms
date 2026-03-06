/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 400000

void NhapMang(int a[MAXN], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
}
int LinearSearch(int a[MAXN], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			return 1;
	}
	return -1;
}

int main()
{
	int a[MAXN], n, x;

	std::cin >> x;

	NhapMang(a, n);

	int i = LinearSearch(a, n, x);

	if (i == -1)
		std::cout << "false";
	else
		std::cout << "true";
	return 0;
}
