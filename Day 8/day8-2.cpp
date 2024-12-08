/*
	JAI JAGANNATH!
*/
//@Author : zanj0

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set =  __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define LOCAL
#define ff              first
#define ss              second
#define pb              push_back
#define MOD             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
#define endl       		"\n"
#define timetaken cerr<<"Time : "<<1000*(long double)clock()/(long double)CLOCKS_PER_SEC<<"ms\n"

typedef long long int lli;

void zanj0()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

vector<string> Split(string& s, char delimeter) {
	string temp = "";
	vector<string> ret;
	for (auto& it : s) {
		if (it == delimeter) {
			if (!temp.empty())ret.pb(temp);
			temp = "";
		} else temp += it;
	}
	if (!temp.empty())ret.pb(temp);
	return ret;
}

void Out(vector<string>& v) {
	for (auto& it : v) {
		cout << it << endl;
	}
	cout << endl;
}

void Out(vector<lli>& v) {
	for (auto& it : v) {
		cout << it << " ";
	}
	cout << endl;
}

int n, m;

bool IsInside(int i, int j) {
	return (i >= 0 && i < n) && (j >= 0 && j < m);
}

int dir[4][2] = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<string> v;

vector<lli> Convert(vector<string>& v) {
	vector<lli> ret;
	for (auto& it : v) {
		ret.pb(stol(it));
	}
	return ret;
}

vector<lli> Convert(string s, char delimeter) {
	vector<string> v = Split(s, delimeter);
	return Convert(v);
}

lli GetDistance(pair<lli, lli> a, pair<lli, lli> b) {
	return abs(a.ff - b.ff) + abs(a.ss - b.ss);
}

pair<lli, lli> GetSlope(pair<lli, lli> a, pair<lli, lli> b) {
	pair<lli, lli> ret = {(b.ss - a.ss), (b.ff - a.ff)};
	lli g = gcd(abs(ret.ff), abs(ret.ss));
	ret.ff /= g;
	ret.ss /= g;
	return ret;

}
void CreateAntinode(vector<pair<lli, lli>>& points) {
	for (int i = 0; i < points.size(); i++) {
		for (int j = i + 1; j < points.size(); j++) {
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < m; y++) {
					lli dist_1 = GetDistance({x, y}, points[i]);
					lli dist_2 = GetDistance({x, y}, points[j]);

					pair<lli, lli> slope_1 = GetSlope({x, y}, points[i]);
					pair<lli, lli> slope_2 = GetSlope({x, y}, points[j]);
					if (slope_1 != slope_2) continue;

					v[x][y] = '#';

				}
			}
		}
	}
}
void Solve() {
	lli ret = 0;
	string s;
	map<char, vector<pair<lli, lli>>> idx;


	while (getline(cin, s)) {
		v.pb(s);
	}

	n = v.size();
	m = v[0].size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (isalpha(v[i][j]) || isdigit(v[i][j])) {
				idx[v[i][j]].pb({i, j});
			}
		}
	}

	for (auto& it : idx) {
		CreateAntinode(it.ss);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ret += v[i][j] != '.';
		}
	}

	cout << ret << endl;
}

int32_t main()
{
	zanj0();
	Solve();
	timetaken;
	return 0;
}



