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
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int l = 1;
		for (; l < n && a[l - 1] <= a[l]; l++);

		int r = n - 1;
		for (; r > 0 && a[r - 1] <= a[r]; r--);

		bool ans = l == n || (l == r && a[0] >= a[n - 1]);

		cout << (ans ? "YES" : "NO") << endl;
	}

	return 0;
}
