#include<iostream>
#include<set>
#include<unordered_map>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<string>
#include<numeric>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<chrono>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

string CheckCarNumber(string number);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC;
	string carNumber;

	cin >> TC;

	while (TC--) {
		cin >> carNumber;
		cout << CheckCarNumber(carNumber) << "\n";
	}

	return 0;
}

string CheckCarNumber(string number) {
	string front, back;
	int frontVal, backVal;
	int pos = number.find("-");
	int delta;

	front = number.substr(0, pos);
	back = number.substr(pos+1);

	frontVal = (front[0] - 'A') * 26 * 26
		+ (front[1] - 'A') * 26
		+ (front[2] - 'A');

	backVal = stoi(back);

	delta = abs(frontVal - backVal);
	
	return (delta > 100 ? "not nice" : "nice");
};