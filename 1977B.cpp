#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int x;
		cin >> x;

		vector<int> ans(32, 0);
		for (int i = 0; i < 30; i++)
			ans[i] = x >> i & 1;
		
		for (int i = 0, k = i; i < ans.size() - 1; i = k)
		{
			if (ans[i] && ans[i + 1])
			{
				ans[i] = -1;
				for (k = i + 1; k < ans.size() && ans[k]; k++)
					ans[k] = 0;
				ans[k] = 1;
			}
			else
				k = i + 1;
		}

		int n = ans.size();
		for (; n > 1 && ans[n - 1] == 0; n--);
		ans.resize(n);

		cout << n << endl;
		for (int i = 0; i < n; i++)
		{
			if (i > 0)
				cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}

	return 0;
}
