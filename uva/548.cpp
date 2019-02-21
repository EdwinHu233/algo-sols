#include <iostream>
#include <sstream>

// Since all nodes have different values,
// we don't need to store the value explicitly.
// Simply use the value as index in 'ns[MAX]'
const int MAX = 10000 + 5;
struct Node {
    int lval, rval;
};

Node ns[MAX];
int in_seq[MAX], post_seq[MAX];

int build(int in_base, int post_base, int size) {
    if (size <= 0) return -1;
    int root_val = post_seq[post_base + size - 1];
    auto &root = ns[root_val];
    int i = 0;
    for (; i < size; ++i) {
        if (in_seq[in_base + i] == root_val) break;
    }
    int sz1 = i, sz2 = size - i - 1;
    root.lval = build(in_base, post_base, sz1);
    root.rval = build(in_base + sz1 + 1, post_base + sz1, sz2);
    return root_val;
}

int best_sum, best_val;

void find_min(int root_val, int anc_sum) {
    if (root_val < 0 || anc_sum > best_sum) return;
    auto &root = ns[root_val];
    int current_sum = anc_sum + root_val;
    if (root.lval < 0 && root.rval < 0) {
        if (current_sum < best_sum ||
            (current_sum == best_sum && root_val < best_val)) {
            best_sum = current_sum;
            best_val = root_val;
        }
        return;
    }
    find_min(root.lval, current_sum);
    find_min(root.rval, current_sum);
}

int read_seq(bool is_in) {
    int num = 0;
    auto &seq = is_in ? in_seq : post_seq;
    std::string buffer;
    std::getline(std::cin, buffer);
    std::stringstream ss(buffer);
    while (ss >> seq[num]) ++num;
    return num;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while (read_seq(true)) {
        int size = read_seq(false);
        int root_val = build(0, 0, size);
        best_sum = best_val = (1 << 30);
        find_min(root_val, 0);
        std::cout << best_val << '\n';
    }
    return 0;
}
