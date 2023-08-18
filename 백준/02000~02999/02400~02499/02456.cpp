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
typedef pair<int, int> Pii;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, string> UMapSS;
typedef vector<string> Words;

typedef struct _candidate {
    int index;
    int scoreCount[4];
    int sumOfScore;
    bool hasSameRank;
}Candidate;

vector<Candidate> InitializeCandidates(int N);
bool Cmp(Candidate& c1, Candidate& c2);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Candidate> candidates = InitializeCandidates(4);
    Candidate answer;
    int scoreOfCandidates[4];
    int TC;

    cin >> TC;

    while (TC--) {
        for (int i = 1; i <= 3; i++) {
            cin >> scoreOfCandidates[i];
            candidates[i].sumOfScore += scoreOfCandidates[i];
            candidates[i].scoreCount[scoreOfCandidates[i]]++;
        }
    }
    sort(candidates.begin(), candidates.end(), Cmp);

    answer = *candidates.rbegin();

    cout << (answer.hasSameRank ? 0 : answer.index) << " " 
        << answer.sumOfScore;

    return 0;
}

vector<Candidate> InitializeCandidates(int N) {
    vector<Candidate> candidates(N); 
    Candidate candidate;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            candidate.scoreCount[j] = 0; 
        }
        candidate.index = i;
        candidate.sumOfScore = 0; 
        candidate.hasSameRank = false;
        candidates[i] = candidate; 
    }

    return candidates;
};

bool Cmp(Candidate& c1, Candidate& c2) {
    if (c1.sumOfScore != c2.sumOfScore) {
        return c1.sumOfScore < c2.sumOfScore;
    }
    if (c1.scoreCount[3] != c2.scoreCount[3]) {
        return c1.scoreCount[3] < c2.scoreCount[3];
    }
    if (c1.scoreCount[2] != c2.scoreCount[2]) {
        return c1.scoreCount[2] < c2.scoreCount[2];
    }

    c1.hasSameRank = c2.hasSameRank = true;
    return c1.sumOfScore < c2.sumOfScore;
};