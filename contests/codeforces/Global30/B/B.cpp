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
	vector<int> a(n); for(auto& i : a) cin >> i;

	for(int i = 0; i < n - 1; ++i){
		for(int j = i + 1; j < n; ++j){
			if(a[j] % a[i] % 2 == 0){
				cout << a[i] << ' ' << a[j] << '\n';
				return;
			}
		}
	}

	cout << "-1\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}