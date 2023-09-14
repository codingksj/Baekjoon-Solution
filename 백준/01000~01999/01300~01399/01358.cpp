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

typedef struct Coord {
    int x;
    int y;

    bool operator<= (const Coord& other) const {
        bool isInSquare = (x <= other.x) && (y <= other.y);

        return isInSquare;
    }

    int operator- (const Coord& other) const {
        int dx = x - other.x;
        int dy = y - other.y;
        int distance = dx * dx + dy * dy;

        return distance;
    }
}Coord;

bool CheckIsInSquare(const Coord& start, const Coord& end, const Coord& player);
bool CheckIsInCircle(const Coord& center, const Coord& player, const int R);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Coord start, end, player;
    Coord center1, center2;
    int W, H, X, Y, P;
    int R;
    int count = 0;

    cin >> W >> H >> X >> Y >> P;

    R = H / 2;

    start = { X,Y }, end = { X + W, Y + H };
    center1 = { X, Y + R }, center2 = { X + W, Y + R };

    for (int i = 0; i < P; i++) {
        cin >> player.x >> player.y;
        (CheckIsInSquare(start, end, player) ||
            CheckIsInCircle(center1, player, R) ||
            CheckIsInCircle(center2, player, R)) && count++;
    }
    
    cout << count << "\n";

    return 0;
}

bool CheckIsInSquare(const Coord& start, const Coord& end, const Coord& player) {
    bool isInSquare = (start <= player) && (player <= end);

    return isInSquare;
};

bool CheckIsInCircle(const Coord& center, const Coord& player, const int R) {
    bool isInCircle = (center - player) <= R * R;

    return isInCircle;
};