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

Words LoadWords(const int N);
int CalcMaxSum(const Words& words);
int Power(const int base, const int exp);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Words words;
    int N, maxSum;

    cin >> N;
    cin.ignore();

    words = LoadWords(N);
    maxSum = CalcMaxSum(words);

    cout << maxSum << "\n";

    return 0;
}

Words LoadWords(const int N) {
    Words words(N);

    for (string& word : words) {
        cin >> word;
    }

    return words;
};

int CalcMaxSum(const Words& words) {
    vector<int> alphaValues(26, 0);
    int totalValue = 0;
    int length;
    int weight = 9;

    for (const string& word : words) {
        length = word.length();
        for (int i = 0; i < length; i++) {
            alphaValues[word[i] - 'A'] += Power(10, (length - i - 1));
        }
    }

    sort(alphaValues.begin(), alphaValues.end(), greater<int>());

    for (int& value : alphaValues) {
        totalValue += value * (weight--);
    }

    return totalValue;
};

int Power(const int base, const int exp) {
    int number = 1;

    for (int i = 0; i < exp; i++) {
        number *= base;
    }

    return number;
};