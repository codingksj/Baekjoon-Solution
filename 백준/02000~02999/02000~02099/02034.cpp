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

vector<Pcc> FindPossibleNote(const vector<int>& sheet);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Pcc> possibleNotes;
    vector<int> sheet;
    int N;

    cin >> N;

    sheet.resize(N);

    for (int& note : sheet) {
        cin >> note;
    }

    possibleNotes = FindPossibleNote(sheet);

    if (!possibleNotes.empty()) {
        for (const Pcc& possibleNote : possibleNotes) {
            cout << possibleNote.first << " " << possibleNote.second << "\n";
        }
    }

    return 0;
}

vector<Pcc> FindPossibleNote(const vector<int>& sheet) {
    vector<Pcc> possibleNotes;
    const string pitchNames = "CXDXEFXGXAXB";
    char first, last;
    int index;
    bool isPossible;

    for (int start = 'A'; start <= 'G'; start++) {
        index = pitchNames.find(start);
        isPossible = true;

        for (const int& note : sheet) {
            index = (index + note) % 12;
            if (index < 0) {
                index += 12;
            }
            if (pitchNames[index] == 'X') {
                isPossible = false;
                break;
            }
        }
        first = start;
        last =  pitchNames[index];

        if (isPossible) {
            possibleNotes.push_back({ first, last });
        }
    }

    return possibleNotes;
};