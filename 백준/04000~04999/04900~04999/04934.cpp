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

#define PI 3.141592653589793

typedef struct Clock {
    int h;
    int m;
    int u;
    int s;
    double rad;
}Clock;

Clock GetTime();
double CalcRadian(Clock& t);
double CalcArea(Clock& t1, Clock& t2, double r);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Clock t1, t2;
    double r, area;
    int TC;

    cin >> TC;

    for (int i = 1; i <= TC; i++) {
        t1 = GetTime();
        t2 = GetTime();

        cin >> r;

        area = CalcArea(t1, t2, r);

        cout << i << ". " << setprecision(3) << fixed << area << "\n";
    }

    return 0;
}

Clock GetTime() {
    Clock t;

    cin >> t.h >> t.m >> t.s >> t.u;

    t.rad = CalcRadian(t);

    return t;
};

double CalcRadian(Clock& t) {
    const double H = 30.0, M = 0.5, S = 0.5 / 60.0, U = 0.5 / 6000.0;
    double radian = (H * t.h + M * t.m + S * t.s + U * t.u) * PI / 180.0;

    return radian;
};

double CalcArea(Clock& t1, Clock& t2, double r) {
    double area;
    double theta = t2.rad - t1.rad;

    if (theta < 0) {
        theta += 360.0;
    }

    area = 0.5 * r * r * theta;

    return area;
};