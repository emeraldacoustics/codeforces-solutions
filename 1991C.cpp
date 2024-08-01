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
	
	vector<bool> vis(2, false);
	for (int i = 0; i < n; i++)
		vis[a[i] % 2] = true;
	
	if (vis[0] && vis[1])
		cout << "-1" << endl;
	else
	{
		vector<int> x;
		vector<int> z = a;
		for (; ; )
		{
			int mn = *min_element(z.begin(), z.end());
			int mx = *max_element(z.begin(), z.end());
			if (mn == 0 && mx == 0)
				break;

			int y = mn + (mx - mn) / 2;
			x.push_back(y);
			for (int i = 0; i < z.size(); i++)
				z[i] = abs(z[i] - y);
		}
		
		cout << x.size() << endl;
		for (int i = 0; i < x.size(); i++)
		{
			if (i > 0)
				cout << " ";
			cout << x[i];
		}
		cout << endl;
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
