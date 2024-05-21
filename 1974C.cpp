#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		long long ans = 0;
		map<long long, int> M;
		for (int i = 0; i < n - 2; i++)
			M[a[i] << 20 | a[i + 1]]++;
		for (const auto & it : M)
			ans = ans + (long long)it.second * (it.second - 1) / 2;
		M.clear();
		
		for (int i = 0; i < n - 2; i++)
			M[a[i] << 20 | a[i + 2]]++;
		for (const auto & it : M)
			ans = ans + (long long)it.second * (it.second - 1) / 2;
		M.clear();

		for (int i = 0; i < n - 2; i++)
			M[a[i + 1] << 20 | a[i + 2]]++;
		for (const auto & it : M)
			ans = ans + (long long)it.second * (it.second - 1) / 2;
		M.clear();

		for (int i = 0; i < n - 2; i++)
			M[a[i] << 40 | a[i + 1] << 20 | a[i + 2]]++;
		for (const auto & it : M)
			ans = ans - (long long)it.second * (it.second - 1) / 2 * 3;

		cout << ans << endl;
	}

	return 0;
}
