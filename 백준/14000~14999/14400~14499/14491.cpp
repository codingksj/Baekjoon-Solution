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

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, nonaryT = 0;
    int weight = 1;
	vector<int> digits;

    cin >> T;

    if (T == 0) {
        cout << 0;
    }
    else {
        while (T > 0) {
            digits.push_back(T % 9);
            T /= 9;
        }
        for (auto digit : digits) {
            nonaryT += digit * weight;
            weight *= 10;
        }
        cout << nonaryT;
    }


	return 0;
}

