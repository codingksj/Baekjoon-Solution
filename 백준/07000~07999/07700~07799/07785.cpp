#include <iostream>
#include <stdio.h>
#include <set>
#include <string>
using namespace std;

int N;
int pos;
char name[10], command[10];

string user, cmd;
set<string, greater<string>> S;

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s %s", name, command);
        user = string(name);
        cmd = string(command);
        if (cmd == "enter")
            S.insert(user);
        else if (cmd == "leave")
            S.erase(user);
    }
    for (const auto& element : S) {
        cout << element << "\n";
    }

    
    return 0;
}