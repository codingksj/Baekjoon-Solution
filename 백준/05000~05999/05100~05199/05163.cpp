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

#define PI 3.1415926535897932384

double GetVolume(double r) {
	double V = (4.0 / 3.0) * PI * r * r * r;
	return V;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC, N;
	double weight, r;
	double V, totalV;
	string answer;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		answer = "No";
		totalV = 0;
		cin >> N >> weight;
		while (N--) {
			cin >> r;
			totalV += GetVolume(r);
		}
		if (totalV / 1000 > weight) {
			answer = "Yes";
		}
		cout << "Data Set " << i << ":" << "\n";
		cout << answer << "\n" << "\n";
	}
	return 0;
}