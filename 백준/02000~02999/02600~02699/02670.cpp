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

double FIndMaxPartialProduct(const vector<double>& V, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<double> V;
    double maxProduct;
    int N;

    cin >> N;

    V.resize(N);

    for (double& e : V) {
        cin >> e;
    }

    maxProduct = FIndMaxPartialProduct(V, N);

    cout << setprecision(3) << fixed << maxProduct << "\n";

    return 0;
}

double FIndMaxPartialProduct(const vector<double>& V, const int N) {
    double curProduct;
    double maxProduct = 0;

    for (int i = 0; i < N; i++) {
        curProduct = 1;
        for (int j = i; j < N; j++) {
            curProduct *= V[j];
            if (curProduct == 0) {
                break;
            }
            maxProduct = max(maxProduct, curProduct);
        }
    }

    return maxProduct;
};