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

bool IsLeapYear(int year);
bool IsValidDate(int day, int month, int year);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int D, M, Y;
  
    while (true) {
        cin >> D >> M >> Y;
        if (D == 0 && M == 0 && Y == 0) {
            break;
        }
        cout << (IsValidDate(D, M, Y) ? "Valid" : "Invalid") << "\n";
    }

    return 0;
}

bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool IsValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth;
    switch (month) {
    case 2:
        daysInMonth = IsLeapYear(year) ? 29 : 28;
        break;
    case 4: case 6: case 9: case 11:
        daysInMonth = 30;
        break;
    default:
        daysInMonth = 31;
        break;
    }

    return day <= daysInMonth;
}