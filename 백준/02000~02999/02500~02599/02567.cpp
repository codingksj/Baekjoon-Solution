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

Matrix2D_i FillPaper(const int N);
int CalcPerimeter(const Matrix2D_i& paper);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_i paper;
    int N, perimeter;

    cin >> N;

    paper = FillPaper(N);
    perimeter = CalcPerimeter(paper);
    
    cout << perimeter << "\n";

    return 0;
}

Matrix2D_i FillPaper(const int N) {
    Matrix2D_i paper(101, vector<int>(101, 0));
    int R, C;

    for (int i = 0; i < N; i++) {
        cin >> R >> C;
        for (int r = R; r < R + 10; r++) {
            for (int c = C; c < C + 10; c++) {
                paper[r][c] = 1;
            }
        }
    }

    return paper;
};

int CalcPerimeter(const Matrix2D_i& paper) {
    int dr[] = { -1,0,1,0 };
    int dc[] = { 0,1,0,-1 };
    int nr, nc;
    int perimeter = 0;

    for (int r = 1; r <= 100; r++) {
        for (int c = 1; c <= 100; c++) {
            if (!paper[r][c]) {
                continue;
            }
            for (int dir = 0; dir < 4; dir++) {
                nr = r + dr[dir];
                nc = c + dc[dir];
                (!paper[nr][nc]) && perimeter++;
            }
        }
    }

    return perimeter;
};