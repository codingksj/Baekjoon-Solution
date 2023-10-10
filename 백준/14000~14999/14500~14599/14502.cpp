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

typedef struct Coord {
    int r;
    int c;
}Coord;

typedef enum OBJECTS{
    EMPTY,
    WALL,
    VIRUS
}OBJECTS;

Matrix2D_i MakeLab(const int R, const int C);
vector<Coord> FindObjectPositions(const Matrix2D_i& lab, const int object, const int R, const int C);
int FindMaxArea(Matrix2D_i& lab, const vector<Coord>& virusPositions, const int R, const int C);
int BFS(Matrix2D_i& lab, const int virus, const int wall, const int R, const int C);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_i lab;
    vector<Coord> virusPositions;
    int R, C;
    int maxSafeArea;

    cin >> R >> C;

    lab = MakeLab(R, C);
    virusPositions = FindObjectPositions(lab, VIRUS, R, C);
    maxSafeArea = FindMaxArea(lab, virusPositions, R, C);

    cout << maxSafeArea << "\n";

    return 0;
}

Matrix2D_i MakeLab(const int R, const int C) {
    Matrix2D_i lab(R, vector<int>(C, 0));

    for (vector<int>& row : lab) {
        for (int& col : row) {
            cin >> col;
        }
    }

    return lab;
};

vector<Coord> FindObjectPositions(const Matrix2D_i& lab, const int object, const int R, const int C) {
    vector<Coord> objectPositions;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (lab[r][c] == object) {
                objectPositions.push_back({ r,c });
            }
        }
    }

    return objectPositions;
};

int FindMaxArea(Matrix2D_i& lab, const vector<Coord>& virusPositions, const int R, const int C) {
    vector<Coord> emptyPositions = FindObjectPositions(lab, EMPTY, R, C);
    int virus = virusPositions.size();
    int empty = emptyPositions.size();
    int wall = R * C - (virus + empty);
    int area, maxArea = 0;

    for (int i = 0; i < empty - 2; i++) {
        for (int j = i + 1; j < empty - 1; j++) {
            for (int k = j + 1; k < empty; k++) {
                lab[emptyPositions[i].r][emptyPositions[i].c] = WALL;
                lab[emptyPositions[j].r][emptyPositions[j].c] = WALL;
                lab[emptyPositions[k].r][emptyPositions[k].c] = WALL;

                area = BFS(lab, virus, wall, R, C);
                maxArea = max(maxArea, area);

                lab[emptyPositions[i].r][emptyPositions[i].c] = EMPTY;
                lab[emptyPositions[j].r][emptyPositions[j].c] = EMPTY;
                lab[emptyPositions[k].r][emptyPositions[k].c] = EMPTY;
            }
        }
    }

    return maxArea;
};

int BFS(Matrix2D_i& lab, const int virus, const int wall, const int R, const int C) {
    Matrix2D_b bfsCheck(R, vector<bool>(C, false));
    queue<Coord> q;
    int dr[] = { -1,0,1,0 };
    int dc[] = { 0,1,0,-1 };
    int r, c, nr, nc;
    int area, allVirus = virus;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            bfsCheck[i][j] = (lab[i][j] != EMPTY);
            if (lab[i][j] == VIRUS) {
                q.push({ i,j });
            }
        }
    }

    while (!q.empty()) {
        r = q.front().r;
        c = q.front().c;
        q.pop();

        for (int i = 0; i < 4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && !bfsCheck[nr][nc]) {
                bfsCheck[nr][nc] = true;
                q.push({ nr,nc });
                allVirus++;
            }
        }
    }

    area = R * C - (allVirus + wall + 3);

    return area;
};
