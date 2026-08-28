#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

void solve(){

	const int n = 10;
	vector<int> a(n);
	for(auto& x : a) cin >> x;

	int ans = a[0];
	for(int sub = 0; sub < (1 << 10); ++sub){
		int sum = 0;
		for(int i = 0; i < n; ++i){
			if(sub & (1 << i)) sum += a[i];
		}
		int ds = abs(sum - 100);
		int da = abs(ans - 100);

		if(ds < da) ans = sum;
		else if(ds == da) ans = max(ans,sum);
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