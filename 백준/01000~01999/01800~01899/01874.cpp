#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    stack<int> stk;
    vector<char> V;
    int N, X, top = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &X);
        while (top < X) {
            top++;
            V.push_back('+');
            stk.push(top);
        }

        if (stk.top() == X) {
            V.push_back('-');
            stk.pop();
        }
    }


    if (stk.empty()) {
        for (int i = 0; i < V.size(); i++) {
            printf("%c\n", V[i]);
        }
    }
    else {
        printf("NO\n");
    }
}