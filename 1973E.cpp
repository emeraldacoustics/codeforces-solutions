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
		vector<int> p(n);
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
			p[i]--;
		}

		vector<int> q;
		for (int i = 0; i < n; i++)
		{
			if (p[i] != i)
				q.push_back(p[i] + i);
		}

		long long ans = 0;
		if (q.empty())
			ans = (long long)n * (n * 2 + 1);
		else
		{
			if (count(q.begin(), q.end(), q[0]) == q.size())
				ans += 1;
			
			int mn = n, mx = -1;
			for (int i = 0; i < n; i++)
			{
				if (p[i] != i)
				{
					mn = min(mn, i);
					mx = max(mx, i);
				}
			}

			mn++;
			mx++;
			for (int l = 1; l <= mn + n; l++)
				ans += max(0, n * 2 - max(l, mx));
		}

		cout << ans << endl;
	}

	return 0;
}
