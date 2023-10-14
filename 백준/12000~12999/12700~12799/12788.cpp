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

typedef tuple<int, int, int> Tiii;

typedef map<int, int> Mapii;
typedef map<int, string> MapiS;
typedef map<LL, LL> MapLL;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;

typedef unordered_map<LL, LL> HashLL;
typedef unordered_map<string, bool> HashSb;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<bool>> Matrix2D_b;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

vector<int> LoadPencils(const int N);
int CountPencilBorrow(const vector<int>& pencils, const int need);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> pencils;
    int N, M, K;
    int need, borrow;

    cin >> N;
    cin >> M >> K;

    need = M * K;
    pencils = LoadPencils(N);

    sort(pencils.begin(), pencils.end(), greater<int>());

    borrow = CountPencilBorrow(pencils, need);

    cout << ((borrow == -1) ? "STRESS" : to_string(borrow)) << "\n";

    return 0;
}

vector<int> LoadPencils(const int N) {
    vector<int> pencils(N);

    for (int& pencil : pencils) {
        cin >> pencil;
    }

    return pencils;
};

int CountPencilBorrow(const vector<int>& pencils, const int need) {
    int count = 0;
    int borrow = 0;

    for (const int& pencil : pencils) {
        if (need <= borrow) {
            break;
        }
        borrow += pencil;
        count++;
    }

    (need > borrow) && (count = -1);

    return count;
};

