#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string binary, b1, b2, binary17;
	char result[1010];
	int d1, d2, carry = 0, sum = 0;
	cin >> binary;
	b1 = "0000" + binary;
	b2 = binary + "0000";
	for (int i = b1.size() - 1; i >= 0; i--) {
		d1 = b1[i] - '0';
		d2 = b2[i] - '0';
		sum = d1 + d2 + carry;
		carry = sum / 2;
		sum %= 2;
		result[i] = sum + '0';
	}
	result[b1.size()] = '\0';
	binary17 = string(result);
	if (carry) {
		binary17 = "1" + binary17;
	}
	cout << binary17 << "\n";
	return 0;
}