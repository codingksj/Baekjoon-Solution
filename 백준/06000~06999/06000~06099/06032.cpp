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

typedef struct Toy {
    LL joy;
    LL price;
    int index;
    double hfm;

    bool operator> (const Toy& other) const {
        return hfm > other.hfm;
    }
}Toy;

vector<Toy> LoadToys(int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Toy> toys;
    LL total_price = 0;
    int N;

    cin >> N;

    toys = LoadToys(N);

    sort(toys.begin(), toys.end(), greater<Toy>());

    for (int i = 0; i < 3; i++) {
        total_price += toys[i].price;
    }

    cout << total_price << "\n";

    for (int i = 0; i < 3; i++) {
        cout << toys[i].index << "\n";
    }

    return 0;
}

vector<Toy> LoadToys(int N) {
    vector<Toy> toys;
    int index = 1;

    toys.resize(N);

    for (Toy& toy : toys) {
        cin >> toy.joy >> toy.price;
        toy.hfm = (double)toy.joy / toy.price;
        toy.index = index++;
    }

    return toys;
};