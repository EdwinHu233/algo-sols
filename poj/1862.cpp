#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>

int main() {
    int n, tmp;
    std::priority_queue<double> pq;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &tmp);
        pq.push(tmp);
    }
    while (pq.size() > 1) {
        double a = pq.top();
        pq.pop();
        double b = pq.top();
        pq.pop();
        pq.push(2 * std::sqrt(a * b));
    }
    printf("%.3lf\n", pq.top());
    return 0;
}

