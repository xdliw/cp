#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

#define int long long

bool construct(vector<int>& a, vector<int>& b, int c, int k){
	for(int i = 0; i < c; ++i){
		if((a[i] + 1) * (b[c - i - 1] + 1) - 1 > k) return false;
	}
	return true;
}

void solve(){

	int n, k; cin >> n >> k;
	vector<int> q(n),r(n);
	for(auto& x : q) cin >> x; 
	for(auto& x : r) cin >> x; 
	sort(q.begin(),q.end());
	sort(r.begin(),r.end());

	int L = 0, R = n;
	while(L != R){
		int c = (L + R + 1) >> 1;
		if(construct(q,r,c,k)) L = c;
		else R = c - 1;
	}

	cout << L << '\n';

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}