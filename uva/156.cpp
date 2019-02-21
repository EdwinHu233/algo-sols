#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

string normalize(string s) {
    for (auto &c : s) {
        if (isalpha(c)) {
            c = tolower(c);
        }
    }
    sort(s.begin(), s.end());
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> words;
    map<string, int> cnt;

    string s, s_norm;
    while (cin >> s && s != "#") {
        words.push_back(s);
        s_norm = normalize(s);
        if (cnt.count(s_norm) == 1) {
            ++cnt[s_norm];
        } else {
            cnt[s_norm] = 1;
        }
    }

    vector<string> ans;
    for (const auto &s : words) {
        if (cnt[normalize(s)] == 1) {
            ans.push_back(s);
        }
    }
    sort(ans.begin(), ans.end());
    for (const auto &s : ans) {
        cout << s << "\n";
    }
    return 0;
}
