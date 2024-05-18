#include <algorithm>
#include <iostream>
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
		vector<int> p(n);
		for (int i = 0; i < n; i++)
			cin >> p[i];

		int x = 0;
		for (int i = 0; i < n; i++)
		{
			p[i]--;
			if (p[i] == 0)
				x = i % 2;
		}

		vector<int> z(n);
		for (int k = 0; k < 2; k++)
		{
			vector<int> v;
			for (int i = k; i < n; i += 2)
				v.push_back(p[i]);
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size(); i++)
				z[v[i]] = (k == x ? n / 2 : n) - i - 1;
		}

		vector<int> q(n);
		for (int i = 0; i < n; i++)
			q[i] = z[p[i]];

		for (int i = 0; i < n; i++)
		{
			if (i > 0)
				cout << " ";
			cout << q[i] + 1;
		}
		cout << endl;
	}

	return 0;
}
