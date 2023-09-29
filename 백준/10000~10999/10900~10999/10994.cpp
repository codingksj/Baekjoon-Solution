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

Words LoadStars(const int size);
void FillStars(Words& starMap, const int size, const int start);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words starMap;
    int size;

    cin >> size;

    starMap = LoadStars(size);
    FillStars(starMap, size, 0);

    for (const string& line : starMap) {
        cout << line << "\n";
    }

    return 0;
}

Words LoadStars(const int size) {
    Words starMap;
    int length = 4 * size - 3;

    length = 4 * size - 3;

    starMap.resize(length, string(length, ' '));

    return starMap;
};

void FillStars(Words& starMap, const int size, const int start) {
    int length = 4 * size - 3;

    if (size == 1) {
        starMap[start][start] = '*';
        return;
    }
    
    for (int i = start; i < start + length; i++) {
        starMap[start][i] = 
            starMap[start + length - 1][i] =
            starMap[i][start] =
            starMap[i][start + length - 1] = '*';
    }

    FillStars(starMap, size - 1, start + 2);
};
