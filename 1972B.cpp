#include <algorithm>
#include <iostream>
#include <string>

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

		string s;
		cin >> s;

		cout << (count(s.begin(), s.end(), 'U') % 2 ? "YES" : "NO") << endl;
	}

	return 0;
}
