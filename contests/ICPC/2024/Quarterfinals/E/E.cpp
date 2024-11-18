#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long

int n;
vector<vector<int>> adj;
vector<int> a;
vector<bool> children_processed;
vector<int> ans;


void dfs(int u, int parent){
    // dbg(u, parent);

    ans.push_back(u + 1);
    a[u]--;

    if(children_processed[u]) return;

    for(auto v : adj[u]){
        if(v == parent) continue;
        while(a[v] > 0){
            dfs(v,u);
            ans.push_back(u + 1);
            a[u]--;
        }
    }

    children_processed[u] = 1;

}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    
    adj.resize(n);
    a.resize(n);
    children_processed.resize(n);

    for(auto& i : a) cin >> i;
    a[0]++;

    for(int i = 0; i < n - 1; ++i){
        int u,v; cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    for(auto i : a){
        if(i != 0){
            cout << 0;
            return 0;
        }
    }

    for(auto& i : ans){
        cout << i << ' ';
    }

}