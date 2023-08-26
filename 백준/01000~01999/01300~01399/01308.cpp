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
}Date;

Date GetDate();
string CalcDday(Date& D1, Date& D2);
bool IsLeapYear(int year);
int CalcDaysInMonth(int year, int month);
int CalcTotalDays(Date& date);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Date D1, D2;
    string answer;

    D1 = GetDate();
    D2 = GetDate();
    
    answer = CalcDday(D1, D2);

    cout << answer << "\n";

    return 0;
};

Date GetDate() {
    Date D;

    cin >> D.year >> D.month >> D.day;

    return D;
};

string CalcDday(Date& D1, Date& D2) {
    string answer;
    bool moreThan1000;
    int totalDaysD1 = CalcTotalDays(D1);
    int totalDaysD2 = CalcTotalDays(D2);
    int dy = D2.year - D1.year;
    int dm = D2.month - D1.month;
    int dd = D2.day - D1.day;

    moreThan1000 = dy > 1000 || (dy == 1000 && dm >= 0 && dd >= 0);

    answer = moreThan1000 ? "gg" : "D-" + to_string(totalDaysD2 - totalDaysD1);

    return answer;
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

int CalcTotalDays(Date& date) {
    int totalDays = 0;

    for (int year = 1; year < date.year; ++year) {
        totalDays += IsLeapYear(year) ? 366 : 365;
    }

    for (int month = 1; month < date.month; ++month) {
        totalDays += CalcDaysInMonth(date.year, month);
    }

    totalDays += date.day;

    return totalDays;
}
