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
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;

void MoveVecToArr(int cards[334][3], vector<int>& V, int K);
void MoveArrToVec(int cards[334][3], vector<int>& V, int K);
set<int> GetCol(int cards[334][3], string& s, int K);
void GetResult(int cards[334][3], set<int>& answer, set<int>& cols);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> numbers;
    set<int> answers, cols;
    string s;
    int cards[334][3] = { 0, };
    int N, D, K;

    cin >> N;

    K = N / 3;

    for (int i = 0; i < N; i++) {
        numbers.push_back(i + 1);
    }

    answers = set<int>(numbers.begin(), numbers.end());

    cin >> D;
    
    while (D--) {
        MoveVecToArr(cards, numbers, K);

        cin >> s;

        cols = GetCol(cards, s, K);

        GetResult(cards, answers, cols);

        MoveArrToVec(cards, numbers, K);
    }

    if (!answers.empty()) {
        for (int answer : answers) {
            cout << answer << " ";
        }
    }

    return 0;
}

void MoveVecToArr(int cards[334][3], vector<int>& V, int K) {
    for (int r = 0; r < K; r++) {
        for (int c = 0; c < 3; c++) {
            cards[r][c] = V[3 * r + c];
        }
    }
    V.clear();
};

void MoveArrToVec(int cards[334][3], vector<int>& V, int K) {
    for (int c = 0; c < 3; c++) {
        for (int r = 0; r < K; r++) {
            V.push_back(cards[r][c]);
        }
    }
    memset(cards, 0, sizeof(cards));
};

set<int> GetCol(int cards[334][3], string& s, int K) {
    MapSi table = {
        {"first",0},
        {"second",1},
        {"third",2},
    };
    set<int> cols;
    int c = table[s];

    for (int r = 0; r < K; r++) {
        cols.insert(cards[r][c]);
    }

    return cols;
};

void GetResult(int cards[334][3], set<int>& answer, set<int>& cols) {
    set<int> temp = answer;

    answer.clear();

    set_intersection(cols.begin(), cols.end(), temp.begin(), temp.end(),
        inserter(answer, answer.begin()));

    cols.clear();
};