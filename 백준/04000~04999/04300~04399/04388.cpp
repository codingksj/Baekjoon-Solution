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

int CountCarry(LL num1, LL num2) {
    int carryCount = 0;
    int carry = 0; 

    while (num1 || num2) {
        int digit1 = num1 % 10;
        int digit2 = num2 % 10;

        int sum = digit1 + digit2 + carry;
        if (sum >= 10) {
            carryCount++;
            carry = 1;
        }
        else {
            carry = 0;
        }
        num1 /= 10;
        num2 /= 10;
    }

    return carryCount;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	LL a, b;
    int carryCount;

    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        carryCount = CountCarry(a, b);
        cout << carryCount << "\n";;
    }
	return 0;
}