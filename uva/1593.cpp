#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, size_t> id_cache;
std::vector<std::string> str_cache;

using Vec = std::vector<size_t>;
using File = std::vector<Vec>;

size_t get_id(const std::string &s) {
    if (!id_cache.count(s)) {
        str_cache.push_back(s);
        id_cache[s] = str_cache.size() - 1;
    }
    return id_cache[s];
}

bool readline(Vec &result) {
    std::string buffer;
    if (!std::getline(std::cin, buffer)) return false;
    std::stringstream ss(buffer);
    while (ss >> buffer) {
        result.push_back(get_id(buffer));
    }
    return true;
}

Vec max_len_of_cols(const File &file) {
    Vec result;
    for (size_t i = 0;; ++i) {
        size_t max_len = 0;
        for (const auto &row : file) {
            if (i < row.size()) {
                auto current_len = str_cache[row[i]].size();
                max_len = std::max(max_len, current_len);
            }
        }
        if (max_len == 0) break;
        result.push_back(max_len);
    }
    return result;
}

void print(const File &file, const Vec &max_lens) {
    for (size_t i = 0; i < file.size(); ++i) {
        for (size_t j = 0; j < file[i].size(); ++j) {
            const auto &word = str_cache[file[i][j]];
            size_t num_space;
            if (j == file[i].size() - 1) {
                num_space = 0;
            } else {
                num_space = max_lens[j] - word.size() + 1;
            }
            std::cout << word;
            for (size_t k = 0; k < num_space; ++k) {
                std::cout << ' ';
            }
        }
        if (i != file.size() - 1) {
            std::cout << '\n';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    File file;
    while (true) {
        file.emplace_back();
        if (!readline(file.back())) break;
    }
    auto max_lens = max_len_of_cols(file);
    print(file, max_lens);
    return 0;
}
