#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

#define int long long

void solve(){

	int n,m; cin >> n >> m;
	vector<int> a(n),b(m);
	for(auto& x : a) cin >> x;
	for(auto& x : b) cin >> x;
	int sa = a.back(),sb = b.back();

	for(int i = 0; i < n - 1; ++i){
		sa += a[i] - a[i + 1] + 1;
	}
	for(int i = 0; i < m - 1; ++i){
		sb += b[i] - b[i + 1] + 1;
	}

	if(sa >= sb) cout << "1\n";
	else cout << "2\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}