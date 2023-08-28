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

typedef struct Coord {
    int r;
    int c;

    bool operator==(const Coord& other) const {
        return r == other.r && c == other.c;
    }
}Coord;

enum Positions{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

Words MakeWoodBlock(int N);
Words MoveRobot(Words& woodBlock, string& commands, int N);
Coord GetNextPos(Coord& curPos, char& command, int N);
char MakeCarve(char& cur, char& command);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words woodBlock, woodBlockPrinting;
    string commands;
    int N;

    cin >> N;

    woodBlock = MakeWoodBlock(N);

    cin >> commands;

    woodBlockPrinting = MoveRobot(woodBlock, commands, N);

    for (string& line : woodBlockPrinting) {
        cout << line << "\n";
    }

    return 0;
};

Words MakeWoodBlock(int N) {
    Words woodBlock(N, string(N, '.'));

    return woodBlock;
};

Words MoveRobot(Words& woodBlock, string& commands, int N) {
    Words copy = woodBlock;
    Coord curPos = { 0, 0 }, nextPos;

    for (char command : commands) {
        nextPos = GetNextPos(curPos, command, N);
        if (curPos == nextPos) {
            continue;
        }

        copy[curPos.r][curPos.c] = 
            MakeCarve(copy[curPos.r][curPos.c], command);

        copy[nextPos.r][nextPos.c] = 
            MakeCarve(copy[nextPos.r][nextPos.c], command);

        curPos = nextPos;
    }

    return copy;
};

Coord GetNextPos(Coord& curPos, char& command, int N) {
    map<char, int> posTable = {
        {'U', UP},
        {'R', RIGHT},
        {'D', DOWN},
        {'L', LEFT}
    };
    Coord nextPos;
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    int posIndex = posTable[command];
    bool validR, validC;

    nextPos = { curPos.r + dr[posIndex] , curPos.c + dc[posIndex] };
    validR = nextPos.r >= 0 && nextPos.r < N;
    validC = nextPos.c >= 0 && nextPos.c < N;

    if (!validR || !validC) {
        nextPos = curPos;
    }

    return nextPos;
};

char MakeCarve(char& cur, char& command) {
    bool isVertical = command == 'U' || command == 'D';
    char carve;

    if ((cur == '|' && !isVertical) || (cur == '-' && isVertical) || cur == '+') {
        carve = '+';
    }
    else if (cur=='.') {
        carve = isVertical ? '|' : '-';
    }
    else {
        carve = cur;
    }

    return carve;
};