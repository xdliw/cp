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
	vector<int> a(n);
	vector<int> w1(n),w2(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		w1[i] = (a[i] == 1 ? 1 : -1);
		w2[i] = (a[i] == 3 ? -1 : 1);
	}

	vector<int> pref1(n), pref2(n);
	for(int i = 0; i < n; ++i){
		if(i == 0){
			pref1[0] = w1[0];
			pref2[0] = w2[0];
			continue;
		}

		pref1[i] = w1[i] + pref1[i - 1]; 
		pref2[i] = w2[i] + pref2[i - 1]; 
	}

	int mn = 1e9 + 8;
	for(int i = 1; i < n - 1; ++i){
		int a = i - 1;
		int b = i;
		if(pref1[a] >= 0) mn = min(mn, pref2[a]);
		if(pref2[b] >= mn){
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}