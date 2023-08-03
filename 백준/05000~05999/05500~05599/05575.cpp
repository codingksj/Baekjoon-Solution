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

#define HOUR 3600
#define MINUTE 60

typedef struct _time {
	int hour;
	int min;
	int sec;
}Time;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Time start[3];
	Time end[3];
	LL total[3];
	LL dh, dm, ds;
	LL h, m, s;
	for (int i = 0; i < 3; i++) {
		cin >> start[i].hour >> start[i].min >> start[i].sec
			>> end[i].hour >> end[i].min >> end[i].sec;

		dh = end[i].hour - start[i].hour;
		dm = end[i].min - start[i].min;
		ds = end[i].sec - start[i].sec;
		total[i] = dh * HOUR + dm * MINUTE + ds;
	}
	for (int i = 0; i < 3; i++) {
		h = total[i] / HOUR;
		total[i] -= (h * HOUR);
		m = total[i] / MINUTE;
		total[i] -= (m * MINUTE);
		s = total[i];
		cout << h << " " << m << " " << s << " " << "\n";
	}
	return 0;
}