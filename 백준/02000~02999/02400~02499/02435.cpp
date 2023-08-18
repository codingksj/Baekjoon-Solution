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
typedef pair<string, int> Psi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> temperatures, sumsOfTemper;
    int N, K;
    int temperature;
    int sumOfTemper = 0;
    int maxTemper = -10000000;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> temperature;
        sumOfTemper += temperature;
        temperatures.push_back(temperature);
        sumsOfTemper.push_back(sumOfTemper);
    }

    for (int i = K - 1; i < N; i++) {
        sumOfTemper = sumsOfTemper[i] - (i >= K ? sumsOfTemper[i - K] : 0);
        maxTemper = max(maxTemper, sumOfTemper);
    }

    cout << maxTemper;

    return 0;
}
