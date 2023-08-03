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
	string jaehwan, doc;
	int L1, L2;
	cin >> jaehwan;
	cin >> doc;
	L1 = jaehwan.length();
	L2 = doc.length();
	(L1 >= L2) ? cout << "go\n" : cout << "no";
	return 0;
}