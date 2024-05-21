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

		string b;
		cin >> b;

		vector<bool> vis(26, false);
		for (const auto & c : b)
			vis[c - 'a'] = true;
		
		vector<int> r;
		for (int i = 0; i < 26; i++)
		{
			if (vis[i])
				r.push_back(i);
		}

		vector<int> v(26, -1);
		for (int i = 0; i < r.size(); i++)
			v[r[i]] = r[r.size() - i - 1];

		string s;
		for (const auto & c : b)
			s.push_back(v[c - 'a'] + 'a');
		
		cout << s << endl;
	}

	return 0;
}
