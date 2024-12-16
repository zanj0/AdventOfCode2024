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
int dir[4][2] = {{ 0, 1}, {0, -1}, {1, 0}, { -1, 0}};
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
struct Data {
	lli cost, x, y, dir;
};
struct Comparator {
	bool operator()(Data& a, Data& b) {
		return !(a.cost < b.cost);
	}
};
map<array<lli, 3>, lli> Dijkstra(pair<lli, lli> curr, pair<lli, lli> target, lli dir_idx = 0) {
	priority_queue<Data, vector<Data>, Comparator> pq;
	pq.push({0, curr.ff, curr.ss, dir_idx});
	map<array<lli, 3>, lli> distance;
	while (!pq.empty()) {

		Data now = pq.top();
		pq.pop();
		if (!IsInside(now.x, now.y) || v[now.x][now.y] == '#') continue;
		array<lli, 3> temp = {now.x, now.y, now.dir};
		if (distance.count(temp)) continue;

		distance[temp] = now.cost;


		// Go in same direction
		Data n_temp;

		n_temp.x = now.x + dir[now.dir][0];
		n_temp.y = now.y + dir[now.dir][1];
		n_temp.cost = now.cost + 1;
		n_temp.dir = now.dir;

		if (!distance.count({n_temp.x, n_temp.y, n_temp.dir})) pq.push(n_temp);

		// Rotate
		if (now.dir == 0 || now.dir == 1) {
			n_temp.x = now.x ;
			n_temp.y = now.y ;
			n_temp.cost = now.cost + 1000;
			n_temp.dir = 2;
			if (!distance.count({n_temp.x, n_temp.y, n_temp.dir})) pq.push(n_temp);
			n_temp.dir = 3;
			if (!distance.count({n_temp.x, n_temp.y, n_temp.dir})) pq.push(n_temp);
		} else {
			n_temp.x = now.x ;
			n_temp.y = now.y ;
			n_temp.cost = now.cost + 1000;
			n_temp.dir = 0;
			if (!distance.count({n_temp.x, n_temp.y, n_temp.dir})) pq.push(n_temp);
			n_temp.dir = 1;
			if (!distance.count({n_temp.x, n_temp.y, n_temp.dir})) pq.push(n_temp);
		}
	}

	return distance;
}

void Solve() {

	string s;

	while (getline(cin, s)) {

		v.pb(s);
	}

	n = v.size();
	m = v[0].size();

	pair<lli, lli> curr, target;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'S') {
				curr = {i, j};
			}
			if (v[i][j] == 'E') {
				target = {i, j};
			}
		}
	}

	map<array<lli, 3>, lli> distance_1 = Dijkstra(curr, target);
	lli best = inf;
	lli dir_idx = -1;
	for (int i = 0; i < 4; i++) {
		if (distance_1.count({target.ff, target.ss, i})) {

			if (distance_1[ {target.ff, target.ss, i}] < best) {
				best = distance_1[ {target.ff, target.ss, i}];
				dir_idx = i;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		dir[i][0] *= -1;
		dir[i][1] *= -1;

	}

	map<array<lli, 3>, lli> distance_2 = Dijkstra(target, curr, dir_idx);


	set<pair<lli, lli>> all;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				array<lli, 3> temp = {i, j, k};
				if (distance_1.count(temp) && distance_2.count(temp) && distance_1[temp] + distance_2[temp] == best) {
					all.insert({i, j});
				}
			}

		}
	}

	cout << "Part 1: " << best << endl;
	cout << "Part 2: " << all.size() << endl;

}

int32_t main()
{
	zanj0();
	Solve();
	timetaken;
	return 0;
}



