#include <iostream>
#include <string>

using namespace std;

char something_else(const char & c)
{
	return c == 'a' ? 'b' : 'a';
}

void solve()
{
	string s;
	cin >> s;

	int x = -1;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i - 1] == s[i])
		{
			x = i;
			break;
		}
	}

	if (x < 0)
		cout << something_else(s[0]) << s;
	else
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (i == x)
				cout << something_else(s[i]);
			cout << s[i];
		}
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
		solve();

	return 0;
}
