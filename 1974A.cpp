#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int x, y;
		cin >> x >> y;

		int ans = (y + 1) / 2;
		ans = max(ans, (max(0, x - (15 * ans - 4 * y)) + 14) / 15 + ans);

		cout << ans << endl;
	}

	return 0;
}
