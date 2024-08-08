#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<string> s(2);
	cin >> s[0] >> s[1];

	int ans = 0;
	for (int i = 1; i + 1 < n; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			if (s[k][i] == '.' &&
				s[k][i - 1] == '.' &&
				s[k][i + 1] == '.' &&
				s[k ^ 1][i] == '.' &&
				s[k ^ 1][i - 1] != '.' &&
				s[k ^ 1][i + 1] != '.')
				ans++;
		}
	}

	cout << ans << endl;
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
