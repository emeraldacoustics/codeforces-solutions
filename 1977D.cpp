#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

using namespace std;

mt19937_64 random;

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<vector<bool> > a(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			a[i][j] = s[j] - '0';
	}

	vector<long long> h0(n), h1(n);
	for (int i = 0; i < n; i++)
	{
		h0[i] = random();
		h1[i] = random();
	}

	int ans = 0;
	pair<int, int> ans_idx;
	map<pair<long long, long long>, int> frq;
	for (int j = 0; j < m; j++)
	{
		pair<long long, long long> hsh;
		for (int i = 0; i < n; i++)
		{
			if (a[i][j])
			{
				hsh.first ^= h0[i];
				hsh.second ^= h1[i];
			}
		}

		for (int i = 0; i < n; i++)
		{
			const auto cur = make_pair(hsh.first ^ h0[i], hsh.second ^ h1[i]);
			const auto cnt = ++frq[cur];
			if (ans < cnt)
			{
				ans = cnt;
				ans_idx = make_pair(i, j);
			}
		}
	}

	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << (a[i][ans_idx.second] ^ (i == ans_idx.first));
	cout << endl;
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
