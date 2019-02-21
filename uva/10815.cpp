#include <iostream>
#include <set>
#include <sstream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::set<std::string> dict;
    std::string blank_seperated;
    while (std::cin >> blank_seperated) {
        // Convert upper case letters to lower case (others to space)
        for (auto &c : blank_seperated) {
            if (std::isalpha(c)) {
                c = std::tolower(c);
            } else {
                c = ' ';
            }
        }
        // Further split words
        std::stringstream buffer(blank_seperated);
        std::string tmp;
        while (buffer >> tmp) {
            dict.insert(tmp);
        }
    }
    for (auto &s : dict) {
        std::cout << s << "\n";
    }
    return 0;
}
