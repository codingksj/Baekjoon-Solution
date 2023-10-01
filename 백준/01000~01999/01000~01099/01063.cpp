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

typedef struct Coord {
    int r;
    int c;

    Coord operator+ (const Coord& other) const {
        Coord newCoord = { r + other.r, c + other.c };

        return newCoord;
    }

    bool operator==  (const Coord& other) const {
        bool isSame = (r == other.r) && (c == other.c);

        return isSame;
    }

    bool operator<= (const Coord& other) const {
        bool isLower = (r <= other.r) && (c <= other.c);

        return isLower;
    }
}Coord;

PSS FindLastPositionOfRockAndKing(const Coord& king, const Coord& rock, const int N);
pair<Coord, Coord> UpdatePosition(const pair<Coord, Coord>& cur, const string& dir);
string ConvertCoordToString(const Coord& coord);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Coord king, rock;
    PSS lastPostions;
    string kS, rS;
    int N;

    cin >> kS >> rS >> N;
    
    king = { kS[1] - '0', kS[0] - 'A' + 1 };
    rock = { rS[1] - '0', rS[0] - 'A' + 1 };

    lastPostions = FindLastPositionOfRockAndKing(king, rock, N);

    cout << lastPostions.first << "\n"
        << lastPostions.second << "\n";

    return 0;
}

PSS FindLastPositionOfRockAndKing(const Coord& king, const Coord& rock, const int N) {
    pair<Coord, Coord> cur = { king, rock };
    PSS lastPositions;
    string dir;

    for (int i = 0; i < N; i++) {
        cin >> dir;
        cur = UpdatePosition(cur, dir);
    }

    lastPositions.first = ConvertCoordToString(cur.first);
    lastPositions.second = ConvertCoordToString(cur.second);

    return lastPositions;
};

pair<Coord, Coord> UpdatePosition(const pair<Coord, Coord>& cur, const string& dir) {
    map<string, Coord> directions = {
        {"R", {0, 1}},   
        {"L", {0, -1}},  
        {"B", {-1, 0}},   
        {"T", {1, 0}},  
        {"RT", {1, 1}}, 
        {"LT", {1, -1}},
        {"RB", {-1, 1}},  
        {"LB", {-1, -1}}  
    };
    Coord king = cur.first;
    Coord rock = cur.second;
    Coord nKing, nRock;
    Coord edge1 = { 1,1 }, edge2 = { 8,8 };

    nKing = king + directions[dir];
    nRock = nKing + directions[dir];

    if (!((edge1 <= nKing) && (nKing <= edge2))) {
        return make_pair(king, rock);
    }
    if (!(nKing == rock)) {
        return make_pair(nKing, rock);
    }
    if (!((edge1 <= nRock) && (nRock <= edge2))) {
        return make_pair(king, rock);
    }
    return make_pair(nKing, nRock);
};

string ConvertCoordToString(const Coord& coord) {
    string position = "";
    char c1, c2;

    c1 = (coord.c - 1 + 'A');
    c2 = (coord.r + '0');

    position += c1;
    position += c2;

    return position;
};
