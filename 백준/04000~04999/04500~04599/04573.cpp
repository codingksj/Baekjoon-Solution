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
typedef vector<vector<int>> Matrix2Di;

#define PI 3.141592653589793

double CalcCostPerArea(double D, double P);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    double D, P;
    double eff, minEff;
    double inch;
    int N;

    for (int TC = 1;; TC++) {
        minEff = 1E+9;

        cin >> N;

        if (N == 0) {
            break;
        }

        while (N--) {
            cin >> D >> P;
            eff = CalcCostPerArea(D, P);
            if (eff < minEff) {
                minEff = eff;
                inch = D;
            }
        }
        cout << "Menu " << TC << ": " << inch << "\n";
    }

    return 0;
}

double CalcCostPerArea(double D, double P) {
    double costPerArea;
    double area;
    double r = D / 2;

    area = PI * r * r;
    costPerArea = P / area;

    return costPerArea;
};