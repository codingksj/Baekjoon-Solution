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

typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
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

typedef struct Student {
    string name;
    int year;
    int month;
    int day;

    bool operator< (const Student& other) const {
        if (year != other.year) {
            return year > other.year;
        }
        if (month != other.month) {
            return month > other.month;
        }
        return day > other.day;
    }
};

vector<Student> LoadStudents(int N);
PSS FindMinMaxBirthday(vector<Student>& students, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Student> students;
    PSS ans;
    int N;

    cin >> N;

    students = LoadStudents(N);
    ans = FindMinMaxBirthday(students, N);

    cout << ans.first << "\n"
        << ans.second << "\n";

    return 0;
}

vector<Student> LoadStudents(int N) {
    vector<Student> students(N);

    for (Student& st : students) {
        cin >> st.name >> st.day >> st.month >> st.year;
    }

    return students;
};

PSS FindMinMaxBirthday(vector<Student>& students, int N) {
    vector<Student> cp_students = students;
    PSS ans;

    sort(cp_students.begin(), cp_students.end());

    ans = { cp_students[0].name, cp_students[N - 1].name };

    return ans;
};