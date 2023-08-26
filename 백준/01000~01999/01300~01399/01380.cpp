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

vector<PiS> GetStudents(int N);
PiS FindStudent(vector<PiS>& students, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<PiS> students;
    PiS student;
    int N;
    int TC = 1;

    while (cin >> N) {
        cin.ignore();

        if (N == 0) {
            break;
        }

        students = GetStudents(N);
        student = FindStudent(students, N);

        cout << TC++ << ' ' << student.second << "\n";
    }

    return 0;
};

vector<PiS> GetStudents(int N) {
    vector<PiS> students(N);
    int index = 1;

    for (PiS& student : students) {
        student.first = index++;
        getline(cin, student.second);
    }

    return students;
};

PiS FindStudent(vector<PiS>& students, int N) {
    PiS ans;
    bitset<102> checks;
    int number;
    char trash;

    for (int i = 0; i < 2 * N - 1; i++) {
        cin >> number >> trash;
        checks.flip(number);
    }

    for (int i = 1; i <= N; i++) {
        if (checks[i]) {
            ans = students[i - 1];
            break;
        }
    }
    return ans;
};