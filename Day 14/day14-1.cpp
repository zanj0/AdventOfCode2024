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

pair<lli, lli> GetCoordinate(string& s) {
	vector<string>  v = Split(s, '=');
	v = Split(v[1], ',');
	return {stol(v[0]), stol(v[1])};
}

void Process(pair<lli, lli>& a, pair<lli, lli>& b) {
	lli k = 100;
	while (k--) {
		a.ff += b.ff;
		a.ss += b.ss;

		a.ff += n;
		a.ff %= n;

		a.ss += m;
		a.ss %= m;


	}
}
void Solve() {
	lli ret = 0;
	string s;
	n = 101, m = 103;
	lli first_quad = 0, second_quad = 0, third_quad = 0 , fourth_quad = 0;
	while (getline(cin, s)) {
		vector<string> v = Split(s, ' ');

		pair<lli, lli> left = GetCoordinate(v[0]);
		pair<lli, lli> right = GetCoordinate(v[1]);


		Process(left, right);

		swap(left.ff, left.ss);

		if (left.ff == (m - 1) / 2 || left.ss == (n - 1) / 2) continue;

		if (left.ff < (m - 1) / 2 && left.ss < (n - 1) / 2 ) first_quad++;
		else if (left.ff > (m - 1) / 2 && left.ss < (n - 1) / 2) third_quad++;
		else if (left.ff > (m - 1) / 2 && left.ss > (n - 1) / 2) fourth_quad++;
		else second_quad++;

	}

	ret = first_quad * second_quad * third_quad * fourth_quad;

	cout << ret << endl;
}

int32_t main()
{
	zanj0();
	Solve();
	timetaken;
	return 0;
}
