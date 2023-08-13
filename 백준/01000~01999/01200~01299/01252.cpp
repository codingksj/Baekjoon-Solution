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
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

void PaddingBinarys(string& bin1, string& bin2);
void AddBinarys(string bin1, string bin2, string& res);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string bin1, bin2, res = "";

	cin >> bin1 >> bin2;
	
	PaddingBinarys(bin1, bin2);
	AddBinarys(bin1, bin2, res);

	cout << res << "\n";

	return 0;
}

void PaddingBinarys(string& bin1, string& bin2) {
	int L1, L2, delta;

	L1 = bin1.length();
	L2 = bin2.length();
	delta = abs(L1 - L2);

	while (delta--) {
		if (L1 < L2) {
			bin1 = "0" + bin1;
		}
		else if (L1 > L2) {
			bin2 = "0" + bin2;
		}
	}
};

void AddBinarys(string bin1, string bin2, string& res) {
	int carry = 0;

	int length = bin1.length(); 

	for (int i = length - 1; i >= 0; --i) {
		int bit1 = bin1[i] - '0';
		int bit2 = bin2[i] - '0';

		int sum = bit1 + bit2 + carry;
		carry = sum / 2;

		res = to_string(sum % 2) + res;
	}

	if (carry != 0) {
		res = to_string(carry) + res;
	}
	else {
		if (res.find_first_not_of('0') == string::npos) {
			res = "0";
		}
		else { 
			res = res.substr(res.find_first_not_of('0'));
		}
	}
}
