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
typedef vector<vector<bool>> Matrix2D_b;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

typedef struct Info {
    int r;
    int c;
    int move;
}Info;

Words MakeBoard(const int N);
Matrix2D_b MakeBFSCheck(Words& board, const int N, const int M);
int BFS(const Words& board, Matrix2D_b& BFSCheck, const int N, const int M);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words board;
    Matrix2D_b BFSCheck;
    int N, M;
    int minMove;

    cin >> N >> M;

    board = MakeBoard(N);
    BFSCheck = MakeBFSCheck(board, N, M);
    minMove = BFS(board, BFSCheck, N, M);

    cout << minMove << "\n";

    return 0;
}

Words MakeBoard(const int N) {
    Words board(N);

    for (string& line : board) {
        cin >> line;
    }

    return board;
};

Matrix2D_b MakeBFSCheck(Words& board, const int N, const int M) {
    Matrix2D_b BFSCheck(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '0') {
                BFSCheck[i][j] = true;
            }
        }
    }

    return BFSCheck;
};

int BFS(const Words& board, Matrix2D_b& BFSCheck, const int N, const int M) {
    queue<Info> q;
    int dx[] = { 0,1,0,-1 };
    int dy[] = { -1,0,1,0 };
    int x, y;
    int nx, ny;
    int movement = 1;

    q.push({ 0,0,movement });

    BFSCheck[0][0] = true;

    while (!q.empty()) {
        x = q.front().c;
        y = q.front().r;
        movement = q.front().move + 1;

        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !BFSCheck[ny][nx]) {
                BFSCheck[ny][nx] = true;
                q.push({ ny,nx,movement });
            }
        }
        if (BFSCheck[N - 1][M - 1]) {
            break;
        }
    }

    return movement;
};
