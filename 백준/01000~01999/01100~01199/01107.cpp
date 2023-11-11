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

//사용자 지정 함수
vector<bool> LoadUsableButtons(const int brokenCount);
int CalcMinimumButtonPush(const vector<bool>& usableButtons, const int target);
bool CheckCanMakeNumber(const vector<bool>& usableButtons, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<bool> usableButtons;
    int target;
    int brokenCount;
    int minButtonPush;

    cin >> target;
    cin >> brokenCount;

    usableButtons = LoadUsableButtons(brokenCount);
    minButtonPush = CalcMinimumButtonPush(usableButtons, target);

    cout << minButtonPush << "\n";

    return 0;
}

vector<bool> LoadUsableButtons(const int brokenCount) {
    vector<bool> usableButtons = InitVector<bool>(10, true);
    int button;

    for (int i = 0; i < brokenCount; i++) {
        cin >> button;
        usableButtons[button] = false;
    }

    return usableButtons;
};

int CalcMinimumButtonPush(const vector<bool>& usableButtons, const int target) {
    int minButtonPush = abs(target - 100);
    int curButtonPush;
    const int MAX = 998994;

    for (int i = 0; i <= MAX; i++) {
        if (CheckCanMakeNumber(usableButtons, i)) {
            curButtonPush = abs(target - i) + to_string(i).length();
            minButtonPush = min(minButtonPush, curButtonPush);
        }
    }
    return minButtonPush;
};

bool CheckCanMakeNumber(const vector<bool>& usableButtons, const int N) {
    int number = N;

    do {
        if (!usableButtons[number % 10]) {
            return false;
        }
        number /= 10;
    } while (number);

    return true;
};