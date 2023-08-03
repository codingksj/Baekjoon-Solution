#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<string>
#include<numeric>
#include<cmath>
#include<cctype>
#include<iomanip>

using namespace std;

typedef long long LL;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	string univ = "YONSEI";
	string slogan = "Leading the Way to the Future";

	cin >> N;
	N == 0 && cout << univ;
	N == 1 && cout << slogan;
	return 0;
}