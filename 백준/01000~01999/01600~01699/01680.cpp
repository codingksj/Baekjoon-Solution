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

typedef struct GarbageTruck {
    int capacity;
    int distance;
}GarbageTruck;

GarbageTruck CalcTotalDistance(const int W, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    GarbageTruck gTruck;
    int TC, W, N;

    cin >> TC;

    while (TC--) {
        cin >> W >> N;

        gTruck = CalcTotalDistance(W, N);

        cout << gTruck.distance << "\n";
    }

    return 0;
}

GarbageTruck CalcTotalDistance(const int W, const int N) {
    GarbageTruck gTruck = { W,0 };
    int curX, prevX = 0;
    int totalTrash = 0;
    int curTrash = 0;

    for (int i = 0; i < N; i++) {
        cin >> curX >> curTrash;

        gTruck.distance += curX - prevX;
        prevX = curX;
        totalTrash += curTrash;

        if (totalTrash > gTruck.capacity) {
            totalTrash = curTrash;
            gTruck.distance += 2 * curX;
        }
        else if (totalTrash == gTruck.capacity && i != N - 1) {
            totalTrash = 0;
            gTruck.distance += 2 * curX;
        }
    }
    gTruck.distance += curX;

    return gTruck;
};