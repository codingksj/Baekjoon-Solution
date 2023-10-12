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

vector<Pii> LoadJewels(const int N);
vector<int> LoadBags(const int K);
LL CalcMaxStealValue(const vector<Pii>& jewels, const vector<int>& bags, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Pii> jewels;
    vector<int> bags;
    LL maxValue;
    int N, K;

    cin >> N >> K;

    jewels = LoadJewels(N);
    bags = LoadBags(K);

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    maxValue = CalcMaxStealValue(jewels, bags, N);

    cout << maxValue << "\n";

    return 0;
};

vector<Pii> LoadJewels(const int N) {
    vector<Pii> jewels(N);

    for (Pii& jewel : jewels) {
        cin >> jewel.first >> jewel.second;
    }

    return jewels;
};

vector<int> LoadBags(const int K) {
    vector<int> bags(K);

    for (int& bag : bags) {
        cin >> bag;
    }

    return bags;
};

LL CalcMaxStealValue(const vector<Pii>& jewels, const vector<int>& bags, const int N) {
    LL totalValue = 0;
    priority_queue<int> pq;
    int i = 0;

    for (const int& bag : bags) {
        for (; i < N && bag >= jewels[i].first; i++) {
            pq.push(jewels[i].second);
        }
        if (!pq.empty()) {
            totalValue += pq.top();
            pq.pop();
        }
    }

    return totalValue;
};