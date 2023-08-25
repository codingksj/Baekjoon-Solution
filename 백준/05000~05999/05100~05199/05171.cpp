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
typedef vector<vector<int>> Matrix2D_i;

typedef struct Fingerprint {
    char fingerprint[5][5];
}Fingerprint;

#define PI 3.141592653589793

vector<Fingerprint> MakeFingerprintDB(int N);
Fingerprint GetFingerprint();
string FindCriminal(vector<Fingerprint>& db, Fingerprint& criminal);
int CalcSimilarity(Fingerprint& suspect, Fingerprint& criminal);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
   
    vector<Fingerprint> policeDb;
    Fingerprint criminal;
    string answer;
    int TC, N;

    cin >> N >> TC;

    policeDb = MakeFingerprintDB(N);

    for (int i = 1; i <= TC; i++) {
        criminal = GetFingerprint();
        answer = FindCriminal(policeDb, criminal);

        cout << "Data Set " << i << ":\n"
            << answer << "\n\n";
    }

    return 0;
}

vector<Fingerprint> MakeFingerprintDB(int N) {
    vector<Fingerprint> policeDb(N);

    for (Fingerprint& criminal : policeDb) {
        criminal = GetFingerprint();
    }

    return policeDb;
};

Fingerprint GetFingerprint() {
    Fingerprint criminal;

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            cin >> criminal.fingerprint[r][c];
        }
    }

    return criminal;
};

string FindCriminal(vector<Fingerprint>& db, Fingerprint& criminal) {
    string answer = "";
    vector<int> similarities;
    int maxSimilarity = 0;
    int similarity;
    int index = 1;

    for (Fingerprint& suspect : db) {
        similarity = CalcSimilarity(suspect, criminal);
        similarities.push_back(similarity);
        maxSimilarity = max(similarity, maxSimilarity);
    }

    for (int e : similarities) {
        if (e == maxSimilarity) {
            answer += to_string(index) + ' ';
        }
        index++;
    }

    return answer;
};

int CalcSimilarity(Fingerprint& suspect, Fingerprint& criminal) {
    int similarity = 0;

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            (suspect.fingerprint[r][c] == criminal.fingerprint[r][c]) && similarity++;
        }
    }

    return similarity;
};