#include<iostream>
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

string DecodeCipher(string cipher, string decode_rule);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string cipher, decode_rule, tmp;
	int TC;

	cin >> TC;
	getline(cin, tmp);

	while (TC--) {
		getline(cin, cipher);
		getline(cin, decode_rule);
		cout << DecodeCipher(cipher, decode_rule) << "\n";
	}
	return 0;
}

string DecodeCipher(string cipher, string decode_rule) {
	int pos;
	int maxL = cipher.length();
	string decoded_cipher = "";

	for (int i = 0; i < maxL; i++) {
		if (cipher[i] == ' ') {
			decoded_cipher += ' ';
			continue;
		}
		pos = cipher[i] - 'A';
		decoded_cipher += decode_rule[pos];
	}

	return decoded_cipher;
};