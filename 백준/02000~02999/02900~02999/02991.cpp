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
	
    int atk1, rest1, atk2, rest2;
    int deliver[3];
    int ans[3] = { 0,0,0 };
    cin >> atk1 >> rest1 >> atk2 >> rest2;
    for (int i = 0; i < 3; i++)
    {
        cin >> deliver[i];
        int dog1 = deliver[i] % (atk1 + rest1);
        int dog2 = deliver[i] % (atk2 + rest2);
        (dog1 <= atk1 && dog1 != 0) && ans[i]++;
        (dog2 <= atk2 && dog2 != 0) && ans[i]++;
    }
    for (int i = 0; i < 3; i++)
        cout << ans[i] << '\n';
	return 0;
}