#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int n, q;
		cin >> n >> q;

		vector<bool> c(n);
		for (int i = 0, x; i < n; i++)
		{
			cin >> x;
			c[i] = x;
		}

		vector<vector<int> > e(n);
		for (int i = 0, u, v; i < n - 1; i++)
		{
			cin >> u >> v;
			u--;
			v--;

			e[u].push_back(v);
			e[v].push_back(u);
		}

		int root = 0;
		vector<int> p(n, -1);
		vector<bool> vis(n, false);
		vis[root] = true;
		queue<int> que;
		for (que.push(root); !que.empty(); que.pop())
		{
			const int u = que.front();
			for (const auto & v : e[u])
			{
				if (!vis[v])
				{
					vis[v] = true;
					p[v] = u;
					que.push(v);
				}
			}
		}

		int blk = 0;
		vector<int> deg(n, 0);
		vector<int> occ(max(3, n), 0);
		for (int u = 0; u < n; u++)
		{
			if (c[u])
			{
				blk++;
				if (p[u] >= 0)
					deg[p[u]]++;
			}
		}
		set<int> s;
		for (int u = 0; u < n; u++)
		{
			if (c[u])
				occ[deg[u]]++;
			if (deg[u] == 2)
				s.insert(u);
		}
		
		for (int qn = 0, u; qn < q; qn++)
		{
			cin >> u;
			u--;

			if (p[u] >= 0)
			{
				if (c[p[u]])
					occ[deg[p[u]]]--;
				if (deg[p[u]] == 2)
					s.erase(p[u]);

				deg[p[u]] += c[u] ? -1 : 1;
				if (c[p[u]])
					occ[deg[p[u]]]++;
				if (deg[p[u]] == 2)
					s.insert(p[u]);
			}

			blk += c[u] ? -1 : 1;
			occ[deg[u]] += c[u] ? -1 : 1;

			c[u] = !c[u];

			bool ans = false;
			if (occ[0] == 1 && occ[1] == blk - 1)
				ans = true;
			else if (occ[0] == 2 && occ[2] == 1 && occ[1] == blk - 3)
			{
				if (s.size() == 1)
				{
					const int r = *s.begin();
					if (p[r] < 0 || !c[p[r]])
						ans = true;
				}
			}

			cout << (ans ? "YES" : "NO") << endl;
		}
	}

	return 0;
}
