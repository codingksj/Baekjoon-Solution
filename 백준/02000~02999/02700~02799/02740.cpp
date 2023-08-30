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

Matrix2D_i GetMatrix(int R, int C);
Matrix2D_i CalcMatrixMultiplication(Matrix2D_i& A, Matrix2D_i& B);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_i A, B, AB;
    int N, M, K;

    cin >> N >> M;

    A = GetMatrix(N, M);

    cin >> M >> K;

    B = GetMatrix(M, K);

    AB = CalcMatrixMultiplication(A, B);

    for (vector<int>& row : AB) {
        for (int& col : row) {
            cout << col << ' ';
        }
        cout << "\n";
    }

    return 0;
}

Matrix2D_i GetMatrix(int R, int C) {
    Matrix2D_i M(R, vector<int>(C, 0));

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> M[r][c];
        }
    }

    return M;
};

Matrix2D_i CalcMatrixMultiplication(Matrix2D_i& A, Matrix2D_i& B) {
    Matrix2D_i AB;
    int N = A.size();
    int M = A[0].size();
    int K = B[0].size();

    AB.resize(N, vector<int>(K, 0));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < K; c++) {
            for (int i = 0; i < M; i++) {
                AB[r][c] += A[r][i] * B[i][c];
            }
        }
    }

    return AB;
};