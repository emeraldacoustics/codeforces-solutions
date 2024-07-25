#include <algorithm>
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

	sort(a.begin(), a.end());
	bool ans = false;
	for (int i = 0, k = i; i < n; i = k)
	{
		for (; k < n && a[i] == a[k]; k++);
		if ((k - i) % 2)
		{
			ans = true;
			break;
		}
	}
	
	cout << (ans ? "YES" : "NO") << endl;
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
