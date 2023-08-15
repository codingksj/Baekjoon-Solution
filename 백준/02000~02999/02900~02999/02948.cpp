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

string GetDayOfWeek(int month, int day);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int M, D;

    cin >> D >> M;
    cout << GetDayOfWeek(M, D);
    return 0;
}

string GetDayOfWeek(int month, int day) {
    string daysOfWeek[] = { "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday" };
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int totalDays = 0;

    for (int i = 1; i < month; i++) {
        totalDays += daysInMonth[i];
    }
    totalDays += day - 1;

    int dayIndex = totalDays % 7;

    return daysOfWeek[dayIndex];
};