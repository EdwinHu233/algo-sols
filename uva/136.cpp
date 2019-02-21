#include <cstdint>
#include <iostream>
#include <queue>
#include <set>

using u64 = uint64_t;
const u64 CO[] = {2, 3, 5};

int main() {
    std::priority_queue<u64, std::vector<int>, std::greater<u64>> pq;
    pq.push(1);
    std::set<u64> s;
    s.insert(1);
    for (int i = 1; i < 1500; ++i) {
        auto x = pq.top();
        pq.pop();
        for (int j = 0; j < 3; ++j) {
            auto y = x * CO[j];
            if (!s.count(y)) {
                s.insert(y);
                pq.push(y);
            }
        }
    }
    std::cout << "The 1500'th ugly number is " << pq.top() << ".\n";
    return 0;
}
