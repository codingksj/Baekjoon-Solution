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

string Encryption(string P, string e);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string P, e;

	getline(cin, P);
	getline(cin, e);

	cout << Encryption(P, e);

	return 0;
}

string Encryption(string P, string e) {
	string encryptionedP = "";
	int pLength = P.length();
	int eLength = e.length();
	int bias;

	char letterP, letterE;

	for (int i = 0; i < pLength; i++) {
		letterP = P[i];
		letterE = e[i % eLength];

		bias = letterP - letterE - 1;
		(bias < 0) && (bias += 26);
		encryptionedP += (letterP == ' ') ? ' ' : ('a' + bias);
	}
	return encryptionedP;
};

