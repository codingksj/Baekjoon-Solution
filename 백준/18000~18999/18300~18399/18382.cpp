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
#include<functional>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<chrono>

// ---------- 사용자 정의 상수 ----------
#define PI 3.141592653589793
#define THOUSAND 1E+3
#define MILLION 1E+6
#define BILLION 1E+9
#define BOARD_SIZE 4

// ---------- 사용자 정의 자료형 ----------
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

typedef vector<string> Words;

// ---------- 템플릿 자료형 ----------
template<typename T> struct Matrix2D {
    vector<vector<T>> m2;

    Matrix2D() {};
    Matrix2D(const size_t R, const size_t C, const T INIT) {
        m2 = vector<vector<T>>(R, vector<T>(C, INIT));
    }
};
template<typename T> struct Matrix3D {
    vector<vector<vector<T>>> m3;

    Matrix3D() {};
    Matrix3D(const size_t H, const size_t R, const size_t C, const T INIT) {
        m3 = vector<vector<vector<T>>>(H, vector<vector<T>>(R, vector<T>(C, INIT)));
    }
};

// ---------- 템플릿 함수 ----------
template<typename T> vector<T> InitVector(const size_t SIZE, const T INIT) { 
    return vector<T>(SIZE, INIT); 
}
template<typename T> vector<vector<T>> Init2DVector(const size_t R, const size_t C, const T INIT) { 
    return vector<vector<T>>(R, InitVector(C, INIT)); 
}
template<typename T> vector<vector<vector<T>>> Init3DVector(const size_t H, const size_t R, const size_t C, const T INIT) {
    return vector<vector<vector<T>>>(H, Init2DVector(R, C, INIT));
}

template<typename T1, typename T2> pair<T1, T2> LoadPair() {
    pair<T1, T2> p;
    cin >> p.first >> p.second;
    return p;
};
template<typename T> vector<T> LoadVector(const size_t SIZE) {
    vector<T> V(SIZE);
    for (T& e : V) {
        cin >> e;
    }
    return V;
}
template<typename T1, typename T2> vector<pair<T1, T2>> LoadVector(const size_t SIZE) {
    vector<pair<T1, T2>> V(SIZE);
    for (pair<T1, T2>& p : V) {
        p = LoadPair<T1, T2>();
    }
    return V;
}
template<typename T> vector<vector<T>> Load2DVector(const size_t R, const size_t C) {
    vector<vector<T>> V(R, vector<T>(C));
    for (vector<T>& row : V) {
        row = LoadVector<T>(C);
    }
    return V;
}
template<typename T1, typename T2> vector<vector<pair<T1, T2>>> Load2DVector(const size_t R, const size_t C) {
    vector<vector<pair<T1, T2>>> V(R, vector<pair<T1, T2>>(C));
    for (vector<pair<T1, T2>>& row : V) {
        row = LoadVector<T1, T2>(C);
    }
    return V;
}

template<typename T1, typename T2> void PrintPair(const pair<T1, T2>& p, const string sepsPair) {
    cout << p.first << sepsPair << p.second;
}
template<typename T> void PrintVector(const vector<T>& V, const string sepsC) { 
    for (const T& e : V) { 
        cout << e << sepsC; 
    } 
}
template<typename T1, typename T2> void PrintVector(const vector<pair<T1, T2>>& V, const string sepsC, const string sepsPair) {
    for (const pair<T1, T2>& p : V) {
        PrintPair<T1, T2>(p, sepsPair);
        cout << sepsC;
    }
}
template<typename T> void Print2DVector(const vector<vector<T>>& V, const string sepsR, const string sepsC) { 
    for (const vector<T>& row : V) { 
        PrintVector(row, sepsC); 
        cout << sepsR; 
    } 
}
template<typename T1, typename T2> void Print2DVector(const vector<vector<pair<T1, T2>>>& V, const string sepsR, const string sepsC, const string sepsPair) {
    for (const vector<pair<T1, T2>>& row : V) {
        PrintVector<T1, T2>(row, sepsC, sepsPair);
        cout << sepsR;
    }
}

template<typename T, typename Compare = less<T>> void Sort(vector<T>& V, Compare cmp = Compare()) { 
    sort(V.begin(), V.end(), cmp); 
}
template<typename T, typename Compare = less<T>> void Sort2D(vector<vector<T>>& V, Compare cmp = Compare()) { 
    for (vector<T>& row : V) { 
        Sort(row, cmp); 
    } 
}
template<typename T, typename Compare = less<T>> void StableSort(vector<T>& V, Compare cmp = Compare()) { 
    stable_sort(V.begin(), V.end(), cmp); 
}
template<typename T, typename Compare = less<T>> void StableSort2D(vector<vector<T>>& V, Compare cmp = Compare()) { 
    for (vector<T>& row : V) { 
        StableSort(row, cmp); 
    } 
}

template<typename T> size_t LowerBoundIndex(const vector<T>& V, const T target) { 
    const size_t index = lower_bound(V.begin(), V.end(), target) - V.begin(); 
    return index; 
}
template<typename T> size_t UpperBoundIndex(const vector<T>& V, const T target) { 
    const size_t index = upper_bound(V.begin(), V.end(), target) - V.begin(); return index; 
}

// ---------- 사용자 정의 함수 ----------
int Simulate2048(Matrix2D<int>& board, const string& commands, const int score);
int DoCommands(Matrix2D<int>& board, const char direction);
void GenerateNewNumber(Matrix2D<int>& board, const int R, const int C, const int value);
int MoveLeft(Matrix2D<int>& board);
int MoveRight(Matrix2D<int>& board);
int MoveUp(Matrix2D<int>& board);
int MoveDown(Matrix2D<int>& board);
void RotateClockwise(Matrix2D<int>& board);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D<int> board;
    string commands;
    int score;
    int totalScore = 0;

    cin >> score;
    cin.ignore();

    getline(cin, commands);

    board.m2 = Load2DVector<int>(BOARD_SIZE, BOARD_SIZE);
    totalScore = Simulate2048(board, commands, score);

    cout << totalScore << "\n";

    return 0;
}

int Simulate2048(Matrix2D<int>& board, const string& commands, const int score) {
    const int COMMAND_SIZE = 4;
    int totalScore = score;
    int cmdLength = commands.length();
    int direction, r, c, val;

    for (int i = 0; i < cmdLength; i += COMMAND_SIZE) {
        direction = commands[i];
        val = commands[i + 1] - '0';
        r = commands[i + 2] - '0';
        c = commands[i + 3] - '0';
        totalScore += DoCommands(board, direction);
        GenerateNewNumber(board, r, c, val);
    }

    return totalScore;
};

int DoCommands(Matrix2D<int>& board, const char direction) {
    int score = 0;

    switch (direction) {
        case 'L':
            score = MoveLeft(board);
            break;
        case 'R':
            score = MoveRight(board);
            break;
        case 'U':
            score = MoveUp(board);
            break;
        case 'D':
            score = MoveDown(board);
            break;
        default:
            break;
    }

    return score;
};

void GenerateNewNumber(Matrix2D<int>& board, const int R, const int C, const int value) {
    board.m2[R][C] = value;
};

int MoveLeft(Matrix2D<int>& board) {
    int score = 0;
    int nc;

    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 1; c < BOARD_SIZE; c++) {
            for (nc = c - 1; nc >= 0 && board.m2[r][nc] == 0; nc--) {};
            nc++;
            if (nc == c) {
                continue;
            }
            board.m2[r][nc] = board.m2[r][c];
            board.m2[r][c] = 0;
        }
        for (int c = 1; c < BOARD_SIZE; c++) {
            if (board.m2[r][c] > 0 && (board.m2[r][c - 1] == board.m2[r][c])) {
                board.m2[r][c - 1] <<= 1;
                board.m2[r][c] = 0;
                score += board.m2[r][c - 1];
            };
        }
        for (int c = 1; c < BOARD_SIZE; c++) {
            for (nc = c - 1; nc >= 0 && board.m2[r][nc] == 0; nc--) {};
            nc++;
            if (nc == c) {
                continue;
            }
            board.m2[r][nc] = board.m2[r][c];
            board.m2[r][c] = 0;
        }
    }

    return score;
};

int MoveRight(Matrix2D<int>& board) {
    int score = 0;

    RotateClockwise(board);
    RotateClockwise(board);
    score = MoveLeft(board);
    RotateClockwise(board);
    RotateClockwise(board);

    return score;
};

int MoveUp(Matrix2D<int>& board) {
    int score = 0;

    RotateClockwise(board);
    RotateClockwise(board);
    RotateClockwise(board);
    score = MoveLeft(board);
    RotateClockwise(board);

    return score;
};

int MoveDown(Matrix2D<int>& board) {
    int score = 0;

    RotateClockwise(board);
    score = MoveLeft(board);
    RotateClockwise(board);
    RotateClockwise(board);
    RotateClockwise(board);

    return score;
};

void RotateClockwise(Matrix2D<int>& board) {
    Matrix2D<int> tmp = Matrix2D<int>(BOARD_SIZE, BOARD_SIZE, 0);

    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            tmp.m2[r][c] = board.m2[BOARD_SIZE - 1 - c][r];
        }
    }

    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            board.m2[r][c] = tmp.m2[r][c];
        }
    }
};