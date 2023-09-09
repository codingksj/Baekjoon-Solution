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

int CountHotelRoom(int start, int end);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    int count;

    while (cin >> N >> M) {
        count = CountHotelRoom(N, M);
        cout << count << "\n";
    }

    return 0;
}

int CountHotelRoom(int start, int end) {
    bitset<10> check;
    string N;
    bool isLucky;
    int count = 0;

    for (int i = start; i <= end; i++) {
        check.reset();
        N = to_string(i);
        isLucky = true;

        for (char digit : N) {
            if (check[digit - '0']) {
                isLucky = false;
                break;
            }
            check[digit - '0'] = 1;
        }

        isLucky && count++;
    }

    return count;
};