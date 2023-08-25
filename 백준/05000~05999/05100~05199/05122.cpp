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

typedef struct MLC_calendar {
    int M[5];
}MLC_calendar;

#define PI 3.141592653589793

MLC_calendar InitMLC_calendar();
string CalcDoomsday(MLC_calendar& mlc);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    MLC_calendar mlc;
    string result;
    int TC;
    
    cin >> TC;

    for (int i = 1; i <= TC; i++) {
        mlc = InitMLC_calendar();
        result = CalcDoomsday(mlc);

        cout << "Data Set " << i << ":" << "\n" << result << "\n\n";
    }
    return 0;
}

MLC_calendar InitMLC_calendar() {
    MLC_calendar mlc;

    for (int i = 0; i < 5; i++) {
        cin >> mlc.M[i];
    }

    return mlc;
};

string CalcDoomsday(MLC_calendar& mlc) {
    string answer;
    int M = 0;
    int J, diff;

    for (int j = 0; j < 5; j++) {
        M = M * (j == 3 ? 18 : 20) + mlc.M[j];
    }

    cin >> J;

    diff = J - M + 13 * 20 * 20 * 18 * 20 - 2456054;


    if (diff < 0) {
        answer = "It's a hoax!";
    }
    else if (diff == 0) {
        answer = "Panic!";
    }
    else {
        answer = to_string(diff);
    }

    return answer;
}