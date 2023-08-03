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
typedef struct _cake {
	int x;
	int y;
	int z;
}Cake;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Cake a, b, c;
	cin >> a.x >> a.y >> a.z;
	cin >> c.x >> c.y >> c.z;
	b.x = c.x - a.z;
	b.y = c.y / a.y;
	b.z = c.z - a.x;
	cout << b.x << " " << b.y << " " << b.z;
	return 0;
}