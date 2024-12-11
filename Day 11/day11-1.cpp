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
#define w(x)            lli x; cin>>x; while(x--)
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


vector<string> v;


string Multiply(string nums1, string nums2) {
	lli n = nums1.size();
	lli m = nums2.size();
	assert(max(n, m) <= 1e6);
	string ans(n + m, '0');
	for (lli i = n - 1; i >= 0; i--) {
		for (lli j = m - 1; j >= 0; j--) {
			lli p = (nums1[i] - '0') * (nums2[j] - '0') + (ans[i + j + 1] - '0');
			ans[i + j + 1] = p % 10 + '0';
			ans[i + j] += p / 10 ;
		}
	}
	for (lli i = 0; i < m + n; i++) {
		if (ans[i] != '0')return ans.substr(i);
	}
	return "0";
}

string RemoveLeadingZero(string& s) {
	reverse(s.begin(), s.end());
	while (s.back() == '0') s.pop_back();
	if (s.empty()) {
		return "0";
	}
	reverse(s.begin(), s.end());
	return s;
}

map<string, map<lli, lli>> dp;

lli Split(string s, lli counter) {

	if (counter == 0) {
		return 1;
	}

	if (dp.count(s) && dp[s].count(counter)) return dp[s][counter];

	if (s == "0") {
		return dp[s][counter] = Split("1", counter - 1);
	}

	lli n = s.size();

	if (n % 2 == 0) {
		string first_half = s.substr(0, n / 2);
		string second_half = s.substr(n / 2);

		first_half = RemoveLeadingZero(first_half);
		second_half = RemoveLeadingZero(second_half);

		return Split(first_half, counter - 1)
		       + Split(second_half, counter - 1);
	}

	return dp[s][counter] = Split(Multiply(s, "2024"), counter - 1);
}
void Solve() {
	lli ret = 0;
	string s;

	while (getline(cin, s)) {
		v = Split(s, ' ');

	}

	for (auto& it : v) {
		ret += Split(it, (lli)25);
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



