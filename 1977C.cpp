#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <class T>
T gcd(const T & a, const T & b)
{
	return a ? gcd(b % a, a) : b;
}


template <class T>
vector<T> get_divisors(T n)
{
	vector<T> ans, tmp;
	for (T i = 1; i <= n / i; i++)
	{
		if (n % i == 0)
		{
			ans.push_back(i);
			if (i * i != n)
				tmp.push_back(n / i);
		}
	}
	reverse(tmp.begin(), tmp.end());
	ans.insert(ans.end(), tmp.begin(), tmp.end());

	return ans;
}

int nikita_and_lcm(const vector<int> & a)
{
	int z = *max_element(a.begin(), a.end());

	set<int> s;
	for (const auto & x : a)
	{
		if (z % x)
			return a.size();

		s.insert(x);
	}

	auto v = get_divisors(z);
	int ans = 0;
	for (const auto & l : v)
	{
		if (s.count(l))
			continue;
		
		int lcm = 1, cnt = 0;
		for (const auto & x : a)
		{
			if (l % x == 0)
			{
				cnt++;
				lcm = lcm / gcd(lcm, x) * x;
			}
		}

		if (lcm == l)
			ans = max(ans, cnt);
	}

	return ans;
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
		
		cout << nikita_and_lcm(a) << endl;
	}

	return 0;
}
