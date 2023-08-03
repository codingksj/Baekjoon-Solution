#include <iostream>
using namespace std;

void Star(int row, int cols, int size) {
    if ((row / size) % 3 == 1 && (cols / size) % 3 == 1) { 
        cout << " "; 
    }
    else {
        if (size / 3 == 0) { 
            cout << "*"; 
        }
        else {
            Star(row, cols, size / 3);
        }
    }
}

int main() {
    int N;
    int r, c;
    cin >> N;

    for (r = 0; r < N; r++) {
        for (c = 0; c < N; c++) {
            Star(r, c, N);
        }
        cout << "\n";
    }
}