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

	if(a[0] == -1 && a[n - 1] == -1){
		a[0] = 0;
		a[n - 1] = 0;
	}
	else if(a[0] == -1){
		a[0] = a[n - 1];
	}
	else if(a[n - 1] == -1){
		a[n - 1] = a[0];
	}
	
	int sum = abs(a[n - 1] - a[0]);
	cout << sum << '\n';
	for(auto& x : a){
		if(x == -1) cout << "0 ";
		else cout << x << ' ';
	}

	cout << '\n';


}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}