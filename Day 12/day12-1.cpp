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

int n, m;

int dir[4][2] = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> v;

set<pair<lli, lli>> visited;
lli dfs(lli i, lli j, vector < string >& grid, char required) {

	if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size()) return 1;

	if (grid[i][j] == '*') return 0;
	if (grid[i][j] !=  required) {

		return 1;
	}
	visited.insert({i, j});
	grid[i][j] = '*';
	lli ret = 0;
	ret = dfs(i + 1, j, grid, required) + dfs(i, j + 1, grid, required) +  dfs(i - 1, j, grid, required) + dfs(i, j - 1, grid, required);
	return  ret;
}
lli Dfs2(lli i, lli j, vector<string>& grid, char required) {
	if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size()) return 0;
	if (grid[i][j] != required) return 0;
	grid[i][j] = '*';
	visited.insert({i, j});

	lli ret = 1;
	for (int k = 0; k < 4; k++) {
		ret += Dfs2(i + dir[k][0], j + dir[k][1], grid, required);
	}
	return ret;
}
void Solve() {
	lli ret = 0;
	string s;

	while (getline(cin, s)) {

		v.pb(s);

	}

	n = v.size();
	m = v[0].size();
	vector<string> grid;
	vector<pair<lli, lli>> data;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited.count({i, j})) {

				// done.insert(v[i][j]);

				grid = v;
				lli area = Dfs2(i, j, grid, v[i][j]);

				grid = v;
				lli perimeter = dfs(i, j, grid, v[i][j]);

				data.pb({area, perimeter});
			}
		}
	}

	for (auto& it : data) {

		ret += it.ff * it.ss ;
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



