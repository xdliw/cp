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

	int n,q; cin >> n >> q;
	vector<int> a(n + 1); a[0] = 0; //1-ind
	for(int i = 1; i <= n;++i)
		cin >> a[i];

	vector<int> diff(n + 1); diff[0] = 0;
	while(q--){
		int l,r; cin >> l >> r;

		diff[l] += 1;
		diff[r + 1] -= 1;
	}

	for(int i = 1; i <= n; ++i){
		diff[i] += diff[i - 1];
	}

	sort(diff.begin(),diff.end());
	sort(a.begin(),a.end());

	int ans = 0;
	for(int i = 1; i <= n; ++i){
		ans += a[i] * diff[i];
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