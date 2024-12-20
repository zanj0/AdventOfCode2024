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
		cout << ((it == inf) ? "I" : to_string(it)) << " ";
	}
	cout << endl;
}

void Out(vector<vector<lli>>& v) {
	for (auto& it : v) {
		Out(it);
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
lli ret = inf;
lli best = inf;
vector<vector<lli>> bad;
vector<vector<lli>> Bfs(pair<lli, lli> src, pair<lli, lli> dest, vector<string>& grid) {
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
			if (IsInside(ni, nj) && ret[ni][nj] > ret[curr.ff][curr.ss] + 1 && grid[ni][nj] != '#') {
				ret[ni][nj] = ret[curr.ff][curr.ss] + 1;
				q.push({ni, nj});
			}
		}
	}
	return ret;
}
void Solve(lli x) {
	string s;

	while (getline(cin, s)) {

		v.pb(s);

	}
	n = v.size();
	m = v[0].size();
	pair<lli, lli> src, dest;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'S') {
				src = {i, j};
			} else if (v[i][j] == 'E') {
				dest = {i, j};
			}
		}
	}


	vector<vector<lli>> dist = Bfs(src, dest, v);
	vector<vector<lli>> aux = Bfs(dest, src, v);

	best = ret = dist[dest.ff][dest.ss];

	map<lli, lli> cnt;
	lli ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] != '#') {
				if (dist[i][j] == inf) continue;
				queue<pair<lli, lli>> q;
				q.push({i, j});
				set<pair<lli, lli>> neighbours;
				for (int k = 0; k < x; k++) {
					int sz = q.size();
					while (sz--) {
						pair<lli, lli> curr = q.front();
						q.pop();
						neighbours.insert(curr);
						for (int l = 0; l < 4; l++) {
							int ni = curr.ff + dir[l][0];
							int nj = curr.ss + dir[l][1];
							if (IsInside(ni, nj)) {
								if (neighbours.count({ni, nj})) continue;
								neighbours.insert({ni, nj});
								q.push({ni, nj});
							}
						}
					}

				}
				while (!q.empty()) {
					neighbours.insert(q.front());
					q.pop();
				}
				for (auto& it : neighbours) {

					if (v[it.ff][it.ss] != '#') {

						lli now = dist[i][j] + abs(it.ff - i) + abs(it.ss - j) + aux[it.ff][it.ss] ;

						ans += (ret - now) >= 100;
					}
				}
			}

		}
	}


	cout << ans << endl;
}

int32_t main()
{
	zanj0();
	Solve(2);
	Solve(20);
	timetaken;
	return 0;
}



