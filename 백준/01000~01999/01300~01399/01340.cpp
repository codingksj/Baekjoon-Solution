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

typedef struct Date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
}Date;

Date InitDate();
double CalcProgress(Date& D);
bool IsLeapYear(int year);
int CalcDaysInMonth(int year, int month);
int CalcTotalDays(Date& D);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Date D = InitDate();
    double progress = CalcProgress(D);

    cout << setprecision(15) << fixed << progress << "\n";

    return 0;
};

Date InitDate() {
    Date D;
    MapSi monthTable = {
        {"January", 1},
        {"February", 2},
        {"March", 3},
        {"April", 4},
        {"May", 5},
        {"June", 6},
        {"July", 7},
        {"August", 8},
        {"September", 9},
        {"October", 10},
        {"November", 11},
        {"December", 12}
    };
    string M;
    char tmp;

    cin >> M >> D.day >> tmp >> D.year >>
        D.hour >> tmp >> D.minute;

    D.month = monthTable[M];

    return D;
};

double CalcProgress(Date& D) {
    int baseDays = IsLeapYear(D.year) ? 366 : 365;
    int baseMinutes = baseDays * 24 * 60;
    int totalMinutes = CalcTotalDays(D) * 24 * 60 + D.hour * 60 + D.minute;
    double progress = double(100 * totalMinutes) / baseMinutes;

    return progress;
};

bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int CalcDaysInMonth(int year, int month) {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && IsLeapYear(year)) {
        return 29;
    }

    return days[month - 1];
}

int CalcTotalDays(Date& D) {
    int totalDays = 0;
  
    for (int month = 1; month < D.month; ++month) {
        totalDays += CalcDaysInMonth(D.year, month);
    }

    totalDays += D.day - 1;

    return totalDays;
}