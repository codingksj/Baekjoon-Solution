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

//사용자 정의 상수
#define PI 3.141592653589793
#define THOUSAND 1E+3
#define MILLION 1E+6
#define BILLION 1E+9
#define MAX 2700

using namespace std;

//템플릿 함수
template<typename T> vector<T> InitVector(const int SIZE, const T INIT) { return vector<T>(SIZE, INIT);}
template<typename T> vector<vector<T>> Init2DVector(const int R, const int C, const T INIT) { return vector<vector<T>>(R, vector<T>(C,INIT)); }

template<typename T> vector<T> LoadVector(const int SIZE) { vector<T> V(SIZE); for (T& e : V) { cin >> e; } return V; }
template<typename T> vector<vector<T>> Load2DVector(const int R, const int C) { vector<vector<T>> V(R, vector<T>(C)); for (vector<T>& row : V) { for (T& e : row) { cin >> e; } } return V; }
template<typename T1, typename T2> vector<pair<T1, T2>> LoadPairVector(const int SIZE) { vector<pair<T1, T2>> V(SIZE); for (pair<T1, T2>& p : V) { cin >> p.first >> p.second; } return V; }

template<typename T> void PrintVector(const vector<T>& V, const string seps) { for (const T& e : V) { cout << e << seps; } }

template<typename T, typename Compare = less<T>> void Sort(vector<T>& V, Compare cmp = Compare()) { sort(V.begin(), V.end(), cmp); }
template<typename T, typename Compare = less<T>> void Sort2D(vector<vector<T>>& V, Compare cmp = Compare()) { for (vector<T>& row : V) { sort(row.begin(), row.end(), cmp); } }

//사용자 정의 자료형
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

//사용자 정의 함수
int Analyze(const int N);
vector<int> LoadPrimes(const int N);
bool CheckSumOfDigitsOdd(const int N);
bool CheckCompositeNumber(const vector<int>& primes, const int N);
bool CheckPrimeFactorsKindEven(const vector<int>& primes, const int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, type;
    
    cin >> N;

    type = Analyze(N);

    cout << type << "\n";

    return 0;
}

int Analyze(const int N) {
    vector<int> primes = LoadPrimes(MAX);
    int type;
    bool isOdd = CheckSumOfDigitsOdd(N);
    bool isComposite = CheckCompositeNumber(primes, N);
    bool isKindEven = CheckPrimeFactorsKindEven(primes, N);
    bool isType1 = (N == 4 || N >= 6) && isOdd;
    bool isType2 = N == 2 || N == 4 || (isComposite && isKindEven);

    type = isType1 ? (isType2 ? 4 : 1) : (isType2 ? 2 : 3);

    return type;
};

vector<int> LoadPrimes(const int N) {
    vector<int> primes = { 2 };
    vector<bool> isPrime(N + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 3; i <= N; i += 2) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
};

bool CheckSumOfDigitsOdd(const int N) {
    int number = N;
    int sumOfDigits = 0;
    bool isOdd;

    while (number) {
        sumOfDigits += number % 10;
        number /= 10;
    }
    
    isOdd = sumOfDigits & 1;

    return isOdd;
};

bool CheckCompositeNumber(const vector<int>& primes, const int N) {
    bool isComposite = N > 1;

    for (const int& p : primes) {
        if (N == p) {
            isComposite = false;
            break;
        }
    }

    return isComposite;
};

bool CheckPrimeFactorsKindEven(const vector<int>& primes, const int N) {
    int number = N;
    int kindCount = 0;
    bool isKindEven;

    for (const int& p : primes) {
        if (number % p) {
            continue;
        }
        while (!(number % p)) {
            number /= p;
        }
        kindCount++;
    }

    isKindEven = !(kindCount & 1);

    return isKindEven;
};