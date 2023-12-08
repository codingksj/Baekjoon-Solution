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
#define INF 1E+8

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
typedef pair<int, char> Pic;
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
template<typename T1, typename T2> void PrintVector(const vector<pair<T1, T2>>& V, const string sepsR, const string sepsPair) {
    for (const pair<T1, T2>& p : V) {
        PrintPair<T1, T2>(p, sepsPair);
        cout << sepsR;
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

template<typename T, typename Compare = less<T>> void SortAll(vector<T>& V, Compare cmp = Compare()) {
    sort(V.begin(), V.end(), cmp);
}
template<typename T, typename Compare = less<T>> void SortAll2D(vector<vector<T>>& V, Compare cmp = Compare()) {
    for (vector<T>& row : V) {
        Sort(row, cmp);
    }
}
template<typename T, typename Compare = less<T>> void StableSortAll(vector<T>& V, Compare cmp = Compare()) {
    stable_sort(V.begin(), V.end(), cmp);
}
template<typename T, typename Compare = less<T>> void StableSortAll2D(vector<vector<T>>& V, Compare cmp = Compare()) {
    for (vector<T>& row : V) {
        StableSort(row, cmp);
    }
}

template<typename T> size_t LowerBoundIndex(const vector<T>& V, const T target) {
    const size_t index = lower_bound(V.begin(), V.end(), target) - V.begin();
    return index;
}
template<typename T> size_t UpperBoundIndex(const vector<T>& V, const T target) {
    const size_t index = upper_bound(V.begin(), V.end(), target) - V.begin();
    return index;
}

template<typename Number> vector<Number> InitArithmeticSeq(const size_t N, const Number firstTerm = 1, const Number commonDiff = 1) {
    vector<Number> seq;

    for (size_t i = 0; i < N; i++) {
        seq.push_back(firstTerm + i * commonDiff);
    }

    return seq;
}

// ---------- 열거형 상수 ----------
enum OBJECT_TYPES {
    EMPTY = 0,
    BODY,
    APPLE
};

// ---------- 사용자 정의 함수 및 연산자 ----------
int SimulateSnake(const int boardSize, const int appleNum);
void PlaceApple(Matrix2D<int>& board, const int appleNum);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int boardSize, apples;
    int endTime;

    cin >> boardSize >> apples;

    endTime = SimulateSnake(boardSize, apples);

    cout << endTime << "\n";

    return 0;
}

int SimulateSnake(const int boardSize, const int appleNum) {
    Matrix2D<int> board = Matrix2D<int>(boardSize, boardSize, 0);
    vector<Pic> moves;
    deque<Pii> snake;
    Pii head = { 0,0 };
    Pii tail = { 0,0 };
    int dr[] = { 0,1,0,-1 };
    int dc[] = { 1,0,-1,0 };
    int dir = 0;
    int r = 0;
    int c = 0;
    int nr = 0;
    int nc = 0;
    int move = 0;
    int moveCount;
    int time = 0;
    bool isGame = true;

    snake.push_back(head);
    board.m2[r][c] = BODY;

    PlaceApple(board, appleNum);

    cin >> moveCount;

    moves = LoadVector<int, char>(moveCount);

    while (true) {
        time++;

        nr = r + dr[dir];
        nc = c + dc[dir];

        if (nr < 0 || nr >= boardSize || nc < 0 || nc >= boardSize) {
            break;
        }

        tail = snake.back();
        head = { nr,nc };

        switch (board.m2[head.first][head.second]){
            case EMPTY:
                board.m2[head.first][head.second] = BODY;
                board.m2[tail.first][tail.second] = EMPTY;
                snake.pop_back();
                snake.push_front(head);
                break;
            case APPLE:
                board.m2[head.first][head.second] = BODY;
                snake.push_front(head);
                break;
            default:
                isGame = false;
                break;
        }
        r = nr;
        c = nc;
        if (!isGame) {
            break;
        }
        if (move >= moveCount) {
            continue;
        }
        if (time == moves[move].first) {
            dir = moves[move++].second == 'L' ? (dir + 3) % 4 : (dir + 1) % 4;
        }
    }

    return time;
};

void PlaceApple(Matrix2D<int>& board, const int appleNum) {
    int r, c;

    for (int i = 0; i < appleNum; i++) {
        cin >> r >> c;
        board.m2[r - 1][c - 1] = APPLE;
    }
};