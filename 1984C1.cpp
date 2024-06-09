#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	long long mn = 0, mx = 0;
	for (int i = 0; i < n; i++)
	{
		long long xmx = max(abs(mn + a[i]), abs(mx + a[i]));
		long long xmn = min(mn + a[i], mx + a[i]);

		mx = xmx, mn = xmn;
	}

	cout << mx << endl;
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
