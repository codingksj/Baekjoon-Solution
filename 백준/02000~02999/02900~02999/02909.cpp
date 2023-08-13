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

LL CalculatePrice(int price, int k);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	LL candy_price, k;

	cin >> candy_price >> k;

	cout << CalculatePrice(candy_price, k);

	return 0;
}

LL CalculatePrice(int price, int k) {
	LL new_price;
	LL money = pow(10, k);

	new_price = round((double)price / money) * money;

	return new_price;
};