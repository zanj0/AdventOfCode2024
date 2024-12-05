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
// string Get
vector<pair<lli, lli>> Split(string& s, string x) {
	string temp = "";
	vector<pair<lli, lli>> ret;
	deque<char> dq;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		dq.push_back(s[i]);
		if (dq.size() == 4) {

			string temp = "";
			temp += dq[0];
			temp += dq[1];
			temp += dq[2];
			temp += dq[3];
			if (temp == "mul(") {
				// cout << i << endl;
				string first_num = "";
				string second_num = "";
				int j = i + 1;
				bool ok = true;
				while (j < min(i + 4, n) && s[j] >= '0' && s[j] <= '9') {
					first_num += s[j];
					j++;
				}
				// cout << first_num << endl;
				if (j < n && s[j] == ',') {
					j++;
				} else ok = false;
				// cout << ok << endl;
				lli last_j = j;
				while (j < min(last_j + 4, (lli)n) && s[j] >= '0' && s[j] <= '9') {
					second_num += s[j];
					j++;
				}
				if (j < n && s[j] == ')') {

				} else ok = false;
				if (ok) {
					i = j;
					ret.pb({stol(first_num), stol(second_num)});
				}
			}
		}
		if (dq.size() > 3) dq.pop_front();
	}
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
void Solve() {
	string s;

	lli ret = 0;
	while (getline(cin, s)) {
		vector<pair<lli, lli>> v = Split(s, "mul");
		for (auto& it : v) {
			ret += it.ff * it.ss;
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
