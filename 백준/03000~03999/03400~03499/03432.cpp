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
typedef pair<int, int> Pii;
typedef pair<int, string> Pis;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

typedef struct _tictactoe {
    char board[5][5];
}Tictactoe;

string DetermineWinner(Tictactoe& T);
bool CheckWin(Tictactoe& T, Pii& pos, char p);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Tictactoe T;
    string result;
    int TC;

    cin >> TC;

    while (TC--) {
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                cin >> T.board[r][c];
            }
        }
        result = DetermineWinner(T);
        cout << result << "\n";
    }

    return 0;
}

string DetermineWinner(Tictactoe& T) {
    Pii pos;
    string result;
    bool winA = false, winB = false;
    
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            pos = { r,c };
            CheckWin(T, pos, 'A') && (winA = true);
            CheckWin(T, pos, 'B') && (winB = true);
            if (winA && winB) {
                r = 3;
                break;
            }
        }
    }

    if (winA == winB) {
        result = "draw";
    }
    else if (winA) {
        result = "A wins";
    }
    else {
        result = "B wins";
    }

    return result;
};

bool CheckWin(Tictactoe& T, Pii& pos, char p) {
    int r = pos.first;
    int c = pos.second;

    bool rows[3], R;
    bool cols[3], C;
    bool diag1, diag2, D;
    bool win;

    for (int i = 0; i < 3; i++) {
        rows[i] = (T.board[r + i][c] == p)
            && (T.board[r + i][c + 1] == p)
            && (T.board[r + i][c + 2] == p);

        cols[i] = (T.board[r][c + i] == p)
            && (T.board[r + 1][c + i] == p)
            && (T.board[r + 2][c + i] == p);
    }

    diag1 = (T.board[r][c] == p)
        && (T.board[r + 1][c + 1] == p)
        && (T.board[r + 2][c + 2] == p);

    diag2 = (T.board[r][c + 2] == p)
        && (T.board[r + 1][c + 1] == p)
        && (T.board[r + 2][c] == p);

    R = rows[0] || rows[1] || rows[2];
    C = cols[0] || cols[1] || cols[2];
    D = diag1 || diag2;

    win = R || C || D;

    return win;
};