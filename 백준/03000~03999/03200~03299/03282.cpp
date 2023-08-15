#include<iostream>
#include<sstream>
#include<bitset>
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
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> Pii;
typedef pair<LL, LL> PLL;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int rooms[101] = { 0, };
    int N, G;
    int roomIndex = 0;
    int guest;
    bool check = false;

    cin >> N >> G;

    while (G--) {
        cin >> guest;
        while (guest > 0) {
            if (check) {
                if (rooms[roomIndex] == 2) {
                    roomIndex++;
                }
                else {
                    rooms[roomIndex]++;
                    roomIndex++;
                    guest--;
                }
            }
            else {
                if (guest == 1) {
                    rooms[roomIndex] = 1;
                    roomIndex++;
                    guest--;
                }
                else {
                    rooms[roomIndex] = 2;
                    roomIndex++;
                    guest -= 2;
                }

                if (roomIndex == N) {
                    check = true;
                    roomIndex = 0;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << rooms[i] << "\n";
    }


    return 0;
}