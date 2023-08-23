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
typedef vector<vector<int>> Matrix2Di;

typedef struct Nutrient {
    string name;
    string unit;
    double amount;
    double requirement;
}Nutrient;

vector<Nutrient> GetNutrients();
void PrintNutrientsInfo(vector<Nutrient>& nutrients);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Nutrient> nutrients;
    
    nutrients = GetNutrients();
    PrintNutrientsInfo(nutrients);

    return 0;
}
vector<Nutrient> GetNutrients() {
    vector<Nutrient> nutrients;
    Nutrient nutrient;

    while (true) {
        cin >> nutrient.amount;
        if (nutrient.amount < 0) {
            break;
        }
        cin >> nutrient.unit >> nutrient.requirement;
        cin.ignore();
        getline(cin, nutrient.name);
        nutrients.push_back(nutrient);
    }

    return nutrients;
};

void PrintNutrientsInfo(vector<Nutrient>& nutrients) {
    Words low_nutrients;
    double percentage;
    bool hasLowNutrients;

    for (Nutrient& nutrient : nutrients) {
        percentage = (nutrient.amount * 100 / nutrient.requirement);
        if (percentage < 1) {
            hasLowNutrients = true;
            low_nutrients.push_back(nutrient.name);
            continue;
        }
        cout << nutrient.name << ' ' << setprecision(1) << fixed
            << nutrient.amount << ' ' << setprecision(0) << fixed
            << nutrient.unit << ' ' 
            << percentage << "%" << "\n";
    }

    if (hasLowNutrients) {
        cout << "Provides no significant amount of:" << "\n";
        for (string name : low_nutrients) {
            cout << name << '\n';
        }
    }
};