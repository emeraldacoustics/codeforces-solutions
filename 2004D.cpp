#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> colors = { "BG", "BR", "BY", "GR", "GY", "RY" };
map<string, int> clrid;

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<string> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];

	vector<vector<int> > cities(colors.size());
	for (int i = 0; i < n; i++)
		cities[clrid[c[i]]].push_back(i);

	for (int qn = 0; qn < q; qn++)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		if (x > y)
			swap(x, y);

		int ans = -1;
		if (c[x][0] == c[y][0] ||
			c[x][0] == c[y][1] ||
			c[x][1] == c[y][0] ||
			c[x][1] == c[y][1])
			ans = abs(x - y);
		else
		{
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					string s = c[x];
					s[i] = c[y][j];
					
					int z = clrid[s];
					if (cities[z].empty())
						continue;
					
					int k = lower_bound(cities[z].begin(), cities[z].end(), x) - cities[z].begin();
					if (k < cities[z].size() && cities[z][k] < y)
					{
						int d = abs(x - y);
						if (ans < 0 || ans > d)
							ans = d;
					}
					else
					{
						if (k > 0)
						{
							int d = abs(x - cities[z][k - 1]) + abs(cities[z][k - 1] - y);
							if (ans < 0 || ans > d)
								ans = d;
						}

						if (k < cities[z].size())
						{
							int d = abs(x - cities[z][k]) + abs(cities[z][k] - y);
							if (ans < 0 || ans > d)
								ans = d;
						}
					}
				}
			}
		}

		cout << ans << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	for (int i = 0; i < colors.size(); i++)
	{
		clrid[colors[i]] = i;

		string tmp = colors[i];
		swap(tmp[0], tmp[1]);
		clrid[tmp] = i;
	}

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
		solve();

	return 0;
}
