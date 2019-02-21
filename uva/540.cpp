#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
   private:
    using TotalQueue = std::queue<int>;
    using TeamQueue = std::queue<int>;

    std::unordered_map<int, int> team_id;
    TotalQueue total;
    std::vector<TeamQueue> team;

   public:
    Solution(int team_num) : team(team_num, TeamQueue()) {
        for (int i = 0; i < team_num; ++i) {
            int member_num, member_id;
            std::cin >> member_num;
            while (member_num--) {
                std::cin >> member_id;
                team_id[member_id] = i;
            }
        }
    }

    void enque(int x) {
        int tid = team_id[x];
        if (team[tid].empty()) {
            total.push(tid);
        }
        team[tid].push(x);
    }

    int deque() {
        auto &t = team[total.front()];
        int x = t.front();
        t.pop();
        if (t.empty()) {
            total.pop();
        }
        return x;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int case_cnt = 0;
    int team_num;
    std::string op;
    while (std::cin >> team_num && team_num) {
        std::cout << "Scenario #" << (++case_cnt) << "\n";
        Solution solution(team_num);
        while (std::cin >> op && op[0] != 'S') {
            if (op[0] == 'E') {
                int id;
                std::cin >> id;
                solution.enque(id);
            } else {
                std::cout << solution.deque() << "\n";
            }
        }
        std::cout << "\n";
    }
    return 0;
}
