#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void print(const std::string &s, char pad, unsigned len) {
    std::cout << s;
    while (len--) {
        std::cout << pad;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n;
    while (std::cin >> n) {
        size_t max_len = 0;
        std::vector<std::string> words;
        // Read and preprocess input data
        while (n--) {
            std::string tmp;
            std::cin >> tmp;
            max_len = std::max(max_len, tmp.size());
            words.push_back(tmp);
        }
        std::sort(words.begin(), words.end());
        // Calculate layout
        auto num_cols = 62 / (max_len + 2),
             num_rows = (words.size() + num_cols - 1) / num_cols;
        // Output
        print("", '-', 60);
        std::cout << '\n';
        for (size_t i = 0; i < num_rows; i++) {
            for (size_t j = 0; j < num_cols; ++j) {
                auto index = i + num_rows * j;
                if (index >= words.size()) {
                    break;
                }
                auto len_padding = max_len - words[index].size();
                if (j != num_cols - 1) {
                    len_padding += 2;
                }
                print(words[index], ' ', len_padding);
            }
            std::cout << '\n';
        }
    }
    return 0;
}
