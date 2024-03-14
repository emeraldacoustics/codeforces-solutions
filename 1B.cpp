#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

string transform(const string & s)
{
	int r = find(s.begin(), s.end(), 'R') - s.begin();
	int c = find(s.begin(), s.end(), 'C') - s.begin();
	int d = 0;
	for (const auto & c : s)
	{
		if (isdigit(c))
			d++;
	}

	stringstream ans;
	if (r == 0 && 2 <= c && c < s.length() && d == s.length() - 2)
	{
		int row = stoi(s.substr(1, c - 1));
		int col = stoi(s.substr(c + 1, s.length() - c - 1));

		int x = 0, z = 1;
		for (; col >= z; x++, col-= z, z *= 26);

		string c;
		for (z /= 26; x > 0; x--, col %= z, z /= 26)
			c += 'A' + col / z;
		
		ans << c << row;
	}
	else
	{
		int x = 0;
		for (; x < s.length() && isalpha(s[x]); x++);

		int row = stoi(s.substr(x, s.length() - x));
		int col = 0;
		for (int i = 0, z = 1; i < x; i++, z *= 26)
			col += z * (s[x - i - 1] - 'A' + 1);

		ans << 'R' << row << 'C' << col;
	}

	return ans.str();
}

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int t = 0; t < n; t++)
	{
		string s;

		cin >> s;

		cout << transform(s) << endl;
	}

	return 0;
}