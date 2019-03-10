#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int cnt = s.end() - lower_bound(s.begin(), s.end(), s.back());
    while (cnt--) cout << s.back();
    cout << '\n';
    return 0;
}
