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

typedef struct Student {
    int nationalNum;
    int studentNum;
    int score;

    bool operator> (const Student& other) const {
        return score > other.score;
    }
}Student;

vector<Student> GetStudents(int N);
vector<Student> FindWinners(vector<Student>& students);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Student> students;
    vector<Student> winners;
    int N;

    cin >> N;

    students = GetStudents(N);
    winners = FindWinners(students);

    for (Student& winner : winners) {
        cout << winner.nationalNum << ' ' << winner.studentNum << "\n";
    }

    return 0;
}

vector<Student> GetStudents(int N) {
    vector<Student> students(N);

    for (Student& student : students) {
        cin >> student.nationalNum 
            >> student.studentNum 
            >> student.score;
    }

    return students;
};

vector<Student> FindWinners(vector<Student>& students) {
    vector<Student> copy = students;
    vector<Student> winners;
    int nationCount[101] = { 0, };
    int count = 0;

    sort(copy.begin(), copy.end(), greater<Student>());

    for (Student& student : copy) {
        if (nationCount[student.nationalNum] < 2) {
            winners.push_back(student);
            nationCount[student.nationalNum]++;
            count++;
        }
        if (count == 3) {
            break;
        }
    }

    return winners;
};