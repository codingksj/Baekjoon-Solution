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

typedef struct _exam {
	int info;
	int math;
	int sci;
	int eng;
}Exam;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Exam min, man;
	int s1, s2;
	cin >> min.info >> min.math >> min.sci >> min.eng;
	cin >> man.info >> man.math >> man.sci >> man.eng;
	s1 = min.info + min.math + min.sci + min.eng;
	s2 = man.info + man.math + man.sci + man.eng;
	cout << max(s1, s2);
	return 0;
}