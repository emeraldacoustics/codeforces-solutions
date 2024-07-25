#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	long long ans = 0;
	for (int k = 0; k < 2; k++)
	{
		ans += accumulate(a.begin(), a.end(), 0ll);
		set<int> s;
		vector<int> b(n);
		int mx = 0;
		for (int i = 0; i < n; i++)
		{
			if (s.count(a[i]))
				mx = max(mx, a[i]);
			s.insert(a[i]);

			b[i] = mx;
		}

		a = b;
	}

	for (int i = 0, k = i; i < n; i = k)
	{
		for (; k < n && a[i] == a[k]; k++);
		ans += ((long long)(k - i) * (n - k) + (long long)(k - i) * (k - i + 1) / 2) * a[i];
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
