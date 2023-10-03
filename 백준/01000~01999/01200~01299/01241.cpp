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

typedef pair<char, char> Pcc;
typedef pair<char, int> Pci;
typedef pair<char, string> PcS;
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> PiS;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> PSi;
typedef pair<string, LL> PSL;
typedef pair<string, string> PSS;

typedef map<int, int> Mapii;
typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<LL, LL> HashLL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

#define MAX 1E+6

vector<int> LoadStudents(const int N);
vector<int> MakeNumberCounts(const vector<int>& V);
vector<int> MakeTouchCounts(const vector<int>& students, const vector<int>& numCounts);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> students, numCounts, touchCounts;
    int N;

    cin >> N;

    students = LoadStudents(N);
    numCounts = MakeNumberCounts(students);
    touchCounts = MakeTouchCounts(students, numCounts);

    for (const int& e : touchCounts) {
        cout << e << "\n";
    }

    return 0;
}

vector<int> LoadStudents(const int N) {
    vector<int> students(N);

    for (int& st : students) {
        cin >> st;
    }

    return students;
};

vector<int> MakeNumberCounts(const vector<int>& V) {
    vector<int> numCounts(MAX + 1, 0);

    for (const int& e : V) {
        numCounts[e]++;
    }

    return numCounts;
};

vector<int> MakeTouchCounts(const vector<int>& students, const vector<int>& numCounts) {
    vector<int> touchCounts;
    int cnt;

    for (const int& st : students) {
        cnt = -1;

        for (int i = 1; i * i <= st; i++) {
            if (st % i) {
                continue;
            }
            cnt += (i * i == st) ?
                numCounts[i] :
                numCounts[st / i] + numCounts[i];
        }
        touchCounts.push_back(cnt);
    }

    return touchCounts;
};


