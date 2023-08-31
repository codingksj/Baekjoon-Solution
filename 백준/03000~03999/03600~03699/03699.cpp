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
typedef vector<vector<LL>> Matrix2D_L;

Matrix2D_L FillParkingTower(LL H, LL L);
LL CalcTotalTime(Matrix2D_L& parking_tower, LL L);
PLL FindCar(Matrix2D_L& parking_tower, LL N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_L parking_tower;
    map<LL, PLL> parkInfo;
    LL TC, H, L;
    LL totalTime;

    cin >> TC; 

    while (TC--) {
        cin >> H >> L;
        parking_tower = FillParkingTower(H, L);
        totalTime = CalcTotalTime(parking_tower, L);

        cout << totalTime << '\n';
    }


    return 0;
}

Matrix2D_L FillParkingTower(LL H, LL L) {
    Matrix2D_L parking_tower(H, vector<LL>(L));

    for (vector<LL>& floor : parking_tower) {
        for (LL& place : floor) {
            cin >> place;
        }
    }

    return parking_tower;
};


LL CalcTotalTime(Matrix2D_L& parking_tower, LL L) {
    Matrix2D_L pTower = parking_tower;
    LL total_time = 0;
    LL moveTime;
    LL carH, carL, dH, dL;
    PLL carPos, end = { -1,-1 };

    for (LL N = 1;;N++) {
        carPos = FindCar(pTower, N);

        if (carPos == end) {
            break;
        }

        carH = carPos.first;
        carL = carPos.second;

        dH = 2 * carH;
        dL = min(carL, L - carL);

        moveTime = 10LL * dH + 5LL * dL;
        total_time += moveTime;

        rotate(pTower[carH].begin(),
            pTower[carH].begin() + carL,
            pTower[carH].end());
    }

    return total_time;
}

PLL FindCar(Matrix2D_L& parking_tower, LL N) {
    PLL carPos = { -1,-1 };
    LL H = parking_tower.size();
    LL L = parking_tower[0].size();

    for (int h = 0; h < H; h++) {
        for (int l = 0; l < L; l++) {
            if (parking_tower[h][l] == N) {
                carPos = { h,l };
                l = L;
                h = H;
            }
        }
    }

    return carPos;
};
