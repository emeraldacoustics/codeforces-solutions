#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int p1, p2, p3;

		cin >> p1 >> p2 >> p3;

		int ans = (p1 + p2 + p3) % 2 ? -1 : (p1 + p2 + min(p1 + p2, p3)) / 2;

		cout << ans << endl;
	}

	return 0;
}
