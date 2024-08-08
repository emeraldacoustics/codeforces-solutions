#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> p(n, -1);
	for (int i = 1; i < n; i++)
	{
		cin >> p[i];
		p[i]--;
	}

	vector<vector<int> > sons(n);
	for (int i = 0; i < n; i++)
	{
		if (p[i] >= 0)
			sons[p[i]].push_back(i);
	}

	vector<int> tpl;
	queue<int> que;
	for (que.push(0); !que.empty(); que.pop())
	{
		const int u = que.front();
		tpl.push_back(u);
		for (const auto & v : sons[u])
			que.push(v);
	}

	vector<int> dp(n);
	for (int i = n - 1; i >= 0; i--)
	{
		const int & u = tpl[i];

		if (sons[u].empty())
			dp[u] = a[u];
		else
		{
			int mn = -1;
			for (const auto & v : sons[u])
			{
				if (mn < 0 || mn > dp[v])
					mn = dp[v];
			}

			if (mn <= a[u])
				dp[u] = mn;
			else
				dp[u] = a[u] + (mn - a[u]) / 2;
		}
	}

	int mn = -1;
	for (const auto & v : sons[0])
	{
		if (mn < 0 || mn > dp[v])
			mn = dp[v];
	}
	if (mn < 0)
		mn = 0;
	
	cout << a[0] + mn << endl;
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
