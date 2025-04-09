#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <cassert>

void println(std::ostream& out, const std::pair<bool, std::string>& p, int d) {
    for (int i = 0; i < d; i++) {
        out << "  ";
    }
    if (p.first) {
        out << "let " << p.second << " = new();" << std::endl;
    } else {
        out << "drop(" << p.second << ");" << std::endl;
    }
}

void println(std::ostream& out, const std::string& s, int d) {
    for (int i = 0; i < d; i++) {
        out << "  ";
    }
    out << s << std::endl;
}

int main() {
#ifdef LOCAL_TESTING
    assert(freopen("input.txt", "rt", stdin));
#endif
    int n;
    std::cin >> n;
    std::vector<std::pair<bool, std::string>> a(n);
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::string line;
        std::getline(std::cin, line);
        if (line.size() > 5 && line.substr(0, 5) == "drop(") {
            auto end = line.find(");");
            assert(end != std::string::npos);
            a[i] = { false, line.substr(5, end - 5) };
        } else if (line.size() > 4 && line.substr(0, 4) == "let ") {
            auto end = line.find(" =");
            assert(end != std::string::npos);
            a[i] = { true, line.substr(4, end - 4) };
        } else {
            assert(false);
        }
    }
    std::vector<int> prev(n);
    {
        std::map<std::string, int> pos;
        for (int i = 0; i < n; i++) {
            auto it = pos.find(a[i].second);
            if (it != pos.end()) {
                assert(it->second >= 0 && it->second < n);
                assert(!a[i].first);
                prev[i] = it->second;
            } else {
                assert(a[i].first);
                prev[i] = -1;
            }
            pos[a[i].second] = i;
        }
    }
    std::vector<int> next(n);
    {
        std::map<std::string, int> pos;
        for (int i = n - 1; i >= 0; i--) {
            auto it = pos.find(a[i].second);
            if (it != pos.end()) {
                assert(it->second >= 0 && it->second < n);
                assert(a[i].first);
                next[i] = it->second;
            } else {
                assert(!a[i].first);
                next[i] = i;
            }
            pos[a[i].second] = i;
        }
    }
    std::vector<std::vector<std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>>> f(
        2,
        std::vector<std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>>(
            n,
            std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>(n, { {0, 0}, {-1, 0} })
        )
    );
    std::function<std::pair<std::pair<int, int>, std::pair<int, int>>(int l, int r, bool w)> rec;
    rec = [&](int l, int r, bool w) -> std::pair<std::pair<int, int>, std::pair<int, int>> {
        if (l > r) {
            assert(l == r + 1);
            return { {0, 0}, {0, 0} };
        }
        assert(l >= 0 && l < n);
        assert(r >= 0 && r < n);
        auto& ans = f[w][l][r];
        if (ans.second.first >= 0) {
            return ans;
        }
        if (l == r) {
            ans = { {a[l].first ? 0 : 1, 0}, {0, 0} };
            return ans;
        }
        assert(l < r);
        ans = rec(l, r - 1, false);
        ans.first.first += a[r].first ? 0 : 1;
        ans.second = { n, 0 };
        if (next[r] > r || a[r].first) {
            return ans;
        }
        for (int i = r - 1; i >= l; i--) {
            if (next[i] > r) {
                break;
            }
            if (prev[r] < i) {
                continue;
            }
            auto lhs = rec(l, i - 1, false);
            int nr = r - 1;
            while (nr > i && !a[nr].first && prev[nr] >= i && prev[nr + 1] + 1 == prev[nr]) {
                nr--;
            }
            auto rhs = rec(i, nr, true);
            lhs.first.first += rhs.first.first;
            lhs.first.second += rhs.first.second + !w;
            lhs.second = { i, nr };
            ans = std::min(ans, lhs);
        }
        return ans;
    };
    assert(rec(0, n - 1, true).second.second >= 0);
    std::function<void(int l, int r, bool w, int d)> rec2;
    rec2 = [&](int l, int r, bool w, int d) {
        assert(l >= 0 && l < n);
        assert(r >= 0 && r < n);
        if (l == r) {
            println(std::cout, a[r], d);
            return;
        }
        const auto& ans = f[w][l][r];
        assert(ans.second.first >= 0);
        if (ans.second.first == n) {
            if (l < r) {
                rec2(l, r - 1, false, d);
            }
            println(std::cout, a[r], d);
        } else {
            if (l <= ans.second.first - 1) {
                rec2(l, ans.second.first - 1, false, d);
            }
            if (w) {
                rec2(ans.second.first, ans.second.second, true, d);
            } else {
                println(std::cout, "{", d);
                if (ans.second.first <= ans.second.second) {
                    rec2(ans.second.first, ans.second.second, true, d + 1);
                }
                println(std::cout, "}", d);
            }
        }
    };
    rec2(0, n - 1, true, 0);
    return 0;
}

