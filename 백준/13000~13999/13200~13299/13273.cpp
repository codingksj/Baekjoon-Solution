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

// ---------- 사용자 정의 상수 ----------
#define PI 3.141592653589793
#define THOUSAND 1E+3
#define MILLION 1E+6
#define BILLION 1E+9

// ---------- 사용자 정의 자료형 ----------
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

typedef vector<string> Words;

// ---------- 템플릿 자료형 ----------
template<typename T> struct Matrix2D {
    vector<vector<T>> m2;

    Matrix2D() {};
    Matrix2D(const size_t R, const size_t C, const T INIT) {
        m2 = vector<vector<T>>(R, vector<T>(C, INIT));
    }
};
template<typename T> struct Matrix3D {
    vector<vector<vector<T>>> m3;

    Matrix3D() {};
    Matrix3D(const size_t H, const size_t R, const size_t C, const T INIT) {
        m3 = vector<vector<vector<T>>>(H, vector<vector<T>>(R, vector<T>(C, INIT)));
    }
};

// ---------- 템플릿 함수 ----------
template<typename T> vector<T> InitVector(const size_t SIZE, const T INIT) {
    return vector<T>(SIZE, INIT);
}
template<typename T> vector<vector<T>> Init2DVector(const size_t R, const size_t C, const T INIT) {
    return vector<vector<T>>(R, InitVector(C, INIT));
}
template<typename T> vector<vector<vector<T>>> Init3DVector(const size_t H, const size_t R, const size_t C, const T INIT) {
    return vector<vector<vector<T>>>(H, Init2DVector(R, C, INIT));
}

template<typename T1, typename T2> pair<T1, T2> LoadPair() {
    pair<T1, T2> p;
    cin >> p.first >> p.second;
    return p;
};
template<typename T> vector<T> LoadVector(const size_t SIZE) {
    vector<T> V(SIZE);
    for (T& e : V) {
        cin >> e;
    }
    return V;
}
template<typename T1, typename T2> vector<pair<T1, T2>> LoadVector(const size_t SIZE) {
    vector<pair<T1, T2>> V(SIZE);
    for (pair<T1, T2>& p : V) {
        p = LoadPair<T1, T2>();
    }
    return V;
}
template<typename T> vector<vector<T>> Load2DVector(const size_t R, const size_t C) {
    vector<vector<T>> V(R, vector<T>(C));
    for (vector<T>& row : V) {
        row = LoadVector<T>(C);
    }
    return V;
}
template<typename T1, typename T2> vector<vector<pair<T1, T2>>> Load2DVector(const size_t R, const size_t C) {
    vector<vector<pair<T1, T2>>> V(R, vector<pair<T1, T2>>(C));
    for (vector<pair<T1, T2>>& row : V) {
        row = LoadVector<T1, T2>(C);
    }
    return V;
}

template<typename T1, typename T2> void PrintPair(const pair<T1, T2>& p, const string sepsPair) {
    cout << p.first << sepsPair << p.second;
}
template<typename T> void PrintVector(const vector<T>& V, const string sepsC) {
    for (const T& e : V) {
        cout << e << sepsC;
    }
}
template<typename T1, typename T2> void PrintVector(const vector<pair<T1, T2>>& V, const string sepsC, const string sepsPair) {
    for (const pair<T1, T2>& p : V) {
        PrintPair<T1, T2>(p, sepsPair);
        cout << sepsC;
    }
}
template<typename T> void Print2DVector(const vector<vector<T>>& V, const string sepsR, const string sepsC) {
    for (const vector<T>& row : V) {
        PrintVector(row, sepsC);
        cout << sepsR;
    }
}
template<typename T1, typename T2> void Print2DVector(const vector<vector<pair<T1, T2>>>& V, const string sepsR, const string sepsC, const string sepsPair) {
    for (const vector<pair<T1, T2>>& row : V) {
        PrintVector<T1, T2>(row, sepsC, sepsPair);
        cout << sepsR;
    }
}

template<typename T, typename Compare = less<T>> void Sort(vector<T>& V, Compare cmp = Compare()) {
    sort(V.begin(), V.end(), cmp);
}
template<typename T, typename Compare = less<T>> void Sort2D(vector<vector<T>>& V, Compare cmp = Compare()) {
    for (vector<T>& row : V) {
        Sort(row, cmp);
    }
}
template<typename T, typename Compare = less<T>> void StableSort(vector<T>& V, Compare cmp = Compare()) {
    stable_sort(V.begin(), V.end(), cmp);
}
template<typename T, typename Compare = less<T>> void StableSort2D(vector<vector<T>>& V, Compare cmp = Compare()) {
    for (vector<T>& row : V) {
        StableSort(row, cmp);
    }
}

template<typename T> size_t LowerBoundIndex(const vector<T>& V, const T target) {
    const size_t index = lower_bound(V.begin(), V.end(), target) - V.begin();
    return index;
}
template<typename T> size_t UpperBoundIndex(const vector<T>& V, const T target) {
    const size_t index = upper_bound(V.begin(), V.end(), target) - V.begin(); return index;
}

// ---------- 사용자 정의 함수 ----------
string ToRoman(const string& decimal);
string ToDecimal(const string& roman);
bool CheckSpecialRoman(const string& roman, const int pos);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string number, convertedNumber;
    int TC;
    bool isRoman;

    cin >> TC;
    cin.ignore();

    while (TC--) {
        getline(cin, number);
        
        isRoman = isalpha(number[0]);
        convertedNumber = isRoman ? ToDecimal(number) : ToRoman(number);

        cout << convertedNumber << "\n";
    }

    return 0;
}

string ToRoman(const string& decimal) {
    string roman;
    int value = stoi(decimal);
    int count;

    if (value >= 1000) {
        count = value / 1000;
        roman += string(count, 'M');
        value %= 1000;
    }
    if (value >= 100) {
        count = value / 100;
        switch (count) {
            case 9: 
                roman += "CM";
                break;
            case 8:
            case 7:
            case 6:
            case 5:
                roman += 'D';
                roman += string(count - 5, 'C');
                break;
            case 4:
                roman += "CD";
                break;
            case 3:
            case 2:
            case 1:
                roman += string(count, 'C');
                break;
            default:
                break;
        }
        value %= 100;
    }
    if (value >= 10) {
        count = value / 10;
        switch (count) {
            case 9:
                roman += "XC";
                break;
            case 8:
            case 7:
            case 6:
            case 5:
                roman += 'L';
                roman += string(count - 5, 'X');
                break;
            case 4:
                roman += "XL";
                break;
            case 3:
            case 2:
            case 1:
                roman += string(count, 'X');
                break;
            default:
                break;
        }
        value %= 10;
    }
    if (value > 0) {
        count = value;
        switch (count) {
            case 9:
                roman += "IX";
                break;
            case 8:
            case 7:
            case 6:
            case 5:
                roman += 'V';
                roman += string(count - 5, 'I');
                break;
            case 4:
                roman += "IV";
                break;
            case 3:
            case 2:
            case 1:
                roman += string(count, 'I');
                break;
            default:
                break;
        }
    }

    return roman;
};

string ToDecimal(const string& roman) {
    map<char, int> convertTable = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500},
        {'M', 1000}
    };
    string decimal;
    int maxLength = roman.length();
    int value = 0;

    for (int i = 0; i < maxLength; i++) {
        if (i < maxLength - 1 && CheckSpecialRoman(roman, i)) {
            value += convertTable[roman[i + 1]] - convertTable[roman[i]];
            i++;
        }
        else {
            value += convertTable[roman[i]];
        }
    }

    decimal = to_string(value);

    return decimal;
};

bool CheckSpecialRoman(const string& roman, const int pos) {
    char c1, c2;
    bool isSpecial = false;

    c1 = roman[pos];
    c2 = roman[pos + 1];

    isSpecial = (c1 == 'I' && c2 == 'V') ||
        (c1 == 'I' && c2 == 'X') ||
        (c1 == 'X' && c2 == 'L') ||
        (c1 == 'X' && c2 == 'C') ||
        (c1 == 'C' && c2 == 'D') ||
        (c1 == 'C' && c2 == 'M');

    return isSpecial;
};