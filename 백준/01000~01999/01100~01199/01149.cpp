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
#include<cstring>
#include<iomanip>

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

int house[1001][3];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    int N;
    int R, G, B;
    house[0][0] = house[0][1] = house[0][2] = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> R >> G >> B;
        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + R;
        house[i][1] = min(house[i - 1][0], house[i - 1][2]) + G;
        house[i][2] = min(house[i - 1][1], house[i - 1][0]) + B;
    }
    cout << min(house[N][2], min(house[N][0], house[N][1]));
	return 0;
}