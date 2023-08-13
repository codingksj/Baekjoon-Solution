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
typedef pair<LL, LL> Pll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    map<string, double> itemCostMap = {
        {"Paper", 57.99},
        {"Printer", 120.50},
        {"Planners", 31.25},
        {"Binders", 22.50},
        {"Calendar", 10.95},
        {"Notebooks", 11.20},
        {"Ink", 66.95}
    };
    string item;
    double totalPrice = 0;

    while (true) {
        cin >> item;
        if (item == "EOI") {
            break;
        }
        totalPrice += itemCostMap[item];
    }
    cout << fixed;
    cout.precision(2);
    cout << "$" << totalPrice;

	return 0;
}