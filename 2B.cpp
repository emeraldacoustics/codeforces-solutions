#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1000;

int a[maxn][maxn];
char prv[2][maxn][maxn];
short int dp[2][maxn][maxn];

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}

	pair<int, int> p0(-1, -1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x = a[i][j];
			if (x == 0)
			{
				for (int k = 0; k < 2; k++)
				{
					prv[k][i][j] = '0';
					dp[k][i][j] = 0;
				}
				p0 = make_pair(i, j);
			}
			else
			{
				int z[2] = { 0 };
				for (; x > 0 && x % 2 == 0; z[0]++, x /= 2);
				for (; x > 0 && x % 5 == 0; z[1]++, x /= 5);

				vector<pair<int, int> > pv;
				for (int k = 0; k < 2; k++)
				{
					prv[k][i][j] = 'X';
					if (i == 0 && j == 0)
						dp[k][i][j] = z[k];
					else
					{
						if (i > 0)
							pv.emplace_back(-1, 0);
						if (j > 0)
							pv.emplace_back(0, -1);

						for (const auto & p : pv)
						{
							int r = i + p.first, c = j + p.second;

							if (prv[k][r][c] == '0')
								continue;

							if (prv[k][i][j] == 'X' || dp[k][i][j] > dp[k][r][c] + z[k])
							{
								prv[k][i][j] = p.first ? 'D' : 'R';
								dp[k][i][j] = dp[k][r][c] + z[k];
							}
						}

						if (prv[k][i][j] == 'X')
						{
							prv[k][i][j] = '0';
							dp[k][i][j] = 0;
						}
					}
				}
			}
		}
	}

	int ans;
	string path;
	if (p0 != make_pair(-1, -1) && (prv[0][n - 1][n - 1] == '0' || min(dp[0][n - 1][n - 1], dp[1][n - 1][n - 1]) >= 1))
	{
		ans = 1;
		for (int i = 0; i < p0.first; i++)
			path.push_back('D');
		for (int j = 0; j < p0.second; j++)
			path.push_back('R');
		for (int i = p0.first; i < n - 1; i++)
			path.push_back('D');
		for (int j = p0.second; j < n - 1; j++)
			path.push_back('R');
	}
	else
	{
		int k = dp[0][n - 1][n - 1] <= dp[1][n - 1][n - 1] ? 0 : 1;
		ans = dp[k][n - 1][n - 1];
		for (int r = n - 1, c = n - 1; r > 0 || c > 0; )
		{
			path.push_back(prv[k][r][c]);
			(prv[k][r][c] == 'D' ? r : c)--;
		}
		reverse(path.begin(), path.end());
	}

	cout << ans << endl;
	cout << path << endl;

	return 0;
}