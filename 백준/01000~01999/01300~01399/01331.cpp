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
}Coord;

bool CheckKnightMovesValidness(const vector<Coord>& knightMoves);
bool CanReach(const Coord& src, const Coord& dest);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Coord> knightMoves(36);
    int n;
    char c;
    bool isValid;

    for (Coord& knightMove : knightMoves) {
        cin >> c >> n;
        knightMove = { n - 1, c - 'A' };
    }

    isValid = CheckKnightMovesValidness(knightMoves);

    cout << (isValid ? "Valid" : "Invalid") << "\n";
    
    return 0;
}

bool CheckKnightMovesValidness(const vector<Coord>& knightMoves) {
    Coord src, dest;
    bitset<36> isVisited;
    int index;
    bool isValid = true;

    for (int i = 0; i < 36; i++) {
        src = knightMoves[i];
        dest = knightMoves[(i + 1) % 36];
        index = src.x + 6 * src.y;

        if (isVisited[index] || !CanReach(src, dest)) {
            isValid = false;
            break;
        }

        isVisited[index] = true;
    }

    return isValid;
};

bool CanReach(const Coord& src, const Coord& dest) {
    int dx = abs(src.x - dest.x);
    int dy = abs(src.y - dest.y);
    bool canReach = (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
    
    return canReach;
};