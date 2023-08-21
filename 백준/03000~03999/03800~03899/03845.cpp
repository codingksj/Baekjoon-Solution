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
typedef pair<int, string> Pis;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

vector<double> GetCenters(int TC);
bool CanCut(vector<double>& centers, double width, double target);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<double> X, Y;
    bool isCut;
    int nx, ny;
    const double W = 100, H = 75;
    double width;
    
    while (true) {
        cin >> nx >> ny >> width;

        if (nx == 0 && ny == 0 && width == 0) {
            break;
        }

        isCut = true;

        X = GetCenters(nx);
        Y = GetCenters(ny);

        isCut = CanCut(X, width, H) &&
                CanCut(Y, width, W);

        cout << (isCut ? "YES" : "NO") << "\n";
    }

    return 0;
}

vector<double> GetCenters(int TC) {
    vector<double> centers;
    double center;

    for (int i = 0; i < TC; i++) {
        cin >> center;
        centers.push_back(center);
    }

    sort(centers.begin(), centers.end());

    return centers;
};

bool CanCut(vector<double>& centers, double width, double target) {
    double before = width / 2;
    double delta;

    for (double& now : centers) {
        delta = now - before;
        before = now;
        if (delta > width) {
            return false;
        }
    }

    return !((centers.back() + width / 2) < target);
};