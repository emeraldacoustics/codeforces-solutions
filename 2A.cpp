#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	map<string, int> namemap;
	vector<string> namev;
	vector<pair<int, int> > rndv;
	vector<int> ptv;

	int n;
	cin >> n;
	for (int rn = 0; rn < n; rn++)
	{
		string name;
		int scr;
		cin >> name >> scr;

		int idx;
		const auto itr = namemap.find(name);
		if (itr == namemap.end())
		{
			namemap[name] = idx = namev.size();
			namev.push_back(name);
			ptv.push_back(0);
		}
		else
			idx = itr->second;

		ptv[idx] += scr;

		rndv.emplace_back(idx, scr);
	}

	int mxp = *max_element(ptv.begin(), ptv.end());
	int ans = -1;

	vector<int> scr(ptv.size(), 0);
	for (const auto & rnd : rndv)
	{
		scr[rnd.first] += rnd.second;

		if (ptv[rnd.first] == mxp && scr[rnd.first] >= mxp)
		{
			ans = rnd.first;
			break;
		}
	}

	cout << namev[ans] << endl;

	return 0;
}