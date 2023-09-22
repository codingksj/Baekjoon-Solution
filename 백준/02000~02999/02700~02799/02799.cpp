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

typedef map<int, int> Mapii;
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

Words LoadBlinds(const int R);
vector<int> AnalyzeBlinds(const Words& blinds, const int R, const int C);
int GetBlindInfo(const Words& blinds, const int R, const int C);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words blinds;
    vector<int> blindsInfo;
    int R, C;

    cin >> R >> C;

    blinds = LoadBlinds(R);
    blindsInfo = AnalyzeBlinds(blinds, R, C);

    for (const int& info : blindsInfo) {
        cout << info << " ";
    }

    return 0;
}

Words LoadBlinds(const int R) {
    Words blinds(5 * R + 1);

    for (string& line : blinds) {
        cin >> line;
    }

    return blinds;
};

vector<int> AnalyzeBlinds(const Words& blinds, const int R, const int C) {
    vector<int> blindsInfo(5, 0);
    int index;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            index = GetBlindInfo(blinds, i, j);
            blindsInfo[index]++;
        }
    }

    return blindsInfo;
};

int GetBlindInfo(const Words& blinds, const int R, const int C) {
    string blind = "";
    int startR = 5 * R + 1;
    int startC = 5 * C + 1;
    int starCount = 0, index;

    for (int r = startR; r < startR + 4; r++) {
        blind += blinds[r].substr(startC, 4);
    }

    starCount = count(blind.begin(), blind.end(), '*');
    index = starCount / 4;

    return index;
};