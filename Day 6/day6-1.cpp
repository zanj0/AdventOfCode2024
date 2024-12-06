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

void Solve() {
	lli ret = 0;
	string s;

	while (getline(cin, s)) {

		v.pb(s);

	}
	pair<lli, lli> curr;
	n = v.size();
	m = v[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '^') {
				curr = {i, j};
				break;
			}
		}
	}

	lli max_moves = 200 * 200;
	int k = 0;

	while (max_moves-- && IsInside(curr.ff , curr.ss)) {

		v[curr.ff][curr.ss] = 'X';
		pair<lli, lli> nxt;
		nxt = curr;
		nxt.ff += dir[k][0];
		nxt.ss += dir[k][1];
		if (!IsInside(nxt.ff, nxt.ss)) break;
		if (v[nxt.ff][nxt.ss] == '#') {
			k = (k + 1) % 4;
			continue;
		}
		curr = nxt;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ret += v[i][j] == 'X';
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


