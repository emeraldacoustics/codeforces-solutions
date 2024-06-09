#include <iostream>
#include <vector>

using namespace std;

const int mod = 998244353;

void solve()
{
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	long long mn = 0, mx = 0;
	int mnc = 1, mxc = 1;
	for (int i = 0; i < n; i++)
	{
		long long xmx = max(abs(mn + a[i]), abs(mx + a[i]));
		long long xmn = min(mn + a[i], mx + a[i]);

		int xmxc = 0;
		if (xmx == mx + a[i])
			xmxc = (xmxc + mxc) % mod;
		if (xmx == abs(mx + a[i]))
			xmxc = (xmxc + mxc) % mod;
		if (mn != mx)
		{
			if (xmx == mn + a[i])
				xmxc = (xmxc + mnc) % mod;
			if (xmx == abs(mn + a[i]))
				xmxc = (xmxc + mnc) % mod;
		}

		int xmnc = 0;
		if (xmn == mx + a[i])
			xmnc = (xmnc + mxc) % mod;
		if (xmn == abs(mx + a[i]))
			xmnc = (xmnc + mxc) % mod;
		if (mn != mx)
		{
			if (xmn == mn + a[i])
				xmnc = (xmnc + mnc) % mod;
			if (xmn == abs(mn + a[i]))
				xmnc = (xmnc + mnc) % mod;
		}

		mx = xmx, mn = xmn;
		mxc = xmxc, mnc = xmnc;
	}

	cout << mxc << endl;
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
