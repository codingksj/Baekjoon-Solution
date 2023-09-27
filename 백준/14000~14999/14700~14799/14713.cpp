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

typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

deque<string> MakeWordDeque(const string& words);
vector<deque<string>> MakeWordDeques(const int N);
bool CheckPossibleSentence(const vector<deque<string>>& wordDqs, const deque<string>& targetDq);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<deque<string>> wordDq;
    deque<string> targetDq;
    string target;
    int N;
    bool isPossible;

    cin >> N;
    cin.ignore();

    wordDq = MakeWordDeques(N);

    getline(cin, target);

    targetDq = MakeWordDeque(target);
    isPossible = CheckPossibleSentence(wordDq, targetDq);

    cout << (isPossible ? "Possible" : "Impossible") << "\n";

    return 0;
}

deque<string> MakeWordDeque(const string& words) {
    istringstream iss(words);
    deque<string> wordDq;
    string word;

    while (iss >> word) {
        wordDq.push_back(word);
    }

    return wordDq;
}

vector<deque<string>> MakeWordDeques(const int N) {
    vector<deque<string>> wordDqs(N);
    string word;

    for (deque<string>& wordDeque : wordDqs) {
        getline(cin, word);
        wordDeque = MakeWordDeque(word);
    }

    return wordDqs;
}

bool CheckPossibleSentence(const vector<deque<string>>& wordDqs, const deque<string>& targetDq) {
    vector<deque<string>> wordDqs2 = wordDqs;
    deque<string> targetDq2 = targetDq;
    int size = targetDq2.size();
    bool isPossible, hasPopped;

    for (int i = 0; i < size; i++) {
        hasPopped = false;

        for (deque<string>& dq : wordDqs2) {
            if (dq.empty()) {
                continue;
            }
            if (dq.front() == targetDq2.front()) {
                hasPopped = true;
                dq.pop_front();
                targetDq2.pop_front();
                break;
            }
        }
        if (!hasPopped) {
            break;
        }
    }

    wordDqs2.push_back(targetDq2);

    isPossible = true;

    for (deque<string>& dq : wordDqs2) {
        if (!dq.empty()) {
            isPossible = false;
            break;
        }
    }

    return isPossible;
}