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

typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;

typedef map<int, string> MapiS;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;

Words GetVideo(int N);
void CompressVideo(Words& video, int x, int y, int N);
bool CheckVideo(Words& vidoe, int x, int y, int n);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words video;
    string ans;
    int N;

    cin >> N;

    video = GetVideo(N);
    CompressVideo(video, 0, 0, N);

    return 0;
}

Words GetVideo(int N) {
    Words video(N);

    for (string& line : video) {
        cin >> line;
    }

    return video;
};

void CompressVideo(Words& video, int x, int y, int N) {
    if (CheckVideo(video, x, y, N)) {
        cout << video[x][y];
        return;
    }
    cout << "(";

    int M = N / 2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            CompressVideo(video, x + i * M, y + j * M, M);
        }
    }

    cout << ")";
};

bool CheckVideo(Words& video, int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (video[x][y] != video[i][j]) {
                return false;
            }
        }
    }

    return true;
};