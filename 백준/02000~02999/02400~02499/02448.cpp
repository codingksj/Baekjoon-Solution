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

void MakeSierpinskiTriangle(Words& stars, const int x, const int y, const int N);
void FillMiniTriangle(Words& stars, const int x, const int y);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words stars;
    int N;

    cin >> N;

    stars.resize(N, string(2 * N, ' '));

    MakeSierpinskiTriangle(stars, 0, 0, N);

    for (const string& line : stars) {
        cout << line << "\n";
    }

    return 0;
}

void MakeSierpinskiTriangle(Words& stars, const int x, const int y, const int N) {
    if (N == 3) {
        FillMiniTriangle(stars, x, y);
        return;
    }
    MakeSierpinskiTriangle(stars, x, y + N / 2, N / 2);
    MakeSierpinskiTriangle(stars, x + N / 2, y, N / 2);
    MakeSierpinskiTriangle(stars, x + N / 2, y + N, N / 2);
};

void FillMiniTriangle(Words& stars, const int x, const int y) {
    vector<Pii> coords = {
        {0, 2}, {1, 1}, {1, 3},
        {2, 0}, {2, 1}, {2, 2},
        {2, 3}, {2, 4}
    };

    for (const Pii& p : coords) {
        stars[x + p.first][y + p.second] = '*';
    }
};

