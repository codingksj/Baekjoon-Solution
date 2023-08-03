#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;
int main() {
    map<string, int> pokemon;
    string number[100000 + 2];
    string name;
    char tmp[25];
    int N, M; 
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        scanf("%s", tmp);
        name = string(tmp);
        pokemon.insert({name, i});
        number[i] = name;
    }
    for (int i = 1; i <= M; i++) {
        char command[21]; 
        scanf("%s", command);
        if ('0' <= command[0] && command[0] <= '9') {
            int index = atoi(command);
            cout << number[index] << "\n";
        }
        else {
            printf("%d\n", pokemon[string(command)]);
        }
    }
    return 0;
}
