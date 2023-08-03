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

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<LL> house;
	LL N, C;
	LL input;
	LL start, mid, end;
	LL left_house;
	LL max_distance, distance, router;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> input;
		house.push_back(input);
	}
	sort(house.begin(), house.end());
	start = 1;
	end = house.back() - house.front();
	if (C == 2) {
		max_distance = end;
	}
	else {
		max_distance = 1;
		while (start <= end) {
			router = 1;
			mid = (start + end) / 2;
			left_house = house[0];
			for (int i = 1; i < N; i++) {
				distance = house[i] - left_house;
				if (distance >= mid) {
					router++;
					left_house = house[i];
				}
			}
			if (router >= C) {
				max_distance = max(max_distance, mid);
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
	}
	cout << max_distance;
	return 0;
}