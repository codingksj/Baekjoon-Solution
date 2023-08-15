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
typedef pair<int, int> Pii;
typedef pair<LL, LL> PLL;

typedef struct _coord {
    int x;
    int y;
}Coord;

void UpdatePosition(Coord& p, char move, int& time);
bool FindTaskmaster(Coord& L, Coord& T);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Coord Luka, taskmaster = { 0,0 };
    string movements;
    vector<int> times;
    int N, time = 0;

    cin >> Luka.x >> Luka.y;
    cin >> N;
    cin >> movements;

    if (FindTaskmaster(Luka, taskmaster)) {
        times.push_back(time);
    }
   
    for (char movement : movements) {
        UpdatePosition(taskmaster, movement, time);
        if (FindTaskmaster(Luka, taskmaster)) {
            times.push_back(time);
        }
    }

    if (times.empty()) {
        cout << -1 << "\n";
        return 0;
    }

    for (int time : times) {
        cout << time << "\n";
    }

    return 0;
}

void UpdatePosition(Coord& p, char move, int& time) {
    time++;
    switch (move) {
        case 'I':
            p.x++;
            break;
        case 'Z':
            p.x--;
            break;
        case 'S':
            p.y++;
            break;
        case 'J':
            p.y--;
            break;
        default:
            break;
    }
};

bool FindTaskmaster(Coord& L, Coord& T) {
    bool canHear;
    int dx, dy;

    dx = abs(L.x - T.x);
    dy = abs(L.y - T.y);

    canHear = dx <= 1 && dy <= 1;

    return canHear;
};

