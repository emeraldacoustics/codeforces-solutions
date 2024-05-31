#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int maxa = 11807;

vector<bool> is_prime;
vector<int> primes;

void initialize()
{
	is_prime.resize(maxa + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2; i <= maxa / i; i++)
	{
		if (!is_prime[i])
			continue;
		
		for (int j = i * i; j <= maxa; j += i)
			is_prime[j] = false;
	}

	for (int i = 0; i <= maxa; i++)
	{
		if (is_prime[i])
			primes.push_back(i);
	}
}

vector<vector<pair<int, int> > > e;
vector<bool> evis;
vector<pair<int, int> > path;

void dfs(const int & u)
{
	for (; !e[u].empty(); )
	{
		const auto edge = e[u].back();
		e[u].pop_back();

		if (evis[edge.second])
			continue;

		evis[edge.second] = true;
		dfs(edge.first);
		path.emplace_back(u, edge.first);
	}
};

int path_length(const int & n)
{
	if (n == 0)
		return 0;
	else if (n % 2)
		return n * (n + 1) / 2;
	else
		return n * n / 2 + 1;
}

vector<int> hamilton(const int & n)
{
	e.clear();
	e.resize(n);
	int ecnt = 0;
	for (int u = 0; u < n; u++)
	{
		e[u].emplace_back(u, ecnt);
		ecnt++;

		for (int v = u + 1; v < n; v++)
		{
			if (n % 2 == 0 && u % 2 == 0 && v == u + 1 && u > 0)
				continue;

			e[u].emplace_back(v, ecnt);
			e[v].emplace_back(u, ecnt);
			ecnt++;
		}
	}

	evis.clear();
	evis.resize(ecnt, false);
	path.clear();
	dfs(0);
	reverse(path.begin(), path.end());

	vector<int> ans;
	ans.push_back(primes[0]);
	for (const auto & edge : path)
		ans.push_back(primes[edge.second]);
	return ans;
}

void solve()
{
	int n;
	cin >> n;

	int m = sqrtl(n * 2);
	for (; path_length(m) + 1 < n; m++);
	auto ans = hamilton(m);
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);

	initialize();

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
		solve();

	return 0;
}
