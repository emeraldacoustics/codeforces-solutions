#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	vector<int> b = a;
	vector<int> wrong(1, -1);

	vector<pair<int, int> > av;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
			av.emplace_back(i, a[i]);
	}

	if (av.empty())
	{
		for (int i = 0; i < n; i++)
			b[i] = i % 2 ? 2 : 1;
		return b;
	}

	vector<vector<int> > avv;
	for (const auto & p : av)
	{
		vector<int> v;
		for (int x = p.second; x > 0; x >>= 1)
			v.push_back(x);
		reverse(v.begin(), v.end());
		avv.push_back(v);
	}

	for (int u = 0; u + 1 < av.size(); u++)
	{
		int v = u + 1, w = 0;
		for (; w < avv[u].size() && w < avv[v].size() && avv[u][w] == avv[v][w]; w++);
		w--;

		int md = avv[u].size() + avv[v].size() - w * 2 - 2;
		int d = av[v].first - av[u].first;
		if (d >= md && (d - md) % 2 == 0)
		{
			int l = av[u].first;
			for (int x = avv[u].size() - 1; x >= w; x--, l++)
				b[l] = avv[u][x];
			
			int r = av[v].first;
			for (int x = avv[v].size() - 1; x >= w; x--, r--)
				b[r] = avv[v][x];
			
			for (; l <= r; l++, r--)
			{
				b[l] = b[l - 1] > 1 ? b[l - 1] >> 1 : 2;
				b[r] = b[r + 1] > 1 ? b[r + 1] >> 1 : 2;
			}
		}
		else
			return wrong;
	}
	for (int x = av[0].first - 1; x >= 0; x--)
		b[x] = b[x + 1] > 1 ? b[x + 1] >> 1 : 2;
	for (int x = av.back().first + 1; x < n; x++)
		b[x] = b[x - 1] > 1 ? b[x - 1] >> 1 : 2;
	
	return b;
}

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		auto ans = solve();

		for (int i = 0; i < ans.size(); i++)
		{
			if (i > 0)
				cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}

	return 0;
}
