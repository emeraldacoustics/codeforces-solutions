#include <iostream>

using namespace std;

bool solve()
{
	long long x;
	cin >> x;

	for (; x > 0; x /= 10)
	{
		if (x < 10)
			return false;

		int s = 10 + x % 10;
		if (s == 19)
			return false;

		x -= s;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
		cout << (solve() ? "YES" : "NO") << endl;

	return 0;
}
