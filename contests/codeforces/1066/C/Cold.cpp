#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif



void solve(){

	int n, k, q; cin >> n >> k >> q;
	vector<array<int,3>> con(q);
	for(auto& [c,l,r] : con){
		cin >> c >> l >> r;
		--l; --r;
	}
	vector<int> a(n); for(auto& x : a) x = -1;

	for(int i = 0; i < n; ++i){
		
		int flags = 0;
		for(int j = 0; j < q; ++j){
			if(con[j][1] <= i && i <= con[j][2])
				flags |= con[j][0];
		}

		if(flags == 0 || flags == 3){
			a[i] = 101;
		}
		else if(flags == 1){
			a[i] = k;
		}
	}

	sort(con.begin(),con.end()); //omg omg omg omg omg ohmyghoooood the bug solver

	for(int j = 0; j < q; ++j){
		int c = con[j][0];

		if(c != 2) continue;
		int l = con[j][1];
		int r = con[j][2];

		set<int> mex;
		for(int i = 0; i <= k; ++i){
			mex.insert(i);
		}

		for(int i = l; i <= r; ++i){
			mex.erase(a[i]);
		}
		for(int i = l; i <= r && *mex.begin() < k; ++i){
			if(a[i] == -1){
				a[i] = *mex.begin();
				mex.erase(mex.begin());
			}
		}
	}

	for(int i = 0; i < n; ++i){
		if(a[i] == -1) cout << "101 ";
		else cout << a[i] << ' ';
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