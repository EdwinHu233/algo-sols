#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string buffer;
    std::vector<std::string> all_words, result;
    std::unordered_set<std::string> hash_table;
    while (std::cin >> buffer) {
        all_words.push_back(buffer);
        hash_table.insert(buffer);
    }
    for (const auto& s : all_words) {
        for (auto it = s.cbegin(); it != s.cend(); ++it) {
            std::string a(s.cbegin(), it), b(it, s.cend());
            if (hash_table.count(a) && hash_table.count(b)) {
                result.push_back(s);
                break;
            }
        }
    }
    std::sort(result.begin(), result.end());
    for (const auto& s : result) {
        std::cout << s << '\n';
    }
    return 0;
}
