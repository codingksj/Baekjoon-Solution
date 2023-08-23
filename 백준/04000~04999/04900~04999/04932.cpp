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
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> Pis;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
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

bool CheckMatrix(int matrix[11][11], int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    bool check;
    int matrix[11][11] = { 0, };
    int TC, N;

    cin >> TC;

    for (int i = 1; i <= TC; i++) {
        cin >> N;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                cin >> matrix[r][c];
            }
        }

        check = CheckMatrix(matrix, N);

        cout << i << ". " << (check ? "YES" : "NO") << "\n";
    }

    return 0;
}

bool CheckMatrix(int matrix[11][11], int N) {
    int dx, dy;
    int new_dx, new_dy;

    if (N == 1) {
        return true;
    }

    for (int r = 1; r < N; r++) {
        dy = matrix[r][0] - matrix[r - 1][0];
        dx = matrix[0][r] - matrix[0][r - 1];

        for (int c = 0; c < N; c++) {
            new_dy = matrix[r][c] - matrix[r - 1][c];
            new_dx = matrix[c][r] - matrix[c][r - 1];

            if (new_dy != dy || new_dx != dx) {
                return false;
            }
        }
    }

    return true;

};