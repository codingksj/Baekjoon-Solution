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
using Coord = array<int, 11>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr string_view target = "long";
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr LL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, DIM = 11, MAX = 1E+6;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

struct HyperBoard {
    bitset<MAX + 1> visChk;
    queue<Coord> q;
    V1<int> dimSize, w;
    int dim = DIM;
    int totalSz, totalTomato;

    HyperBoard() : totalSz(0), totalTomato(0) {}
    HyperBoard(const V1<int>& s) {
        dimSize = s;
        totalSz = 1;
        totalTomato = 0;
        for (int dimSz : dimSize) {
            totalSz *= dimSz;
        }
        w.assign(DIM, 1);
        for (int i = 1; i < DIM; i++) {
            w[i] = w[i - 1] * dimSize[i - 1];
        }
    }
    int GetIdx(const Coord coord) {
        int idx = 0;
        for (int i = 0; i < DIM; i++) {
            idx += coord[i] * w[i];
        }
        return idx;
    };
    void GetCoord(int idx, Coord& coord) {
        for (int i = 0; i < DIM; i++) {
            coord[i] = idx % dimSize[i];
            idx /= dimSize[i];
        }
    }
    void Input() {
        Coord t;
        int val;
        for (int i = 0; i < totalSz; i++) {
            cin >> val;
            if (val == -1) {
                totalTomato++;
                visChk[i] = true;
            }
            else if (val == 1) {
                totalTomato++;
                visChk[i] = true;
                GetCoord(i, t);
                q.push(t);
            }
        }
    }
    bool Check(const Coord& coord) {
        for (int i = 0; i < DIM; i++) {
            if (coord[i] < 0 || coord[i] >= dimSize[i]) {
                return false;
            }
        }
        return !visChk[GetIdx(coord)];
    }
    int BFS() {
        if (totalTomato == totalSz) {
            return 0;
        }
        int day = 0;
        while (!q.empty()) {
            int sz = q.size();
            bool isNewTomato = false;
            for (int k = 0; k < sz; k++) {
                auto coord = q.front(); q.pop();
                for (int i = 0; i < DIM; i++) {
                    for (int d : {1, -1}) {
                        coord[i] += d;
                        if (Check(coord)) {
                            visChk[GetIdx(coord)] = true;
                            q.push(coord);
                            totalTomato++;
                            isNewTomato = true;
                        }
                        coord[i] -= d;
                    }
                }
            }
            if (isNewTomato) {
                day++;
            }
            if (totalTomato == totalSz) {
                return day;
            }
        }
        return -1;
    }
};

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

HyperBoard B;
V1<int> dimSize(DIM);
int mnDay;

int main() {
    FastIO();
    SetUp();

    Input();
    Solve();
    Output();

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
    for (int i : Rng(0, DIM)) {
        cin >> dimSize[i];
    }
    B = HyperBoard(dimSize);
    B.Input();
    return true;
};

void Solve() {
    mnDay = B.BFS();
    return;
};

void Output() {
    println("{}", mnDay);
    return;
};
