#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	int ans = 0;
	for (int i = 0; i < n; )
	{
		if (a[i] == 0)
			i++;
		else if (a[i] <= 2)
		{
			bool flg = false;
			int k = i + 1;
			for (; k < n; )
			{
				if (a[k] == 0)
					break;

				if (a[k] <= 2)
				{
					flg = true;
					k++;
					break;
				}
				else if (k + 1 < n && a[k] <= 4 && 0 < a[k + 1] && a[k + 1] <= 4)
					k += 2;
				else
					break;
			}
			ans += (k - i) - flg;
			i = k;
		}
		else
		{
			ans++;
			i++;
		}
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
