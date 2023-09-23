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

Matrix2D_d LoadAbilities(const int N, const int M);
double CalcAbilitySum(Matrix2D_d& abilities, const int K);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Matrix2D_d abilities;
    int N, M, K;
    double abilitySum;

    cin >> N >> M >> K;

    abilities = LoadAbilities(N, M);
    abilitySum = CalcAbilitySum(abilities, K);

    cout << fixed << setprecision(1) << abilitySum << "\n";

    return 0;
}

Matrix2D_d LoadAbilities(const int N, const int M) {
    Matrix2D_d abilities(N, vector<double>(M, 0.0));
    double stat;
    int person;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> person >> stat;
            abilities[person - 1][i] = stat;
        }
    }

    return abilities;
};

double CalcAbilitySum(Matrix2D_d& abilities, const int K) {
    vector<double> final;
    double abilitySum;

    for (vector<double>& person : abilities) {
        sort(person.begin(), person.end(), greater<double>());
        final.push_back(person[0]);
    }

    sort(final.begin(), final.end(), greater<double>());

    abilitySum = accumulate(final.begin(), final.begin() + K, 0.0);

    return abilitySum;
};