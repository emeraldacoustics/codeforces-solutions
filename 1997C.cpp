#include <iostream>
#include <string>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	int balance = 0;
	for (int i = 1; i < n; i += 2)
		balance += s[i] == '(' ? 1 : -1;
	
	int lft = 0, rmn = n / 2;
	for (int i = 0; i < n; i += 2)
	{
		rmn--;

		if (lft > 0 && abs(balance - 1) <= rmn)
			s[i] = ')';
		else
			s[i] = '(';

		lft += s[i] == '(' ? 1 : -1;
		lft += s[i + 1] == '(' ? 1 : -1;
		balance += s[i] == '(' ? 1 : -1;
	}

	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += i * (s[i] == '(' ? -1 : 1);
	
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
