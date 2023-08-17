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
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

void InitializeBoard(char board[][102], int M, int N);
int CountSnailTurn(int M, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    int ans;

    cin >> M >> N;

    ans = CountSnailTurn(M, N);

    cout << ans;

    return 0;
}

void InitializeBoard(char board[][102], int M, int N) {
    for (int r = 0; r <= M + 1; r++) {
        for (int c = 0; c <= N + 1; c++) {
            board[r][c] = ' ';
        }
    }

    for (int i = 0; i <= N + 1; i++) {
        board[0][i] = board[M + 1][i] = 'X';
    }
    for (int i = 0; i <= M + 1; i++) {
        board[i][0] = board[i][N + 1] = 'X';
    }
}


int CountSnailTurn(int M, int N) {
    char board[102][102];
    int turnCount = 0;

    int dr[4] = { 0, 1, 0, -1 };
    int dc[4] = { 1, 0, -1, 0 };
    int dir = 0;

    int r = 1, c = 1;

    InitializeBoard(board, M, N);
    board[1][1] = 'X';

    while (true) {
        bool canMove = false;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr <= M + 1 && nc >= 0 && nc <= N + 1 && board[nr][nc] != 'X') {
                canMove = true;
                break;
            }
        }

        if (!canMove) {
            break;
        }

        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if (board[nr][nc] == ' ') {
            r = nr;
            c = nc;
            board[r][c] = 'X';
        }
        else {
            dir = (dir + 1) % 4;
            turnCount++;
        }
    }

    return turnCount;
}

