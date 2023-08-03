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
	string s1, s2;
	int n1, n2;
	cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	n1 = stoi(s1);
	n2 = stoi(s2);
	printf("%d\n", n1 > n2 ? n1 : n2);
	return 0;
}