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
	map<int,int> m;
	vector<int> a(2*n); for(auto& x : a){
		cin >> x;
		++m[x];
	}

	if(dbg(1)){
		cout << m.size() << '\n';
		for(auto& [x,c] : m){
			cout << x << ' ' << c << '\n';
		}
	}

	int ans = 0;
	int evens = 0;
	int oddc = 0;
	for(auto& [x,c] : m){
		ans += (c & 1 ? 1 : 2);
		if(!(c & 1)) evens++;
		else oddc += c;
	}

	if(!oddc && ((evens & 1) ^ (n & 1)))
		ans -= 2;
	
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