#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<string>
#include<numeric>
#include<cmath>
#include<cctype>
#include<iomanip>

using namespace std;

typedef long long LL;

typedef struct _size {
	LL width;
	LL length;
	LL area;
}Size;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Size T, E;
	string teamT = "TelecomParisTech", teamE = "Eurecom";
	int TC;
	cin >> TC;
	while (TC--) {
		cin >> T.length >> T.width >> E.length >> E.width;
		T.area = T.length * T.width;
		E.area = E.length * E.width;
		if (T.area > E.area) {
			cout << teamT << "\n";
		}
		else if (T.area < E.area) {
			cout << teamE << "\n";
		}
		else {
			cout << "Tie" << "\n";
		}
	}
	return 0;
}