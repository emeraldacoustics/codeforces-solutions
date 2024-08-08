#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int root = sqrt(n);
	if (root * root < n)
		root++;

	const int criteria = min(n, root * 5 / 2);

	vector<vector<int> > lvlup(criteria);
	for (int k = 1; k <= criteria; k++)
	{
		for (int i = 0, l = 1, x = 0; i < n; i++)
		{
			if (a[i] >= l)
			{
				x++;
				if (x == k)
				{
					x = 0;
					l++;
					lvlup[k - 1].push_back(i + 1);
				}
			}
		}
	}

	const int lmt = (n + criteria - 1) / criteria + 1;
	vector<vector<int> > frq(lmt, vector<int>(n + 1));
	vector<vector<int> > occ(lmt);
	for (int lvl = 0; lvl < lmt; lvl++)
	{
		frq[lvl][0] = 0;
		for (int i = 0; i < n; i++)
		{
			frq[lvl][i + 1] = frq[lvl][i] + (a[i] >= lvl + 1);
			if (a[i] >= lvl + 1)
				occ[lvl].push_back(i);
		}
	}

	for (int qn = 0; qn < q; qn++)
	{
		int idx, x;
		cin >> idx >> x;
		idx--;

		bool ans = false;
		if (x <= criteria)
		{
			int l = upper_bound(lvlup[x - 1].begin(), lvlup[x - 1].end(), idx) - lvlup[x - 1].begin();
			ans = l + 1 <= a[idx];
		}
		else
		{
			int l = 0;
			for (int i = 0; i < idx; )
			{
				int z = frq[l][i] + x;
				if (z <= occ[l].size() && occ[l][z - 1] < idx)
				{
					i = occ[l][z - 1] + 1;
					l++;
				}
				else
					break;
			}

			ans = l + 1 <= a[idx];
		}

		cout << (ans ? "YES" : "NO") << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	solve();

	return 0;
}
