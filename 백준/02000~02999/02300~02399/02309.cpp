#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> dwarf;

    int input;
    int sum = 0;
    int delta;
    int X;
    int i, j;

    for (i = 0; i < 9; i++) {
        cin >> input;
        dwarf.push_back(input);
        sum += dwarf[i];
    }

    sort(dwarf.begin(), dwarf.end());
    delta = sum - 100;

    for (i = 0; i < dwarf.size() - 1; i++) {
        for (j = i + 1; j < dwarf.size(); j++) {
            X = dwarf[i] + dwarf[j];
            if (X == delta) {
                dwarf[i] = dwarf[j] = 0;
                i = dwarf.size();
                break;
            }
        }
    }
    for (i = 0; i < dwarf.size(); i++) {
        if (dwarf[i] != 0) {
            printf("%d\n", dwarf[i]);
        }
    }
    return 0;
}
