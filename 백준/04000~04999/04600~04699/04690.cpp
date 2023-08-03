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
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	bool IsCubic;
	int a, b, c, d;
	int a3, b3, c3, d3;
	for (a = 2; a <= 100; a++) {
		for (b = 2; b <= a; b++) {
			for (c = b; c <= a; c++) {
				for (d = c; d <= a; d++) {
					a3 = a * a * a;
					b3 = b * b * b;
					c3 = c * c * c;
					d3 = d * d * d;
					IsCubic = a3 == b3 + c3 + d3;
					if (IsCubic) {
						cout << "Cube = " << a << ", Triple = (" << b << ',' << c << ',' << d << ")\n";
					}
				}
			}
		}
	}
	return 0;
}