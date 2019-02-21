#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

const size_t MAX_ROW = 10000 + 3, MAX_COL = 10 + 3;
size_t table[MAX_ROW][MAX_COL];

using Pair = std::pair<size_t, size_t>;
namespace std {
template <>
struct hash<Pair> {
    size_t operator()(const Pair &p) const noexcept {
        return (p.first * 1234567 + p.second);
    }
};
}  // namespace std
using Dict = std::unordered_map<Pair, size_t>;

std::unordered_map<std::string, size_t> id_cache;
std::vector<std::string> str_cache;

size_t get_id(const std::string &s) {
    if (!id_cache.count(s)) {
        str_cache.push_back(s);
        id_cache[s] = str_cache.size() - 1;
    }
    return id_cache[s];
}

void readline(size_t row) {
    std::string buffer;
    std::getline(std::cin, buffer);
    // std::cout << buffer << '\n';
    std::stringstream line(buffer);
    size_t i = 0;
    while (std::getline(line, buffer, ',')) {
        table[row][i++] = get_id(buffer);
    }
}

void solve(size_t num_row, size_t num_col) {
    for (size_t c1 = 0; c1 < num_col; ++c1) {
        for (size_t c2 = c1 + 1; c2 < num_col; ++c2) {
            Dict dict;
            for (size_t r = 0; r < num_row; ++r) {
                auto current = std::make_pair(table[r][c1], table[r][c2]);
                if (dict.count(current)) {
                    std::cout << "NO\n";
                    std::cout << dict[current] + 1 << " " << r + 1 << "\n";
                    std::cout << c1 + 1 << " " << c2 + 1 << "\n";
                    return;
                } else {
                    dict[current] = r;
                }
            }
        }
    }
    std::cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t num_row, num_col;
    while (std::cin >> num_row >> num_col) {
        {  // Remove trailing newline
            std::string foo;
            std::getline(std::cin, foo);
        }
        for (size_t i = 0; i < num_row; ++i) {
            readline(i);
        }
        solve(num_row, num_col);
    }
    return 0;
}
