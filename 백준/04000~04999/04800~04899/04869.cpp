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

Words PreProcessing(string& line);
Words MoveScale(Words& pitch_names, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words pitch_names;
    string line;
    int N;

    while (true) {
        getline(cin, line);

        if (line == "***") {
            break;
        }

        pitch_names = PreProcessing(line);

        cin >> N;
        cin.ignore();

        pitch_names = MoveScale(pitch_names, N);

        for (string pitch_name : pitch_names) {
            cout << pitch_name << ' ';
        }

        cout << "\n";
    }

    return 0;
}

Words PreProcessing(string& line) {
    MapSS changeTable = {
        {"Bb","A#"},
        {"Cb","B"},
        {"B#","C"},
        {"Db","C#"},
        {"Eb","D#"},
        {"Fb","E"},
        {"E#","F"},
    };
    Words pitch_names;
    string pitch_name, s;
    string cur = line;
    int maxL;

    for (pair<const string, string>& p : changeTable) {
        while (true) {
            size_t pos = cur.find(p.first);
            s = p.second;
            maxL = p.first.length();
            if (pos == string::npos) {
                break;
            }
            cur.replace(pos, maxL, s);
        }
    }
    istringstream iss(cur);

    while (iss >> pitch_name) {
        pitch_names.push_back(pitch_name);
    }

    return pitch_names;
};

Words MoveScale(Words& pitch_names, int N) {
    Words scale = { "A","A#","B","C","C#","D", "D#", "E","F","F#","G","G#" };
    Words moved;
    int index;

    for (string& pitch_name : pitch_names) {
        index = find(scale.begin(), scale.end(), pitch_name) - scale.begin();
        index = (index + N) % 12;
        (index < 0) && (index += 12);
        moved.push_back(scale[index]);
    }

    return moved;
};