#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> find_path(const vector<vector<int> > & e, const int & a, const int & b)
{
	const int n = e.size();

	vector<int> p(n, -1);
	vector<bool> vis(n, false);
	vis[a] = true;
	queue<int> que;
	for (que.push(a); !que.empty(); que.pop())
	{
		const int u = que.front();
		for (const auto & v : e[u])
		{
			if (!vis[v])
			{
				p[v] = u;
				vis[v] = true;
				que.push(v);
			}
		}
	}

	vector<int> ans;
	for (int x = b; x >= 0; x = p[x])
		ans.push_back(x);
	reverse(ans.begin(), ans.end());

	return ans;
}

int maximum_depth(const vector<vector<int> > & e, const int & r)
{
	const int n = e.size();

	vector<int> d(n, -1);
	d[r] = 0;
	queue<int> que;
	for (que.push(r); !que.empty(); que.pop())
	{
		const int u = que.front();
		for (const auto & v : e[u])
		{
			if (d[v] < 0)
			{
				d[v] = d[u] + 1;
				que.push(v);
			}
		}
	}

	return *max_element(d.begin(), d.end());
}

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int n, a, b;
		cin >> n >> a >> b;
		a--;
		b--;
		
		vector<vector<int> > e(n);
		for (int i = 0, u, v; i < n - 1; i++)
		{
			cin >> u >> v;
			u--;
			v--;

			e[u].push_back(v);
			e[v].push_back(u);
		}

		auto path = find_path(e, a, b);
		int d = path.size() - 1;
		int r = path[d / 2];
		int ans = (d - d / 2) + (n - 1) * 2 - maximum_depth(e, r);

		cout << ans << endl;
	}

	return 0;
}
