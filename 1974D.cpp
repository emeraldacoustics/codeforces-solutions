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

		int x = 0, y = 0;
		int nidx = -1, sidx = -1, eidx = -1, widx = -1;
		for (int i = 0; i < s.length(); i++)
		{
			const auto & c = s[i];
			if (c == 'N')
			{
				y++;
				nidx = i;
			}
			else if (c == 'S')
			{
				y--;
				sidx = i;
			}
			else if (c == 'E')
			{
				x++;
				eidx = i;
			}
			else if (c == 'W')
			{
				x--;
				widx = i;
			}
		}

		if (x % 2 || y % 2)
			cout << "NO";
		else
		{
			int rx = 0, ry = 0;
			x /= 2, y /= 2;
			string p;
			for (const auto & c : s)
			{
				bool r = false;
				if (c == 'N' || c == 'S')
				{
					r = c == 'N' && ry < y || c == 'S' && ry > y;
					if (r)
						ry += c == 'N' ? 1 : -1;
				}
				else if (c == 'E' || c == 'W')
				{
					r = c == 'E' && rx < x || c == 'W' && rx > x;
					if (r)
						rx += c == 'E' ? 1 : -1;
				}
				p.push_back(r ? 'R' : 'H');
			}
			
			int r = count(p.begin(), p.end(), 'R');
			if (r == 0 || r == p.length())
			{
				if (nidx >= 0 && sidx >= 0)
					p[nidx] = p[sidx] = r ? 'H' : 'R';
				else if (eidx >= 0 && widx >= 0)
					p[eidx] = p[widx] = r ? 'H' : 'R';
			}

			r = count(p.begin(), p.end(), 'R');
			if (r == 0 || r == p.length())
				cout << "NO";
			else
				cout << p;
		}
		cout << endl;
	}

	return 0;
}
