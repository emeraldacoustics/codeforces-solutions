#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool query(int u, int v)
{
	string ans;

	if (u > v)
		swap(u, v);
	cout << "? " << u + 1 << " " << v + 1 << endl;
	cout.flush();

	cin >> ans;
	assert(ans != "-1");

	return ans == "YES";
}

void solve()
{
	int n;
	cin >> n;

	vector<int> stk[3];
	for (int u = 0; u < n; u++)
	{
		if (stk[0].empty())
			stk[0].push_back(u);
		else if (stk[1].empty())
		{
			if (query(stk[0].back(), u))
				stk[0].push_back(u);
			else
				stk[1].push_back(u);
		}
		else if (stk[2].empty())
		{
			bool b[2] = { query(stk[0].back(), u), query(stk[1].back(), u) };
			if (b[0] && b[1])
				stk[2].push_back(u);
			else
				stk[b[1]].push_back(u);
		}
		else
		{
			if (query(stk[2].back(), u))
				stk[2].push_back(u);
			else
			{
				int nxt = query(stk[0].back(), u);
				stk[!nxt].push_back(u);
				for (const auto & v : stk[2])
					stk[nxt].push_back(v);
				stk[2].clear();
			}
		}
	}
	for (const auto & v : stk[2])
		stk[0].push_back(v);
	stk[2].clear();

	vector<bool> ans(n, false);
	for (const auto & v : stk[1])
		ans[v] = true;

	cout << "! ";
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	cout.flush();
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
