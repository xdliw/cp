#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


void solve(){

	int n; cin >> n;
	vector<int> p(n);
	for(auto& x : p) cin >> x;

	set<int> uncon, conr; // unconnected, connected on the right
	vector<array<int,2>> edjes;
	for(int i = 1; i <= n; ++i){
		uncon.insert(i);
	}

	uncon.erase(p[0]);
	for(int i = 0; i < n; ++i){
		//connect to the tree
		if(uncon.contains(p[i])){
			dbg(conr.size());
			if(conr.empty() || p[i] > *conr.rbegin()){
				cout << "NO\n";
				return;
			}
			//else it can be connected
			uncon.erase(p[i]);
			edjes.push_back({p[i],*conr.rbegin()});
		}

		//its not on the right anymore, so erase it if it was in conr
		conr.erase(p[i]);

		//connect as much as possible
		dbg(uncon.size());
		while(!uncon.empty() && p[i] < *uncon.rbegin()){
			int u = *uncon.rbegin();
			dbg(p[i],u);
			uncon.erase(u);
			conr.insert(u);
			edjes.push_back({p[i], u});
		}
	}

	assert(uncon.empty());
	assert(edjes.size() == n - 1);

	cout << "YES\n";
	for(auto& [u,v] : edjes){
		cout << u << ' ' << v << '\n';
	}

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}