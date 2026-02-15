#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<numbers>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
using PLL = pair<LL, LL>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

namespace CUBE {
    using Face = char[9];
    using FacePtr = Face*;
    using AdjFace = int[4];
    using Convert = int[4][3];
    enum OBJ { U, D, F, B, L, R, T };
    constexpr int CW[9] = { 6,3,0,7,4,1,8,5,2 };
    constexpr int CCW[9] = { 2,5,8,1,4,7,0,3,6 };
    constexpr char COLORS[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };
    constexpr AdjFace adj[6] = {
        {L, F, R, B}, 
        {L, B, R, F}, 
        {L, D, R, U}, 
        {R, D, L, U},
        {B, D, F, U},
        {F, D, B, U}
    };
    constexpr Convert convert[6] = {
        { {0,1,2}, {0,1,2}, {0,1,2}, {0,1,2} },
        { {6,7,8}, {6,7,8}, {6,7,8}, {6,7,8} },
        { {2,5,8}, {0,1,2}, {6,3,0}, {8,7,6} },
        { {2,5,8}, {8,7,6}, {6,3,0}, {0,1,2} },
        { {8,5,2}, {0,3,6}, {0,3,6}, {0,3,6} },
        { {2,5,8}, {2,5,8}, {6,3,0}, {2,5,8} }
    };
}
using namespace CUBE;

struct Cube {
    Face M[7];

    Cube() {
        for (int i = 0; i < 6; i++) {
            memset(M[i], COLORS[i], sizeof(Face));
        }
    }
    void FaceRotate(int idx, char dir) {
        memcpy(M[T], M[idx], sizeof(Face));
        for (int i = 0; i < 9; i++) {
            M[idx][i] = M[T][(dir == '+' ? CW : CCW)[i]];
        }
    }
    void Print() {
        println("{}{}{}", M[U][0], M[U][1], M[U][2]);
        println("{}{}{}", M[U][3], M[U][4], M[U][5]);
        println("{}{}{}", M[U][6], M[U][7], M[U][8]);
    }
    void Rotate(int idx, char dir) {
        FaceRotate(idx, dir);

        int fIdx[4] = { adj[idx][0], adj[idx][1], adj[idx][2], adj[idx][3] };
        const auto& mp = convert[idx];
        if (dir == '+') {
            for (int i = 0; i < 3; i++) {
                M[T][mp[3][i]] = M[fIdx[0]][mp[0][i]];
            }
            for (int i = 0; i < 3; i++) {
                int curF = fIdx[i], nxtF = fIdx[i + 1];
                for (int j = 0; j < 3; j++) {
                    M[curF][mp[i][j]] = M[nxtF][mp[i + 1][j]];
                }
            }
            for (int i = 0; i < 3; i++) {
                M[fIdx[3]][mp[3][i]] = M[T][mp[3][i]];
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                M[T][mp[0][i]] = M[fIdx[3]][mp[3][i]];
            }
            for (int i = 3; i > 0; i--) {
                int curF = fIdx[i], prvF = fIdx[i - 1];
                for (int j = 0; j < 3; j++) {
                    M[curF][mp[i][j]] = M[prvF][mp[i - 1][j]];
                }
            }
            for (int i = 0; i < 3; i++) {
                M[fIdx[0]][mp[0][i]] = M[T][mp[0][i]];
            }
        }
    }
};
void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

map<char, int> faceMap = {
    {'U', U}, {'D', D}, {'F', F}, {'B', B}, {'L', L}, {'R', R}
};
Cube cube;
string cmd;
int TC, N;

int main() {
    FastIO();
    SetUp();

    cin >> TC;

    while (TC--) {
        Input();
        Solve();
        Output();
    }

    return 0;
}

void FastIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return;
};

void SetUp() {
    return;
};

bool Input() {
    cin >> N;

    return true;
};

void Solve() {
    cube = Cube();
    while (N--) {
        cin >> cmd;
        cube.Rotate(faceMap[cmd[0]], cmd[1]);
    }
    return;
};

void Output() {
    cube.Print();
    return;
};
