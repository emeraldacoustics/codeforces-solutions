#include <iostream>
#include <vector>

using namespace std;

const int maxb = 20;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		int ans = 1;
		for (int b = 0; b < maxb; b++)
		{
			int prv = -1, mx = 0;
			for (int i = 0; i < n; i++)
			{
				if (a[i] & 1 << b)
					prv = i;
				
				mx = max(mx, i - prv + 1);
			}

			if (prv >= 0)
				ans = max(ans, mx);
		}

		cout << ans << endl;
	}

	return 0;
}
