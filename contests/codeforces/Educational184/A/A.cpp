#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


void solve(){

	int n,a; cin >> n >> a;
	vector<int> v(n); for(auto& x : v) cin >> x;
	
	auto lb = lower_bound(v.begin(),v.end(),a);
	auto ub = upper_bound(v.begin(),v.end(),a);

	if(lb - v.begin() > v.end() - ub){
		cout << a - 1 << '\n';
	}
	else{
		cout << a + 1 << '\n';
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