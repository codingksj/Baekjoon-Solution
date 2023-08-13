#include<iostream>
#include<sstream>
#include<bitset>
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
typedef pair<LL, LL> PLL;

string DecodeTimeToBinary(string time);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string time;
	int TC;

	cin >> TC;

	while (TC--) {
		cin >> time;
		cout << DecodeTimeToBinary(time) << "\n";
	}
	return 0;
}

string DecodeTimeToBinary(string time) {
	bitset<6> bitH, bitM, bitS;
	string h, m, s;
	string timeHorizontal = "", timeVertical = "";
	string answer;

	bitH = stoi(time.substr(0, 2));
	bitM = stoi(time.substr(3, 2));
	bitS = stoi(time.substr(6, 2));

	h = bitH.to_string();
	m = bitM.to_string();
	s = bitS.to_string();

	timeHorizontal += (h + m + s);
	for (int i = 0; i < 6; i++) {
		timeVertical += h[i];
		timeVertical += m[i];
		timeVertical += s[i];
	}
	answer = timeVertical + ' ' + timeHorizontal;
	return answer;
};