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
		cout << it << " ";
	}
	cout << endl;
}

void Out(vector<lli>& v) {
	for (auto& it : v) {
		cout << it << " ";
	}
	cout << endl;
}

set<string> has;

void Solve() {
	lli ret = 0;
	string s;
	vector<vector<lli>> v2;


	while (getline(cin, s)) {
		if (s.find('|') != string::npos) {
			has.insert(s);
		} else {
			vector<string> v = Split(s, ',');
			if (v.empty()) continue;
			vector<lli> temp;
			for (auto& it : v) {
				temp.pb(stol(it));
			}
			v2.pb(temp);
		}
	}
	for (auto& it : v2) {
		bool good = true;
		for (int i = 0; i < it.size() && good; i++) {
			for (int j = i + 1; j < it.size() && good; j++) {
				string now = "";
				now += to_string(it[i]);
				now += '|';
				now += to_string(it[j]);
				if (!has.count(now))good = false;
			}
		}
		if (good) {
			continue;
		} else {
			set<int> visited;
			vector<lli> path;
			int n = it.size();
			while (path.size() < it.size()) {

				for (int i = 0; i < n; i++) {
					if (visited.count(i)) continue;
					bool good = true;
					for (int j = 0; j < n && good; j++) {
						if (i == j) continue;
						if (visited.count(j)) continue;
						string now = "";
						now += to_string(it[i]);
						now += '|';
						now += to_string(it[j]);
						if (!has.count(now))good = false;
					}
					if (good) {
						visited.insert(i);
						path.pb(it[i]);
						break;
					}
				}
			}
			if (!path.empty())
				ret += path[path.size() / 2] ;
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

