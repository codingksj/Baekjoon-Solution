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

void LoadPrices(vector<int>& packagePrices, vector<int>& eachPrices, const int M);
int CalcMinPrice(const int N, const int minP, const int minE);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> packagePrices, eachPrices;
    int minPrice;
    int N, M;
    int minP, minE;

    cin >> N >> M;

    LoadPrices(packagePrices, eachPrices, M);

    minP = *min_element(packagePrices.begin(), packagePrices.end());
    minE = *min_element(eachPrices.begin(), eachPrices.end());

    minPrice = CalcMinPrice(N, minP, minE);

    cout << minPrice << "\n";

    return 0;
}

void LoadPrices(vector<int>& packagePrices, vector<int>& eachPrices, const int M) {
    packagePrices.resize(M);
    eachPrices.resize(M);

    for (int i = 0; i < M; i++) {
        cin >> packagePrices[i] >> eachPrices[i];
    }    
};

int CalcMinPrice(const int N, const int minP, const int minE) {
    int minPrice;
    int packageCount = ceil((double)N / 6);
    int eachCount = N;

    minPrice = min(
        { packageCount * minP, 
        eachCount * minE, 
        (N / 6) * minP + (N % 6) * minE }
    );
    
    return minPrice;
};