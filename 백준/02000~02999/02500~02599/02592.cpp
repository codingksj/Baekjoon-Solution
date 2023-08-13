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


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int numbers[102] = { 0, };
	int number;
	int sum = 0, avg, mode;
	int maxV = -1;
	int maxCount;

	for (int i = 0; i < 10; i++) {
		cin >> number;
		sum += number;
		numbers[number / 10]++;
	}
	avg = sum / 10;
	maxCount = *max_element(numbers, numbers + 101);

	for (int i = 1; i <= 100; i++) {
		if (numbers[i] == maxCount) {
			mode = i * 10;
			break;
		}
	}

	cout << avg << "\n"
		<< mode << "\n";

	return 0;
}

