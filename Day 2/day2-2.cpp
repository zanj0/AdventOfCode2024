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
bool IsGood(lli x) {
	return x >= 1 && x <= 3;
}
bool IsSafe(vector<lli>& v) {


	lli n = v.size();

	for (int j = 0; j < n; j++) {
		bool ok = true;
		bool dec = false, inc = false;
		lli last = -1;
		for (int i = 0; i < n && ok; i++) {
			if (i == j) continue;
			else if (last == -1) {
				last = v[i];
			} else if (!dec && !inc) {
				if (last == v[i]) ok = false;
				else if (IsGood(last - v[i])) dec = true;
				else if (IsGood(v[i] - last)) inc = true;
				else ok = false;
			}
			else {
				if (inc) {

					if (!IsGood(v[i] - last)) ok = false;;
				} else {
					if (!IsGood(last - v[i])) ok = false;;
				}
			}

			last = v[i];
		}
		if (ok) return true;
	}
	return false;
}
void Solve() {
	string s;

	lli ret = 0;
	while (getline(cin, s)) {


		vector<string> v = Split(s, ' ');
		vector<lli> v2;
		for (auto& it : v) {
			v2.pb(stol(it));
		}
		ret += IsSafe(v2);
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
