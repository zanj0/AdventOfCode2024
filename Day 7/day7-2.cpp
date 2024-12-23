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

bool GetScore(lli idx, vector<lli>& v, lli temp ,  lli need) {
	if (temp > need) return false;

	if (idx >= v.size()) {
		return temp == need;
	}

	string s = to_string(temp);

	s += to_string(v[idx]);

	return GetScore(idx + 1, v, stol(s), need) || GetScore(idx + 1, v, temp * v[idx], need) || GetScore(idx + 1, v, temp + v[idx],  need);
}
void Solve() {
	lli ret = 0;
	string s;

	while (getline(cin, s)) {


		vector<string> v = Split(s, ':');

		v[1].erase(v[1].begin());

		vector<string> v2 = Split(v[1], ' ');

		vector<lli> v3;

		for (auto& it : v2)v3.pb(stol(it));

		lli need = stol(v[0]);

		if (GetScore(1, v3, v3[0], need)) {
			ret += need;
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



