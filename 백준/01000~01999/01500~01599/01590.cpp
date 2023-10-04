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
#include<tuple>
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

typedef pair<char, char> Pcc;
typedef pair<char, int> Pci;
typedef pair<char, string> PcS;
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;
typedef pair<string, string> PSS;

typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;

typedef struct Bus {
    LL startT;
    LL intervalT;
    LL totalBus;
}Bus;

LL FindMinWaitTime(const LL N, const LL T);
LL BinarySearch(const LL T, const Bus& bus);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    LL N, T;
    LL time;

    cin >> N >> T;

    time = FindMinWaitTime(N, T);

    cout << time << "\n";

    return 0;
}

LL FindMinWaitTime(const LL N, const LL T) {
    Bus bus;
    const LL MAX = (1LL << 32);
    LL time, minTime = MAX;

    for (LL i = 0; i < N; i++) {
        cin >> bus.startT >> bus.intervalT >> bus.totalBus;

        time = BinarySearch(T, bus);

        if (time != -1) {
            minTime = min(minTime, time);
        }
    }

    if (minTime == MAX) {
        minTime = -1;
    }
    
    return minTime;
};

LL BinarySearch(const LL T, const Bus& bus) {
    LL start, mid, end;
    LL nextBusTime, minTime = -1;

    start = 0;
    end = bus.totalBus - 1;

    while (start <= end) {
        mid = (start + end) / 2LL;
        nextBusTime = bus.startT + bus.intervalT * mid;

        if (nextBusTime >= T) {
            minTime = nextBusTime - T;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return minTime;
};
