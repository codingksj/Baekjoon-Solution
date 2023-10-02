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

typedef unordered_map<LL, LL> HashLL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

vector<int> LoadLights(const int N);
int FindMinHeight(const int N, const int M, const vector<int>& lights);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> lights;
    int N, M, H;

    cin >> N >> M;

    lights = LoadLights(M);
    H = FindMinHeight(N, M, lights);

    cout << H << "\n";

    return 0;
}

vector<int> LoadLights(const int N) {
    vector<int> lights(N);

    for (int& light : lights) {
        cin >> light;
    }

    return lights;
};

int FindMinHeight(const int N, const int M, const vector<int>& lights) {
    vector<int> intervals;
    int interval, minHeight;

    for (int i = 0; i <= M; i++) {
        if (i == 0) {
            interval = lights[i];
        }
        else if (i == M) {
            interval = N - lights[i - 1];
        }
        else {
            interval = ceil((lights[i] - lights[i - 1]) / 2.0);
        }
        intervals.push_back(interval);
    }

    sort(intervals.begin(), intervals.end());

    minHeight = intervals[M];

    return minHeight;
};
