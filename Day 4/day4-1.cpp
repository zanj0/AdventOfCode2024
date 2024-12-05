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
lli GetCheck(lli sx, lli sy, lli dx, lli dy, string& required) {
	string temp = "";
	while (sx >= 0 && sx < v.size() && sy >= 0 && sy < v[sx].size() && temp.size() < 4) {
		temp += v[sx][sy];
		sx += dx;
		sy += dy;
	}
	return temp == required;
}
void Solve() {
	string s;
	lli ret = 0;

	while (getline(cin, s)) {
		v.pb(s);
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			for (lli dx = -1; dx <= 1; dx++) {
				for (lli dy = -1; dy <= 1; dy++) {
					if (dx == 0 && dy == 0) continue;
					string now = "XMAS";

					ret += GetCheck(i, j, dx, dy, now);
					reverse(now.begin(), now.end());

					ret += GetCheck(i, j, dx, dy, now);
				}
			}
		}
	}

	assert(ret % 2 == 0);
	cout << ret / 2 << endl;
}
int32_t main()
{
	zanj0();
	Solve();

	timetaken;
	return 0;
}

