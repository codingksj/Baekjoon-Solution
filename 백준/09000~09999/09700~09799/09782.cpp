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
	vector<int> V;
	int N;
	double median;
	for (int caseN = 1;;caseN++) {
		cin >> N;
		if (N == 0) {
			break;
		}
		V.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> V[i];
		}
		median = (N % 2 == 0) ? (V[N / 2] + V[N / 2 - 1]) / 2.0 : V[(N - 1) / 2];
		cout.setf(ios::fixed); cout.precision(1);
		cout << "Case" << " " << caseN << ":" << " " << median << "\n";
	}
	return 0;
}