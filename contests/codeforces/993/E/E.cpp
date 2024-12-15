#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		ll k,l1,r1,l2,r2;
		cin >> k >> l1 >> r1 >> l2 >> r2;

		vector<int> z;
		ll zz = 1;
		while(zz <= 1e9){
			z.push_back(zz);
			zz *= k;
		}

		int ans = 0, l, r;
		for(auto z : z){
			ll p = (l2 + z - 1) / z; //ceil on integers :Z (or only on naturals?)
			ll q = r2 / z;
			l = max(p,l1);
			r = min(q,r1);
			ans += max(r - l + 1, 0);
		}

		cout << ans << '\n';
	
	}

	return 0;
}