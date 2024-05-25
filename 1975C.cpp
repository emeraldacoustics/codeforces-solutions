#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		vector<pair<int, int> > v;
		for (int i = 0; i < n; i++)
			v.emplace_back(a[i], i);
		
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		int ans = 0;
		vector<bool> vis(n, false);
		for (const auto & p : v)
		{
			vis[p.second] = true;
			for (int i = max(0, p.second - 2); i < n && i <= p.second + 2; i++)
			{
				if (i != p.second && vis[i])
				{
					ans = p.first;
					break;
				}
			}
			if (ans)
				break;
		}

		cout << ans << endl;
	}

	return 0;
}
