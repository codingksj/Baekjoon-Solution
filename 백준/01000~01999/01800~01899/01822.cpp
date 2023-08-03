#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<int> setA;
    set<int> setB;
    set<int> diff;    
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        setA.insert(x);
    }

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        setB.insert(x);
    }

    set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), inserter(diff, diff.begin()));

    cout << diff.size() << '\n';
    for (int x : diff) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
