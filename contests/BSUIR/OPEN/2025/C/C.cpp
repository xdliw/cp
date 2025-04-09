#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using Segment = std::pair<int /* color */, int /* length */>;

bool isBalanced(int m, const std::vector<Segment>& a, const std::vector<int>& ans) {
    int sum = 0;
    std::vector<int> b(m);
    for (int i = 0, j = 0, d = 1; i < (int)a.size(); i++) {
        assert(a[i].first >= 0 && a[i].first < m);
        while (j < (int)ans.size() && ans[j] < sum) {
            d = -d;
            j++;
        }
        int prev = sum;
        sum += a[i].second;
        while (j < (int)ans.size() && ans[j] < sum) {
            b[a[i].first] += d * (ans[j] - prev);
            prev = ans[j];
            d = -d;
            j++;
        }
        b[a[i].first] += d * (sum - prev);
    }
    for (int i = 0; i < m; i++) {
        if (b[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
#ifdef LOCAL_TESTING
    assert(freopen("input.txt", "rt", stdin));
#endif
    int n, m;
    std::cin >> n >> m;
    std::vector<Segment> a(n);
    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> s[i] >> a[i].second;
        a[i].first--;
        a[i].second -= s[i] - 1;
    }
    std::vector<int> sum(m);
    for (int i = 0; i < (int)a.size(); i++) {
        assert(a[i].first >= 0 && a[i].first < m);
        sum[a[i].first] += a[i].second;
    }
    for (int i = 0; i < m; i++) {
        if (sum[i] % 2 != 0) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::vector<int> pos(m, -1);
    std::vector<int> dir(m);
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (2 * a[i].second >= sum[a[i].first] && pos[a[i].first] == -1) {
            t = 1 - t;
            pos[a[i].first] = i;
        }
        dir[a[i].first] += t;
    }
    std::vector<int> ans;
    for (int i = 0, len = 0; i < n; i++) {
        if (pos[a[i].first] == i) {
            if (dir[a[i].first] % 2 == 0) {
                ans.push_back(len + sum[a[i].first] / 2);
            } else {
                ans.push_back(len + a[i].second - sum[a[i].first] / 2);
            }
        }
        len += a[i].second;
    }
    std::sort(ans.begin(), ans.end());
    assert(isBalanced(m, a, ans));
    for (int i = 0, it = 0, len = 0, gap = 0; i < (int)ans.size(); i++) {
        while (it < (int)a.size() && len <= ans[i]) {
            len += a[it].second;
            gap += s[it] - (it > 0 ? s[it - 1] + a[it - 1].second : 0);
            it++;
        }
        ans[i] += gap;
    }
    {
        int it = 0;
        for (int i = 0; i < (int)ans.size(); i++) {
            if (i + 1 < (int)ans.size() && ans[i] == ans[i + 1]) {
                i++;
                continue;
            }
            ans[it] = ans[i];
            it++;
        }
        ans.resize(it);
    }
    std::cout << "Yes" << std::endl;
    std::cout << ans.size() << std::endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        std::cout << ans[i] << ' ';
    }
    return 0;
}

