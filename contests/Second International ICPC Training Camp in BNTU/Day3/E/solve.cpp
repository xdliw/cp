#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k; cin >> n >> k;
    vector<set<int>> colors(n);
    vector<int> c(n);
    vector<int> ans(n);
    for(int i=0;i<n;i++) {
        cin >> c[i];
        if(c[i]) colors[i].insert(c[i]);
    }
    vector<int> p(n);
    for(int i=1;i<n;i++) cin >> p[i], --p[i]; //0-ind

    for(int i = n-1; i >= 0; i--) {
        ans[i] = colors[i].size();

				if(colors[p[i]].size() < colors[i].size()) swap(colors[p[i]], colors[i]);
			
				colors[p[i]].insert(colors[i].begin(), colors[i].end());
				
				colors[i].clear();
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}
