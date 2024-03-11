#include<bits/stdc++.h>

// ---------- 사용자 정의 자료형 ----------
using namespace std;

// ---------- 사용자 정의 함수 및 연산자 ----------
bool Input();
void Solve();
void Output();

// ---------- 열거형 상수 ----------

// ---------- 전역 변수 ----------
string gear1, gear2;
int minW, w;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Solve();
    Output();

    return 0;
}

bool Input() {
    getline(cin, gear1);
    getline(cin, gear2);

    if (gear1.length() < gear2.length()) {
        swap(gear1, gear2);
    }
  
    return true;
};

void Solve() {
    int L1 = gear1.length();
    int L2 = gear2.length();
    bool isMatch;

    gear1 = string(L2, '-') + gear1 + string(L2, '-');
    minW = L1 + L2;

    for (int p1 = 0; p1 <= L2 + L1; p1++) {
        isMatch = true;
        for (int p2 = 0; p2 < L2; p2++) {
            if (gear1[p1 + p2] == '2' && gear2[p2] == '2') {
                isMatch = false;
                break;
            }
        }
        if (!isMatch) {
            continue;
        }
        w = p1 < L2 ? (L1 + L2 - p1) : (max(p1 + L2, L1 + L2) - L2);
        minW = min(minW, w);
    }
};

void Output() {
    cout << minW << "\n";
}