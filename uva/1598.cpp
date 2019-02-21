#include <iostream>
#include <set>
#include <unordered_map>

struct Order {
    int id, price;
    mutable int size;
};

auto cmp_buy = [](const Order &a, const Order &b) {
    if (a.price == b.price) return a.id < b.id;
    return a.price > b.price;
};

auto cmp_sell = [](const Order &a, const Order &b) {
    if (a.price == b.price) return a.id < b.id;
    return a.price < b.price;
};

std::set<Order, decltype(cmp_buy)> buy_list(cmp_buy);
std::set<Order, decltype(cmp_sell)> sell_list(cmp_sell);
std::unordered_map<int, Order> order_by_id;

void print_quote() {
    std::cout << "QUOTE ";
    if (buy_list.empty()) {
        std::cout << "0 0";
    } else {
        int bid_price = buy_list.begin()->price, bid_size = 0;
        for (const auto &order : buy_list) {
            if (order.price != bid_price) break;
            bid_size += order.size;
        }
        std::cout << bid_size << ' ' << bid_price;
    }
    std::cout << " - ";
    if (sell_list.empty()) {
        std::cout << "0 99999\n";
    } else {
        int ask_price = sell_list.begin()->price, ask_size = 0;
        for (const auto &order : sell_list) {
            if (order.price != ask_price) break;
            ask_size += order.size;
        }
        std::cout << ask_size << ' ' << ask_price << '\n';
    }
}

void cancel(int id) {
    if (!order_by_id.count(id)) return;
    auto &order = order_by_id[id];
    buy_list.erase(order);
    sell_list.erase(order);
    order_by_id.erase(id);
}

void incoming_buy(Order &order) {
    for (auto it = sell_list.begin(); it != sell_list.end();) {
        if (order.size == 0 || order.price < it->price) break;
        int trade_size = std::min(order.size, it->size);
        order.size -= trade_size;
        it->size -= trade_size;
        std::cout << "TRADE " << trade_size << ' ' << it->price << '\n';
        if (it->size == 0) {
            order_by_id.erase(it->id);
            it = sell_list.erase(it);
        } else {
            ++it;
        }
    }
    if (order.size != 0) {
        buy_list.insert(order);
        order_by_id[order.id] = order;
    }
}

void incoming_sell(Order &order) {
    for (auto it = buy_list.begin(); it != buy_list.end();) {
        if (order.size == 0 || it->price < order.price) break;
        int trade_size = std::min(order.size, it->size);
        order.size -= trade_size;
        it->size -= trade_size;
        std::cout << "TRADE " << trade_size << ' ' << it->price << '\n';
        if (it->size == 0) {
            order_by_id.erase(it->id);
            it = buy_list.erase(it);
        } else {
            ++it;
        }
    }
    if (order.size != 0) {
        sell_list.insert(order);
        order_by_id[order.id] = order;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int num_orders, a, b;
    std::string cmd;
    bool first_test = true;
    while (std::cin >> num_orders) {
        if (first_test) {
            first_test = false;
        } else {
            std::cout << '\n';
        }
        for (int i = 1; i <= num_orders; ++i) {
            std::cin >> cmd >> a;
            if (cmd[0] == 'C') {
                cancel(a);
            } else {
                std::cin >> b;
                Order o;
                o.id = i;
                o.size = a;
                o.price = b;
                if (cmd[0] == 'B') {
                    incoming_buy(o);
                } else {
                    incoming_sell(o);
                }
            }
            print_quote();
        }
        order_by_id.clear();
        buy_list.clear();
        sell_list.clear();
    }
}
