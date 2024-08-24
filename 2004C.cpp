#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	long long ans = 0, dlt = 0;
	for (int i = 0; i < n; i++)
		ans += a[i] * (i % 2 ? -1 : 1);
	for (int i = 0; i + 2 <= n; i += 2)
		dlt += a[i] - a[i + 1];

	ans = ans - min<long long>(dlt, k);

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
