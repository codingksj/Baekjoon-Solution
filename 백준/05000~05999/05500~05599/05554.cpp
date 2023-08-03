#include<iostream>
#include<set>
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

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int x, y;
	int input;
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		cin >> input;
		sum += input;
	}
	x = sum / 60;
	y = sum % 60;
	cout << x << "\n" 
		<< y << "\n";
	return 0;
}