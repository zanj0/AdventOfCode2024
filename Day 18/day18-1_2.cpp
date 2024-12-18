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
vector<vector<lli>> bad;
vector<vector<lli>> Bfs(pair<lli, lli> src, vector<string>& grid) {
	vector<vector<lli>> ret(n, vector<lli>(m, inf));
	ret[src.ff][src.ss] = 0;
	queue<pair<lli, lli>> q;
	q.push(src);
	while (!q.empty()) {
		pair<lli, lli> curr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			lli ni = curr.ff + dir[i][0];
			lli nj = curr.ss + dir[i][1];
			if (IsInside(ni, nj) && ret[ni][nj] > ret[curr.ff][curr.ss] + 1 && grid[ni][nj] == '.') {
				ret[ni][nj] = ret[curr.ff][curr.ss] + 1;
				q.push({ni, nj});
			}
		}
	}
	return ret;
}
void Solve() {

	string s;
	n = 71;
	m = 71;
	lli k = 1024;
	lli ret = -1;

	vector<string> grid (n, string(n, '.'));

	while (getline(cin, s)) {

		vector<lli> v = Convert(s, ',');

		swap(v[0], v[1]);

		bad.pb(v);

	}


	for (int i = 0; i < k; i++) {
		grid[bad[i][0]][bad[i][1]] = '#';
	}

	vector<vector<lli>> dist = Bfs({0, 0}, grid);
	ret = dist[n - 1][m - 1];
	cout << "Part 1: " << ret << endl;

	for (int i = 0; i < k; i++) {
		grid[bad[i][0]][bad[i][1]] = '.';
	}

	lli low = 0, high = bad.size() - 1;
	pair<lli, lli> temp = { -1, -1};
	while (low <= high) {
		lli mid = low + (high - low) / 2;

		for (int i = 0; i <= mid; i++) {
			grid[bad[i][0]][bad[i][1]] = '#';
		}
		vector<vector<lli>> dist = Bfs({0, 0}, grid);
		for (int i = 0; i <= mid; i++) {
			grid[bad[i][0]][bad[i][1]] = '.';
		}
		if (dist[n - 1][m - 1] == inf) {
			temp = {bad[mid][0], bad[mid][ 1]};
			high = mid - 1;
		} else low = mid + 1;
	}
	swap(temp.ff, temp.ss);
	cout << "Part 2: " << temp.ff << " " << temp.ss << endl;
}

int32_t main()
{
	zanj0();
	Solve();
	timetaken;
	return 0;
}



