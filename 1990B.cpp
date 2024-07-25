#include <iostream>

using namespace std;

void solve()
{
	int n, x, y;
	cin >> n >> x >> y;
	x--, y--;
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			cout << " ";

		if (i < y)
			cout << ((y - i - 1) % 2 ? "1" : "-1");
		else if (i <= x)
			cout << "1";
		else
			cout << ((i - x - 1) % 2 ? "1" : "-1");
	}
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
