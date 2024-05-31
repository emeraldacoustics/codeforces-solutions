#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int l, r;
		cin >> l >> r;

		int ans = 30;
		for (; ans > 0 && !(r >> ans & 1); ans--);

		cout << ans << endl;
	}

	return 0;
}
