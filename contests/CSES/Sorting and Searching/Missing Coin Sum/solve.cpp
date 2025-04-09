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

	int n; cin >> n;
	vector<int> a(n); for(auto& i : a) cin >> i;
	sort(a.begin(), a.end());
	ll ans = 0;
	for(int i = 0; i < a.size() && a[i] - ans <= 1;i++){
		ans += a[i];
	}

	cout << ans + 1;

	return 0;
}