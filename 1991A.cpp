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
	
	int ans = a[0];
	for (int i = 2; i < n; i += 2)
		ans = max(ans, a[i]);
	
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
