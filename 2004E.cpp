#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int maxa = 10000000;

vector<int> sg(maxa + 1, 0);

void solve()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		ans ^= sg[a];
	}

	cout << (ans ? "Alice" : "Bob") << endl;
}

int main()
{
	ios::sync_with_stdio(false);

	vector<bool> vis(maxa + 1, false);
	sg[1] = 1;
	int z = 1;
	for (int i = 2; i <= maxa; i += 2)
	{
		vis[i] = true;
		sg[i] = 0;
	}
	for (int i = 3; i <= maxa; i++)
	{
		if (vis[i])
			continue;
		
		sg[i] = ++z;
		for (int k = i * 2; k <= maxa; k += i)
		{
			if (!vis[k])
			{
				vis[k] = true;
				sg[k] = sg[i];
			}
		}
	}

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
		solve();

	return 0;
}
