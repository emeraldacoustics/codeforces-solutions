#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

template <class T>
T gcd(const T & a, const T & b)
{
	return a ? gcd(b % a, a) : b;
}

template <class T>
vector<T> get_primes(T n)
{
	vector<T> ans;
	for (T i = 2; i <= n / i; i++)
	{
		if (n % i == 0)
		{
			ans.push_back(i);
			for (; n % i == 0; n /= i);
		}
	}
	if (n > 1)
		ans.push_back(n);

	return ans;
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

int main()
{
	ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];

	vector<pair<long long, int> > pre;
	for (int z = 0; z < 2; z++)
	{
		vector<int> vpa = get_primes(a[0]);
		vector<int> vda = get_divisors(a[0]);
		vector<int> vpb = get_primes(b[0]);
		vector<int> vdb = get_divisors(b[0]);

		map<int, int> mda, mdb;
		for (int i = 0; i < vda.size(); i++)
			mda[vda[i]] = i;
		for (int i = 0; i < vdb.size(); i++)
			mdb[vdb[i]] = i;

		vector<vector<int> > f(vda.size(), vector<int>(vdb.size(), 0));
		vector<vector<long long> > s(vda.size(), vector<long long>(vdb.size(), 0));
		f[vda.size() - 1][vdb.size() - 1] = 1;
		s[vda.size() - 1][vdb.size() - 1] = c[0] * z;

		for (int i = 1; i < n; i++)
		{
			int x = gcd(a[0], gcd(a[i], b[i])), y = gcd(b[0], gcd(a[i], b[i]));
			f[mda[x]][mdb[y]]--;
			s[mda[x]][mdb[y]] -= c[i];

			x = gcd(a[0], a[i]);
			y = gcd(b[0], b[i]);
			f[mda[x]][mdb[y]]++;

			x = gcd(a[0], b[i]);
			y = gcd(b[0], a[i]);
			f[mda[x]][mdb[y]]++;
			s[mda[x]][mdb[y]] += c[i];
		}

		for (const auto & p : vpa)
		{
			for (int i = vda.size() - 1; i >= 0; i--)
			{
				if (vda[i] % p == 0)
				{
					int k = mda[vda[i] / p];
					for (int j = 0; j < vdb.size(); j++)
					{
						f[k][j] += f[i][j];
						s[k][j] += s[i][j];
					}
				}
			}
		}
		for (const auto & p : vpb)
		{
			for (int j = vdb.size() - 1; j >= 0; j--)
			{
				if (vdb[j] % p == 0)
				{
					int k = mdb[vdb[j] / p];
					for (int i = 0; i < vda.size(); i++)
					{
						f[i][k] += f[i][j];
						s[i][k] += s[i][j];
					}
				}
			}
		}
		for (int i = 0; i < vda.size(); i++)
		{
			for (int j = 0; j < vdb.size(); j++)
			{
				if (f[i][j] == n)
					pre.emplace_back(s[i][j], vda[i] + vdb[j]);
			}
		}

		swap(a[0], b[0]);
	}
	sort(pre.begin(), pre.end());
	int mx = 0;
	for (auto & p : pre)
	{
		mx = max(mx, p.second);
		p.second = max(p.second, mx);
	}
	pre.resize(unique(pre.begin(), pre.end()) - pre.begin());

	for (int qn = 0; qn < q; qn++)
	{
		long long d;
		cin >> d;

		if (qn > 0)
			cout << " ";
		cout << (lower_bound(pre.begin(), pre.end(), make_pair(d + 1, 0)) - 1)->second;
	}
	cout << endl;

	return 0;
}
