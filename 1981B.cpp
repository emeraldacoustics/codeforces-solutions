#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		long long n, m;
		cin >> n >> m;

		long long l = max(0ll, n - m);
		long long r = n + m;

		long long ans = 0;
		for (int i = 0; i < 32; i++)
		{
			auto lx = l >> i, rx = r >> i;
			if (lx & 1 || (rx - lx) + 1 >= 2)
				ans |= 1ll << i;
		}
		cout << ans << endl;
	}

	return 0;
}
