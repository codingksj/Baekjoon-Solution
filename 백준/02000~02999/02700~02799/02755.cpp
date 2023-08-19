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
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, char> MapSc;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

double CalcGPA(vector<Pis>& grades);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Pis> grades;
    Pis grade;
    string subject;
    double gpa;

    int TC;

    cin >> TC;

    while (TC--) {
        cin >> subject >> grade.first >> grade.second;
        grades.push_back(grade);
    }

    gpa = CalcGPA(grades);

    gpa += 1E-7;

    cout.precision(2);
    cout << fixed;
    cout << gpa << "\n";

    return 0;
}

double CalcGPA(vector<Pis>& grades) {
    HashSd score_table = {
        {"A+", 4.3}, {"A0", 4.0}, {"A-", 3.7},
        {"B+", 3.3}, {"B0", 3.0}, {"B-", 2.7},
        {"C+", 2.3}, {"C0", 2.0}, {"C-", 1.7},
        {"D+", 1.3}, {"D0", 1.0}, {"D-", 0.7},
        {"F", 0.0}
    };
    int totalCredit = 0;
    double gpa;
    double sum = 0;

    for (Pis& p : grades) {
        sum += score_table[p.second] * p.first;
        totalCredit += p.first;
    }
    gpa = sum / totalCredit;

    return gpa;
};