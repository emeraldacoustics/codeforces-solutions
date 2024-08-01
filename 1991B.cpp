#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> b(n - 1);
	for (int i = 0; i < n - 1; i++)
		cin >> b[i];

	vector<int> a(n);
	a[0] = b[0];
	a[n - 1] = b[n - 2];
	for (int i = 1; i < n - 1; i++)
		a[i] = b[i - 1] | b[i];

	bool vld = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (b[i] != (a[i] & a[i + 1]))
		{
			vld = false;
			break;
		}
	}

	if (vld)
	{
		for (int i = 0; i < n; i++)
		{
			if (i > 0)
				cout << " ";
			cout << a[i];
		}
	}
	else
		cout << "-1";
	cout << endl;
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
