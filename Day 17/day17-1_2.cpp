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
map<char, lli> registers;

vector<lli> Convert(string s, char delimeter) {
	vector<string> v = Split(s, delimeter);
	return Convert(v);
}
char GetOperand(lli value) {
	if (value >= 0 && value <= 3) return (char)('0' + value);
	if (value == 4) return 'A';
	if (value == 5) return 'B';
	return 'C';
}
int i = 0;

void Zero(lli operation, lli operand) {
	char operand_resolved = GetOperand(operand);
	lli times = (isdigit(operand_resolved)) ? operand_resolved - '0' : registers[operand_resolved];


	registers['A'] /= powl(2, times);

	i += 2;
}

void One(lli operation, lli operand) {
	char operand_resolved = GetOperand(operand);
	lli value = operand;
	registers['B'] = registers['B'] ^ value;
	i += 2;
}


void Two(lli operation, lli operand) {
	char operand_resolved = GetOperand(operand);
	lli value = (isdigit(operand_resolved)) ? operand_resolved - '0' : registers[operand_resolved];
	registers['B'] = value % 8;
	i += 2;
}

void Three(lli operation, lli operand) {
	char operand_resolved = GetOperand(operand);
	lli value = (isdigit(operand_resolved)) ? operand_resolved - '0' : registers[operand_resolved];

	if (registers['A'] == 0) i += 2;
	else i  = value;
}

void Four(lli operation, lli operand) {
	registers['B'] ^= registers['C'];
	i += 2;
}
vector<lli> ret;
void Five(lli operation, lli operand) {
	char operand_resolved = GetOperand(operand);
	lli value = (isdigit(operand_resolved)) ? operand_resolved - '0' : registers[operand_resolved];
	ret.pb(value % 8);
	i += 2;
}

void Six(lli operation, lli operand) {
	char operand_resolved = GetOperand(operand);
	lli times = (isdigit(operand_resolved)) ? operand_resolved - '0' : registers[operand_resolved];
	lli now = registers['A'];
	now /= powl(2, times);
	registers['B'] = now;
	i += 2;
}

void Seven(lli operation, lli operand) {
	char operand_resolved = GetOperand(operand);
	lli times = (isdigit(operand_resolved)) ? operand_resolved - '0' : registers[operand_resolved];
	lli now = registers['A'];
	now /= powl(2, times);
	registers['C'] = now;
	i += 2;
}

void Perform(lli operation, lli operand) {
	// cout << operation << " -- " << operand << endl;
	switch (operation) {
	case 0:
		Zero(operation, operand);
		return;
	case 1:
		One(operation, operand);
		return;
	case 2:
		Two(operation, operand);
		return;
	case 3:
		Three(operation, operand);
		return;
	case 4:
		Four(operation, operand);
		return;
	case 5:
		Five(operation, operand);
		return;
	case 6:
		Six(operation, operand);
		return;
	case 7:
		Seven(operation, operand);
		return;

	}
}

void Solve() {

	string s;

	getline(cin, s);
	v = Split(s, ' ');
	registers['A'] = stol(v.back());

	getline(cin, s);
	v = Split(s, ' ');
	registers['B'] = stol(v.back());

	getline(cin, s);
	v = Split(s, ' ');
	registers['C'] = stol(v.back());

	cin >> s;

	getline(cin, s);
	v = Split(s, ' ');
	vector<string> operations = Split(v.back(), ',');
	vector<lli> operationsll = Convert(operations);

	lli a = 1;
	lli a_val = a;

	while (i + 1 < operationsll.size()) {
		Perform(operationsll[i], operationsll[i + 1]);
	}
	cout << "Part 1: ";
	for (auto& it : ret) {
		cout << it << ",";
	}
	cout << endl;

	while (true) {
		i = 0;
		registers['A'] = a;
		registers['B'] = 0;
		registers['C'] = 0;


		ret.clear();
		while (i + 1 < operationsll.size()) {
			Perform(operationsll[i], operationsll[i + 1]);
		}
		if (ret == operationsll) {
			a_val = a;
			break;
		}

		if (ret.size() < operationsll.size()) {
			a *= 2; continue;
		}
		if (operationsll.size() < ret.size()) {
			a /= 2;
			continue;
		}

		for (int i = operationsll.size() - 1; i >= 0; i--) {
			if (operationsll[i] != ret[i]) {
				a += powl(8, i);
				break;
			}
		}

	}


	cout << "Part 2: ";
	cout << a_val << endl;
}

int32_t main()
{
	zanj0();
	Solve();
	timetaken;
	return 0;
}



