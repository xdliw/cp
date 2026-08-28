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
	vector<int> p(n - 1);
	for(auto& x : p) cin >> x;
	int m; cin >> m;
	vector<int> a(m);
	for(auto& x : a) cin >> x;
	
	sort(a.begin(),a.end());

	cout << m - 1 << ' ';
	for(int i = 1; i < m; ++i){
		cout << a[i] << ' ';
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