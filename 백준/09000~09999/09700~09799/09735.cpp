#include<iostream>
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
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;

/*

주요 개념 : 인수 정리, 계수 비교법, 근의 공식, 이차방정식 판별식

적어도 하나의 정수 해를 가지니 인수 정리에 의해
Ax^3 + Bx^2 + Cx + D = (x - k)(Ax ^ 2 + px + q) 형태이다. (k는 정수)

전개한 후 계수 비교법을 이용하면 B = p-kA, C = q-kp 를 얻는다.
즉 p = kA + B, q = kp + C 임을 이용한다.

결과적으로 inside = p^2 - 4Aq >= 0일때

x1 = k
x2 = (-p + sqrt(inside)) / (2 * A)
x3 = (-p - sqrt(inside)) / (2 * A)

를 얻는다.

set에 넣으면 중복이 없어지니 OK

 */


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	LD A, B, C, D, p, q;
	LD x1 = 0, x2 = 0, x3 = 0;
	LD inside;
	LL TC;
	
	set<LD> X;
	cin >> TC;
	cout.precision(9);
	cout << fixed;
	while (TC--) {
		X.clear();
		cin >> A >> B >> C >> D;
		
		for (LD k = -1E+6; k <= 1E+6; k++) {
			LD fx = A * k * k * k + B * k * k + C * k + D;
			if (fx == 0) {
				x1 = k;
				X.insert(x1);
				break;
			}
		}

		p = x1 * A + B;
		q = x1 * p + C;

		inside = p * p - 4 * A * q;

		if (inside >= 0) {
			x2 = (-p + sqrt(inside)) / (2 * A);
			x3 = (-p - sqrt(inside)) / (2 * A);
			X.insert(x2);
			X.insert(x3);
		}
		for (auto x : X) {
			cout << x << " ";
		}
		cout << "\n";
	}

	return 0;
}
