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

typedef unordered_map<LL, LL> HashLL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;

typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;
typedef vector<vector<LL>> Matrix2D_L;
typedef vector<vector<double>> Matrix2D_d;

priority_queue<int, vector<int>, greater<int>> LoadPriorityQueue(const int N);
int CalcMinCompare(const priority_queue<int, vector<int>, greater<int>>& pq, const int M);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    priority_queue<int, vector<int>, greater<int>> pq;
    int N, ans;

    cin >> N;

    pq = LoadPriorityQueue(N);
    ans = CalcMinCompare(pq, N);

    cout << ans << "\n";

    return 0;
}

priority_queue<int, vector<int>, greater<int>> LoadPriorityQueue(const int N) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int a;

    for (int i = 0; i < N; i++) {
        cin >> a;
        pq.push(a);
    }

    return pq;
}

int CalcMinCompare(const priority_queue<int, vector<int>, greater<int>>& pq, const int N) {
    priority_queue<int, vector<int>, greater<int>> pq2 = pq;
    int n1 = 0, n2 = 0;
    int sum, ans = 0;

    for (int i = 0; i < N - 1; i++) {
        n1 = pq2.top();
        pq2.pop();

        n2 = pq2.top();
        pq2.pop();

        sum = n1 + n2;
        pq2.push(sum);

        ans += sum;
    }

    return ans;
}