#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

const int MAX = 30;
pair<int, int> ms[MAX];

int compute(stringstream &ss) {
    char c;
    int cnt = 0;
    stack<pair<int, int>> stk;
    while (ss >> c) {
        if (c == '(') continue;
        if (c == ')') {
            if (stk.size() >= 2) {
                auto b = stk.top();
                stk.pop();
                auto a = stk.top();
                stk.pop();
                if (a.second != b.first) {
                    return -1;
                } else {
                    cnt += a.first * a.second * b.second;
                    stk.push(make_pair(a.first, b.second));
                }
            }
        } else {
            stk.push(ms[c - 'A']);
        }
    }
    return cnt;
}

int main() {
    int num;
    cin >> num;
    char c;
    int row, col;
    while (num--) {
        cin >> c >> row >> col;
        ms[c - 'A'].first = row;
        ms[c - 'A'].second = col;
    }
    string buffer;
    getline(cin, buffer);
    while (getline(cin, buffer)) {
        stringstream ss(buffer);
        int cnt = compute(ss);
        if (cnt < 0) {
            cout << "error";
        } else {
            cout << cnt;
        }
        cout << '\n';
    }
    return 0;
}
