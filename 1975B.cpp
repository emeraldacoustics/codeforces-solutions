#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
T gcd(const T & a, const T & b)
{
	return a ? gcd(b % a, a) : b;
}

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int x = *min_element(a.begin(), a.end());
		vector<int> b;
		for (const auto & z : a)
		{
			if (z % x)
				b.push_back(z);
		}

		bool ans = true;
		if (!b.empty())
		{
			int g = 0;
			for (const auto & z : b)
				g = gcd(g, z);
			
			if (find(a.begin(), a.end(), g) == a.end())
				ans = false;
		}

		cout << (ans ? "YES" : "NO") << endl;
	}

	return 0;
}
