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
vector<lli> CreateFile(string& s) {
	vector<lli> ret ;
	bool file = true;
	int cnt = 0;
	for (auto& it : s) {
		int val = it - '0';
		if (file) {
			while (val--) {
				ret.pb(cnt);
			}
			cnt++;
		} else {
			while (val --) {
				ret.pb(-1);
			}
		}
		file = !file;
	}

	return ret;
}
void Solve() {
	lli ret = 0;
	string s;

	cin >> s;
	vector<lli> s2 = CreateFile(s);
	int i = 0, j = s2.size() - 1;
	n = s2.size();
	for (int j = n - 1; j >= 0; j--) {
		if (s2[j] == -1) {
			continue;
		}
		int k = j;
		int len = 1;
		while (k >= 0 && s2[k] == s2[j]) {
			k--;
			len++;
		}
		len--;
		k++;

		j = k;

		int temp = 0;

		for (int i = 0; i <= k; i++) {
			if (s2[i] == -1) {
				temp++;
			} else temp = 0;
			if (temp == len) {
				for (int l = i - temp + 1; l <= i; l++) {
					s2[l] = s2[j];
				}
				for (int l = k; l <= k + len - 1 ; l++) {
					s2[l] = -1;
				}
				break;

			}
		}

	}
	for (lli i = 0; i < s2.size(); i++) {
		if (s2[i] == -1) continue;
		ret += (lli)(s2[i]) * i;

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



