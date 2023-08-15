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

    string input, sum;
    int TC;
    int N, rN;
    int maxL;
    bool isFelindrome;

    cin >> TC;

    while (TC--) {
        cin >> input;

        N = stoi(input);

        reverse(input.begin(), input.end());

        rN = stoi(input);

        sum = to_string(N + rN);
        maxL = sum.length();

        isFelindrome = true;
        for (int i = 0; i <= maxL / 2; i++) {
            if (sum[i] != sum[maxL - 1 - i]) {
                isFelindrome = false;
                break;
            }
        }
        cout << (isFelindrome ? "YES" : "NO") << "\n";
    }
    return 0;
}
