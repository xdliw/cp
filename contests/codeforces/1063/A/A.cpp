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
	vector<int> a(n); for(auto& x : a) cin >> x;
	sort(a.begin(),a.end());
	for(int i = 1; i < n - 1; i += 2){
		if(a[i] != a[i + 1]){
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}