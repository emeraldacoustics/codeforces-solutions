#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int n, k;
		cin >> n >> k;

		int mx = 0;
		for (int x = 1; x <= n; x++)
		{
			cout << "? 1 " << n * x << endl;
			cout.flush();

			int r;
			cin >> r;
			if (r != n + 1)
				mx = max(mx, n * x / r);
		}

		int ans = -1;
		for (int l = 1; l <= n / k; l++)
		{
			int x, r = 0;
			for (x = 0; x < k && r < n; x++)
			{
				cout << "? " << r + 1 << " " << mx * l << endl;
				cout.flush();

				cin >> r;
				if (r == n + 1)
					break;
			}

			if (x == k && r == n)
				ans = max(ans, mx * l);
		}

		cout << "! " << ans << endl;
		cout.flush();

		int r;
		cin >> r;
		if (r == -1)
			break;
	}

	return 0;
}
