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

vector<string> v;

lli GetCheck(lli sx, lli sy) {
	string temp = "";
	if (sx && sy && sx + 1 < v.size() && sy + 1 < v[0].size()) {
		string temp1 = "";
		temp1 += min(v[sx - 1][sy - 1], v[sx + 1][sy + 1]);
		temp1 +=  v[sx][sy];
		temp1 +=  max(v[sx - 1][sy - 1], v[sx + 1][sy + 1]);

		string temp2 = "";
		temp2 += min(v[sx + 1][sy - 1], v[sx - 1][sy + 1]);
		temp2 += v[sx][sy];
		temp2 += max(v[sx + 1][sy - 1], v[sx - 1][sy + 1]);

		return temp1 == temp2 && temp1 == "MAS";
	}
	return 0;
}
void Solve() {
	string s;

	lli ret = 0;

	while (getline(cin, s)) {
		v.pb(s);
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			lli val = GetCheck(i, j);

			ret += val;
		}
	}

	cout << ret  << endl;
}
int32_t main()
{
	zanj0();
	Solve();

	timetaken;
	return 0;
}

