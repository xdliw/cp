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
	int x;
	map<int,int> c;
	for(int i = 0; i < n; ++i){
		cin >> x;
		c[x]++;
	}

	int ans = 0;
	for(auto& [x,c] : c){
		if(c >= x) ans += c - x;
		else ans += c;
	}

	cout << ans << '\n';

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}