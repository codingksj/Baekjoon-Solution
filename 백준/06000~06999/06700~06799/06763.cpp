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
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	LL speed, limit, exceed;
	cin >> limit >> speed;
	exceed = speed - limit;
	if (exceed <= 0) {
		cout << "Congratulations, you are within the speed limit!" << "\n";
	}
	else if (exceed <= 20) {
		cout << "You are speeding and your fine is $100." << "\n";
	}
	else if (exceed <= 30) {
		cout << "You are speeding and your fine is $270." << "\n";
	}
	else {
		cout << "You are speeding and your fine is $500." << "\n";
	}
	return 0;
}