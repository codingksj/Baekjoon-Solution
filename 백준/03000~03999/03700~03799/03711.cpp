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
typedef vector<vector<LL>> Matrix2D_L;

vector<int> GetStudents(int N);
int FindMinMod(vector<int>& students);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> students;
    int TC, N;
    int mod;

    cin >> TC;

    while (TC--) {
        cin >> N;

        students = GetStudents(N);
        mod = FindMinMod(students);

        cout << mod << "\n";
    }

    return 0;
}

vector<int> GetStudents(int N) {
    vector<int> students(N);

    for (int& student : students) {
        cin >> student;
    }

    return students;
};

int FindMinMod(vector<int>& students) {
    set<int> mods;
    int sN = students.size();
    int mN;
    int mod;

    if (sN == 1) {
        return 1;
    }

    for (int m = 1;; m++) {
        mods.clear();

        for (int& st : students) {
            mods.insert(st % m);
        }

        mN = mods.size();

        if (mN == sN) {
            mod = m;
            break;
        }
    }

    return mod;
};