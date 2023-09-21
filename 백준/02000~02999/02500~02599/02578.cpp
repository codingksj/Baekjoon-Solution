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

Matrix2D_i FillBingo(Matrix2D_i& bingo, const int number);
bool CheckBingo(const Matrix2D_i& bingo);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_i bingo(5, vector<int>(5, 0));
    int bingoNum;

    for (vector<int>& row : bingo) {
        for (int& col : row) {
            cin >> col;
        }
    }

    for (int i = 1; i <= 25; i++) {
        cin >> bingoNum;

        bingo = FillBingo(bingo, bingoNum);

        if (CheckBingo(bingo)) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}

Matrix2D_i FillBingo(Matrix2D_i& bingo, const int number) {
    Matrix2D_i newBingo = bingo;

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (newBingo[r][c] == number) {
                newBingo[r][c] = 0;
                r = 5;
                c = 5;
                break;
            }
        }
    }

    return newBingo;
};

bool CheckBingo(const Matrix2D_i& bingo) {
    int bingoCount = 0;
    bool isRowBingo;
    bool isColBingo;
    bool isDiagnolBingo;
    bool is3Bingo;

    for (int r = 0; r < 5; r++) {
        isRowBingo = true;
        for (int c = 0; c < 5; c++) {
            if (bingo[r][c]) {
                isRowBingo = false;
                break;
            }
        }
        isRowBingo && bingoCount++;
    }
    for (int c = 0; c < 5; c++) {
        isColBingo = true;
        for (int r = 0; r < 5; r++) {
            if (bingo[r][c]) {
                isColBingo = false;
                break;
            }
        }
        isColBingo && bingoCount++;
    }

    isDiagnolBingo = true;
    for (int i = 0; i < 5; i++) {
        if (bingo[i][i]) {
            isDiagnolBingo = false;
        }
    }
    isDiagnolBingo && bingoCount++;

    isDiagnolBingo = true;
    for (int i = 0; i < 5; i++) {
        if (bingo[i][4 - i]) {
            isDiagnolBingo = false;
        }
    }
    isDiagnolBingo && bingoCount++;


    is3Bingo = bingoCount >= 3;

    return is3Bingo;
};