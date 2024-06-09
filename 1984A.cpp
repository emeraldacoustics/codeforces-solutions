#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	if (a[0] == a[n - 1])
		cout << "NO" << endl;
	else
	{
		string ans;
		for (int i = 0; i < n; i++)
			ans.push_back('R');
		if (a[n - 2] == a[n - 1])
			ans[n - 1] = 'B';
		else
			ans[0] = 'B';

		cout << "YES" << endl;
		cout << ans << endl;
	}
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
