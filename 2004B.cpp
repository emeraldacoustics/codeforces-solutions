#include <iostream>

using namespace std;

void solve()
{
	int l, r, L, R;
	cin >> l >> r;
	r++;
	cin >> L >> R;
	R++;

	int lft = max(l, L), rht = min(r, R);
	int ans = 1;
	if (lft < rht)
	{
		ans = rht - lft - 1;
		if (l != L)
			ans++;
		if (r != R)
			ans++;
	}

	cout << ans << endl;
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
