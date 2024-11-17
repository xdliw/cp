#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define int long long

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans = {1};
vector<bool> leaf;
vector<int> a;


void dfs(int u, int pred){
    
    if(leaf[u] && u != 0){
        
        for(int i = 0; i < a[u];++i){
            ans.push_back(u);
            ans.push_back(pred);
            a[u]--;
            a[pred]--;
        }
        leaf[pred] = 1;

        return;
    }

    //!leaf

    for(int i = 0; i < adj[u].size(); ++i){
				if(visited[i]) continue;
				visited[i] = 1;
        a[u]--;
        ans.push_back(u);
        dfs(adj[u][i], u);
    }

}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    
    adj.resize(n);
    leaf.resize(n);
		visited.resize(n);
		a.resize(n);

		for(auto& i : a) cin >> i;


    map<int,int> c;
    for(int i = 0; i < n - 1;++i){
        int u,v; cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);

        c[u]++;
        c[v]++;
    }

    for(auto& i : c){
        if(i.second == 1){
            leaf[i.first] = 1;
        }
    }

		visited[0] = 1;
    dfs(adj[0][0], -1);

		if(ans.back() != 1 || a[0] != 0){
			cout << 0;
			return 0;
		}

		for(auto& i : ans){
			cout << i << ' ';
		}





}