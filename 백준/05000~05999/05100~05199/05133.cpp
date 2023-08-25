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
typedef pair<int, bool> Pib;
typedef pair<int, int> Pii;
typedef pair<int, string> Pis;
typedef pair<double, double> Pdd;
typedef pair<LL, LL> PLL;
typedef pair<string, int> Psi;
typedef map<int, string> MapiS;
typedef map<string, char> MapSc;
typedef map<string, int> MapSi;
typedef map<string, string> MapSS;
typedef map<string, LL> MapSL;
typedef unordered_map<string, LL> HashSL;
typedef unordered_map<string, double> HashSd;
typedef unordered_map<string, string> HashSS;
typedef vector<string> Words;
typedef vector<vector<int>> Matrix2D_i;

typedef struct Fraction {
    int inteagerPart;
    int denominator;
    int numerator;
}Fraction;

#define PI 3.141592653589793

int GCD(int a, int b);
vector<Fraction> GetFractions(int N, int C);
Fraction InitFraction(int C);
void PrintFractions(vector<Fraction>& ingredients, int TC, int N);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Fraction> ingredients;
    int TC;
    int N, C;

    cin >> TC;

    for (int i = 1; i <= TC; i++) {
        cin >> N >> C;
        ingredients = GetFractions(N, C);
        PrintFractions(ingredients, i, N);
    }
    return 0;
}

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

vector<Fraction> GetFractions(int N, int C) {
    vector<Fraction> fractions(N);

    for (int i = 0; i < N; i++) {
        fractions[i] = InitFraction(C);
    }

    return fractions;
};

Fraction InitFraction(int C) {
    Fraction fraction;
    int front, back1, back2;
    int gcd;
    char slash;

    cin >> front >> back1 >> slash >> back2;

    front *= C;
    back1 *= C;

    front += (back1 / back2);
    back1 %= back2;

    gcd = GCD(back1, back2);
    back1 /= gcd;
    back2 /= gcd;

    fraction = { front, back1, back2 };

    return fraction;
};

void PrintFractions(vector<Fraction>& ingredients, int TC, int N) {
    cout << "Data Set " << TC << ":" << "\n";
    for (int i = 0; i < N; i++) {
        cout << ingredients[i].inteagerPart;
        if (ingredients[i].denominator) {
            cout << ' ' << ingredients[i].denominator 
                << '/' << ingredients[i].numerator;
        }
        cout << "\n";
    }
    cout << "\n";
};