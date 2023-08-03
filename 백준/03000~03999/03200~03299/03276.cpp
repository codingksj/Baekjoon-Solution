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

typedef struct _pebbles {
	int r;
	int c;
	int sum;
}Pebbles;

bool Cmp(const Pebbles& a, const Pebbles& b) {
	return a.sum < b.sum;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int gravel;
	int r, c;
	vector<Pebbles> ICON;
	Pebbles P;
	cin >> gravel;
	for (r = 1; r <= gravel; r++) {
		for (c = gravel; c >= 1; c--) {
			if (r * c < gravel) {
				continue;
			}
			P = { r,c,r + c };
			ICON.push_back(P);
		}
	}
	sort(ICON.begin(), ICON.end(), Cmp);
	cout << ICON[0].r << " " << ICON[0].c;
	return 0;
}