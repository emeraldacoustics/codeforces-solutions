#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int m, x;
		cin >> m >> x;
		vector<int> c(m), h(m);
		for (int i = 0; i < m; i++)
			cin >> c[i] >> h[i];

		int tot = accumulate(h.begin(), h.end(), 0);

		vector<vector<long long> > dp(m + 1, vector<long long>(tot + 1, -1));
		dp[0][0] = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j <= tot; j++)
			{
				if (dp[i][j] != -1)
				{
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + x);
					if (dp[i][j] >= c[i] && j + h[i] <= tot)
						dp[i + 1][j + h[i]] = max(dp[i + 1][j + h[i]], dp[i][j] - c[i] + x);
				}
			}
		}
		for (int i = tot; i >= 0; i--)
		{
			if (dp[m][i] != -1)
			{
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}
