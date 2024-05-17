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
		int n;
		cin >> n;

		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		
		int ans = 0;
		for (int i = 0, k = 0; i < n; i++)
		{
			for (; k < n && a[k] <= b[i]; k++);
			ans = max(ans, i - k + 1);
		}

		cout << ans << endl;
	}

	return 0;
}
