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
typedef vector<vector<double>> Matrix2D_d;

double FindMaxGiftSize(const LL length, const LL width, const LL height, const LL N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    LL N, length, width, height;
    double giftSize;

    cin >> N >> length >> width >> height;

    giftSize = FindMaxGiftSize(length, width, height, N);

    cout << setprecision(15) << fixed << giftSize << "\n";

    return 0;
}

double FindMaxGiftSize(const LL length, const LL width, const LL height, const LL N) {
    double giftSize = 0;
    double left = 0;
    double right = max({ height, length, width });
    double mid;
    LL W, H, L;

    for (int i = 0; i < 10000; i++) {
        mid = (left + right) / 2;
        W = width / mid;
        H = height / mid;
        L = length / mid;

        (H * W * L < N) ? (right = mid) : (giftSize = left = mid);    
    }

    return giftSize;
};