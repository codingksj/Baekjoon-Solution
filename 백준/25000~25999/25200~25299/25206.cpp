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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    map<string, double> gradeWeights = {
        {"A+", 4.5}, {"A0", 4.0},
        {"B+", 3.5}, {"B0", 3.0},
        {"C+", 2.5}, {"C0", 2.0},
        {"D+", 1.5}, {"D0", 1.0},
        {"F", 0.0}
    };
    vector<double> grades, credits;
    string subject, grade;
    double credit, creditSum, gradeSum;

    for (int i = 0; i < 20; i++) {
        cin >> subject >> credit >> grade;
        if (grade == "P") {
            continue;
        }
        grades.push_back(gradeWeights[grade] * credit);
        credits.push_back(credit);
    }
    gradeSum = accumulate(grades.begin(), grades.end(), 0.0);
    creditSum = accumulate(credits.begin(), credits.end(), 0.0);

    cout.precision(9);
    cout << fixed;
    cout << gradeSum / creditSum << "\n";
    return 0;
}

