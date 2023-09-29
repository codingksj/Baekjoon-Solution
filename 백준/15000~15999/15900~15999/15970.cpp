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

map<LL, vector<LL>> LoadColorArrows(const int N);
LL CalcTotalArrowLength(const map<LL, vector<LL>>& colorArrows);
LL CalcArrowLength(const vector<LL>& V);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    map<LL, vector<LL>> colorArrows;
    LL totalArrowLength;
    int N;

    cin >> N;

    colorArrows = LoadColorArrows(N);
    totalArrowLength = CalcTotalArrowLength(colorArrows);

    cout << totalArrowLength << "\n";

    return 0;
}

map<LL, vector<LL>> LoadColorArrows(const int N) {
    map<LL, vector<LL>> colorArrows;
    LL color, dot;

    for (int i = 0; i < N; i++) {
        cin >> dot >> color;
        colorArrows[color].push_back(dot);
    }

    return colorArrows;
};

LL CalcTotalArrowLength(const map<LL, vector<LL>>& colorArrows) {
    LL totalArrowLength = 0;

    for (const pair<LL, vector<LL>>& colorArrow : colorArrows) {
        totalArrowLength += CalcArrowLength(colorArrow.second);
    }

    return totalArrowLength;
};

LL CalcArrowLength(const vector<LL>& V) {
    vector<LL> sortedV = V;
    LL arrowLength = 0;
    LL length1, length2;
    int size = V.size();

    sort(sortedV.begin(), sortedV.end());

    for (int i = 0; i < size; i++) {
        if (i == 0) {
            arrowLength += sortedV[i + 1] - sortedV[i];
        }
        else if (i == size - 1) {
            arrowLength += sortedV[i] - sortedV[i - 1];
        }
        else {
            length1 = sortedV[i + 1] - sortedV[i];
            length2 = sortedV[i] - sortedV[i - 1];
            arrowLength += min(length1, length2);
        }
    }

    return arrowLength;
};

