#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int len;
        cin >> len;
        pq.push(len);
    }
    long long cost = 0;
    while (pq.size() >= 2) {
        int l1 = pq.top();
        pq.pop();
        int l2 = pq.top();
        pq.pop();
        cost += l1 + l2;
        pq.push(l1 + l2);
    }
    cout << cost << '\n';
    return 0;
}
