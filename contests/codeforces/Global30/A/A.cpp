#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& i : v) cin >> i;
	int x; cin >> x;
	sort(v.begin(),v.end());

	if(v[0] <= x && x <= v[n-1]) cout << "YES\n";
	else cout << "NO\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}