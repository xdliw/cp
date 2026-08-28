#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


void solve(){

	int k; cin >> k;
	map<int,int> m;
	for(int i = 0; i < k; ++i){
		int x; cin >> x;
		++m[x];
	}

	for(auto [k,v] : m){
		if(k >= 3 || (k == 2 && v >= 2)){
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}