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
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> Pis;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<int, string> MapiS;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;
typedef vector<vector<int>> Matrix2Di;

bool FindStudent(Words& words, string name);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words students, words;
    string student, line, word;
    vector<int> canFind;
    int TC, N, lineNum;

    cin >> TC;

    for (int i = 1; i <= TC; i++) {
        cin >> N;

        while (N--) {
            cin >> student;
            students.push_back(student);
        }

        cin >> lineNum;
        cin.ignore();

        while (lineNum--) {
            getline(cin, line);
            istringstream iss(line);
            while (iss >> word) {
                words.push_back(word);
            }
        }

        cout << "Test set " << i << ":" << "\n";

        for (string name : students) {
            cout << name << " is "
                << (FindStudent(words, name) ? "present" : "absent")
                << "\n";
        }

        students.clear();
        cout << "\n";
    }

    return 0;
}

bool FindStudent(Words& words, string name) {
    auto it = find(words.begin(), words.end(), name);
    return (it != words.end());
};