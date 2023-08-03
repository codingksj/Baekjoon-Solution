#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int TC;
    int N, M;
    int index, prior, answer;

    queue <pair<int, int>> Printer;
    priority_queue <int> Max;

    cin >> TC;

    while (TC--) {
        Printer = queue <pair<int, int>>();
        Max = priority_queue <int>();
        answer = 0;

        cin >> N >> M;

        for (index = 0; index < N; index++) {
            cin >> prior;
            Printer.push({ index, prior });
            Max.push(prior);
        }

        while (!Printer.empty()) {
            index = Printer.front().first;
            prior = Printer.front().second;
            Printer.pop();

            if (Max.top() == prior) {
                Max.pop();
                answer++;
                if (index == M) {
                    cout << answer << '\n';
                    break;
                }
            }
            else {
                Printer.push({ index, prior });
            }
        }
    }
}