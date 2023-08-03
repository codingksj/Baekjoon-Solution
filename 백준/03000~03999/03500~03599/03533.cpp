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

#define MAX 10

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	bool inputs[MAX] = { false, };

	for (int i = 0; i < MAX; i++){
		cin >> inputs[i];
	}

	bool result = (inputs[0] || inputs[1]);

	for (int i = 0; i < MAX; i++){
		for (int j = i + 1; j < MAX; j++){
			if (i==0 && j==1){
				continue;
			}
			result ^= (inputs[i] || inputs[j]);
		}
	}

	for (int i = 0; i < MAX; i++){
		for (int j = i + 1; j < MAX; j++){
			for (int k = j + 1; k < MAX; k++){
				result ^= (inputs[i] || inputs[j] || inputs[k]);
			}
		}
	}

	cout << result << "\n";
	return 0;
}