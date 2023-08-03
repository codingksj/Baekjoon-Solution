#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string S;
	int N, M;
	int ans = 0;
	cin >> N;
	cin >> M;
	cin >> S;
	for (int i = 0; i < M; i++) {
		int IOI = 0;
		if (S[i] == 'O') {
			continue;
		}
		while (S[i + 1] == 'O' && S[i + 2] == 'I') {
			IOI++;
			if (IOI == N) {
				ans++;
				IOI--;
			}
			i += 2;
		}
	}
	cout << ans << '\n';
	return 0;
}