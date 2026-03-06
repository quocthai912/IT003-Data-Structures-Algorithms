#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	if (s == "")
		cout << "Chuoi rong.";
	else
	{
		unordered_map<char, int> hashMap;
		for (int i = 0; i < s.size(); i++)
		{
			hashMap[s[i]]++;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (hashMap[s[i]] == -1)
				continue;
			cout << s[i] << ": " << hashMap[s[i]] << endl;
			hashMap[s[i]] = -1;
		}
	}
	return 0;
}
