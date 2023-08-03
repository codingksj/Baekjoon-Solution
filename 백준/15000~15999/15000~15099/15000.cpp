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

void ConvertToCapital(char str[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		str[i] = toupper(str[i]);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	const int MAX = 1000000 + 1;
	char line[MAX];
	cin >> line;
	ConvertToCapital(line);
	cout << line;
	return 0;
}