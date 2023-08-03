#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    deque<int> DQ;
    string AC, list, tmp;

    int N, TC;
    bool reverse, error;

    scanf("%d", &TC);

    while (TC--) {
        //초기화 및 입력
        DQ.clear();
        tmp = "";
        reverse = error = false;
        cin >> AC;
        cin >> N;
        cin >> list;
        
        //숫자 추출
        for (int i = 0; i < list.length(); i++) {
            if (isdigit(list[i])) {
                tmp += list[i];
            }
            else {
                if (!tmp.empty()) {
                    DQ.push_back(stoi(tmp));
                    tmp.clear();
                }
            }
        }

        //명령어 실행
        for (auto func : AC) {
            if (func == 'R') {
                reverse = !reverse;
            }
            else {
                if (DQ.empty()) {
                    error = true;
                    break;
                }
                if (reverse)
                    DQ.pop_back();
                else
                    DQ.pop_front();
            }
        }

        //실행 결과
        if (error) {
            cout << "error" << "\n";
        }
        else if (DQ.size() == 0) {
            cout << "[]" << "\n";
        }
        else{
            cout << "[";
            if (reverse) {
                for (auto o = DQ.rbegin(); o != DQ.rend(); o++) {
                    if (o == DQ.rend() - 1)
                        cout << *o;
                    else
                        cout << *o << ',';
                }
            }
            else {
                for (auto o = DQ.begin(); o != DQ.end(); o++) {
                    if (o == DQ.end() - 1)
                        cout << *o;
                    else
                        cout << *o << ',';
                }
            }
            cout << "]\n";
        }

    }
}