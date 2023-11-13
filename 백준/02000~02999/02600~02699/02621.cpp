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
#include<functional>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<chrono>

//사용자 정의 상수
#define PI 3.141592653589793
#define THOUSAND 1E+3
#define MILLION 1E+6
#define BILLION 1E+9

//사용자 정의 자료형
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
typedef vector<Matrix2D_b> Matrix3D_b;
typedef vector<Matrix2D_i> Matrix3D_i;

//사용자 정의 연산자


//템플릿 함수
template<typename T> vector<T> InitVector(const int SIZE, const T INIT) { return vector<T>(SIZE, INIT); }
template<typename T> vector<vector<T>> Init2DVector(const int R, const int C, const T INIT) { return vector<vector<T>>(R, vector<T>(C, INIT)); }

template<typename T> vector<T> LoadVector(const int SIZE) { vector<T> V(SIZE); for (T& e : V) { cin >> e; } return V; }
template<typename T> vector<vector<T>> Load2DVector(const int R, const int C) { vector<vector<T>> V(R, vector<T>(C)); for (vector<T>& row : V) { for (T& e : row) { cin >> e; } } return V; }
template<typename T1, typename T2> vector<pair<T1, T2>> LoadPairVector(const int SIZE) { vector<pair<T1, T2>> V(SIZE); for (pair<T1, T2>& p : V) { cin >> p.first >> p.second; } return V; }

template<typename T> void PrintVector(const vector<T>& V, const string seps) { for (const T& e : V) { cout << e << seps; } }
template<typename T> void Print2DVector(const vector<vector<T>>& V, const string sepsR, const string sepsC) { for (const vector<T>& row : V) { PrintVector(row, sepsC); cout << sepsR; } }

template<typename T, typename Compare = less<T>> void Sort(vector<T>& V, Compare cmp = Compare()) { sort(V.begin(), V.end(), cmp); }
template<typename T, typename Compare = less<T>> void Sort2D(vector<vector<T>>& V, Compare cmp = Compare()) { for (vector<T>& row : V) { sort(row.begin(), row.end(), cmp); } }
template<typename T, typename Compare = less<T>> void StableSort(vector<T>& V, Compare cmp = Compare()) { stable_sort(V.begin(), V.end(), cmp); }
template<typename T, typename Compare = less<T>> void StableSort2D(vector<vector<T>>& V, Compare cmp = Compare()) { for (vector<T>& row : V) { stable_sort(row.begin(), row.end(), cmp); } }

template<typename T> size_t LowerBoundIndex(const vector<T>& V, const T target) { const size_t index = lower_bound(V.begin(), V.end(), target) - V.begin(); return index; }
template<typename T> size_t UpperBoundIndex(const vector<T>& V, const T target) { const size_t index = upper_bound(V.begin(), V.end(), target) - V.begin(); return index; }

typedef struct Card {
    char suit;
    int rank;
}Card;

//사용자 지정 함수
vector<Card> LoadCards(const int N);
int CalcMaxScore(const vector<Card>& cards);
int ConvertSuitToIndex(const char c);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Card> cards;
    int N = 5;
    int score;

    cards = LoadCards(N);
    score = CalcMaxScore(cards);

    cout << score << "\n";

    return 0;
}

vector<Card> LoadCards(const int N) {
    vector<Card> cards(N);

    for (Card& card : cards) {
        cin >> card.suit >> card.rank;
    }

    return cards;
};

int CalcMaxScore(const vector<Card>& cards) {
    vector<int> rankCounts = InitVector<int>(10, 0);
    vector<int> suitCounts = InitVector<int>(4, 0);
    int high = 0;
    int pair1 = 0, pair2 = 0;
    int triple = 0;
    int quad = 0;
    int index;
    int score = 0;
    bool isStraight = false;
    bool isFlush = false;

    for (const Card& card : cards) {
        index = ConvertSuitToIndex(card.suit);
        rankCounts[card.rank]++;
        suitCounts[index]++;
        high = max(high, card.rank);
    }
    for (int i = 9; i > 4; i--) {
        isStraight = 
            (rankCounts[i] &&
            rankCounts[i - 1] &&
            rankCounts[i - 2] &&
            rankCounts[i - 3] &&
            rankCounts[i - 4]);
        if (isStraight) {
            break;
        }
    }

    for (int i = 9; i > 0; i--) {
        if (rankCounts[i] == 4) {
            quad = i;
        }
        if (rankCounts[i] == 3) {
            triple = i;
        }
        if (rankCounts[i] == 2) {
            (pair1 > 0) ? pair2 = i : pair1 = i;
        }

    }

    for (int& suitCount : suitCounts) {
        if (suitCount == 5) {
            isFlush = true;
            break;
        };
    }

    if (isStraight && isFlush) {
        score = 900 + high;
    }
    else if (quad) {
        score = 800 + quad;
    }
    else if (triple && pair1) {
        score = 700 + 10 * triple + pair1;
    }
    else if (isFlush) {
        score = 600 + high;
    }
    else if (isStraight) {
        score = 500 + high;
    }
    else if (triple) {
        score = 400 + triple;
    }
    else if(pair1 && pair2){
        score = 300 + 10 * pair1 + pair2;
    }
    else if (pair1) {
        score = 200 + pair1;
    }
    else {
        score = 100 + high;
    }
    return score;
};

int ConvertSuitToIndex(const char c) {
    for (int i = 0; i < 4; i++) {
        if (c == "RBYG"[i]) {
            return i;
        }
    }
    return 0;
};