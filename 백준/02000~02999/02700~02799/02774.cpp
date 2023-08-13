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


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

	int numbers[10];
	int TC, N;
	int digit, count;

	cin >> TC;

    while (TC--) {
        memset(numbers, 0, sizeof(numbers)); 

        cin >> N;

        do {
            digit = N % 10;
            numbers[digit]++;
            N /= 10;
        } while (N > 0);

        count = 0;

        for (int i = 0; i < 10; i++) {
            if (numbers[i]) {
                count++;
            }
        }
        cout << count << "\n";
    }

	return 0;
}
